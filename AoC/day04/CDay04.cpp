#include "CDay04.h"

#include <array>
#include <utility>


namespace aoc
{
    CDay04::CDay04(ESolve toSolve) :CDay(04, toSolve) {};
    CDay04::~CDay04() = default;

    bool CDay04::checkForXMAS(const vecStr& array, std::string_view chars, const position& pos, const direction& dir,
        const ESolve toSolve) const
    {
        const position newPos{ pos.first + dir.first, pos.second + dir.second };

        //out of bounds
        auto outOfBounds{ [&array, &chars](const position& p)->bool {
        if (chars.empty() || p.first < 0 || p.first >= array.size() || p.second < 0 || p.second >= array.front().size())
        {
            return true;
        }
        return false;
        } };

        if (outOfBounds(newPos))
        {
            return false;
        }

        if (array[newPos.first][newPos.second] == chars.front())
        {
            if (chars.front() == 'S')
            {
                if (toSolve == ESolve::SILVER)
                {
                    return true; //XMAS or X_MAS for Gold
                }

                //check for X-MAS
                auto diagonalPosition{ [&dir](const position& p)->position {
                    return {p.first - 2 * dir.first, p.second - 2 * dir.second};
                    } };

                position diagPos{ diagonalPosition(newPos) };
                if (outOfBounds(diagPos) || array[diagPos.first][diagPos.second] != 'M')
                {
                    return false;
                }

                //now easy to get the other two edges of the X-MAS
                if ((array[newPos.first][diagPos.second] == 'M' && array[diagPos.first][newPos.second] == 'S') ||
                    (array[newPos.first][diagPos.second] == 'S' && array[diagPos.first][newPos.second] == 'M'))
                {
                    return true;
                }

                return false;
            }
            else
            {
                return checkForXMAS(array, std::string_view(chars).substr(1), newPos, dir, toSolve);
            }
        }

        return false;
    }

    int CDay04::solve(ESolve toSolve) const
    {
        int solution{};
        vecStr start{ parse2Container<vecStr>(getID()) };

        size_t length{ start.front().size()};
        for (const auto& line : start)
        {
            if (line.size() != length)
            {
                std::cerr << "Invalid input, some lines are longer than others." << std::endl;
                return 0;
            }
        }
        
        constexpr std::array<direction, 8> directions{
            direction{-1, 0}, direction{1, 0}, direction{0, -1}, direction{0, 1},    // Up, Down, Left, Right
            direction{-1, -1}, direction{-1, 1}, direction{1, -1}, direction{1, 1}  // Diagonals
        };

        for (size_t y{}; y < start.size(); ++y)
        {
            for (size_t x{}; x < start.begin()->size(); ++x)
            {
                for (const direction& dir : directions)
                {
                    if (toSolve == ESolve::SILVER)
                    {
                        if (start[y][x] == 'X' && checkForXMAS(start, "MAS", { y, x }, dir, toSolve))
                        {
                            ++solution;
                        }
                    }
                    else if (start[y][x] == 'A' && dir.first != 0 && dir.second != 0)
                    {
                        if (checkForXMAS(start, "S", {y, x}, dir, toSolve))
                        {
                            ++solution;
                            break;
                        }
                    }
                }
            }
        }

        return solution;
    }

    std::string CDay04::calculateSilver() const
    {
        return std::to_string(solve(ESolve::SILVER));
    }

    std::string CDay04::calculateGold() const
    {
        return std::to_string(solve(ESolve::GOLD));
    }

} //end of namespace aoc