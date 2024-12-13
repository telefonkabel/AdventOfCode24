#include "CDay09.h"

#include <vector>
#include <optional>
#include <iostream>


namespace aoc
{
    CDay09::CDay09(ESolve toSolve) :CDay(9, toSolve) {};
    CDay09::~CDay09() = default;

    int8_t CDay09::c2Digit(const char c) const
    {
        if (!std::isdigit(c))
        {
            std::cerr << "Error: Input value " << c << " is no digit." << std::endl;
            return 0;
        }
        return c - '0' ;
    }

    void CDay09::fillRecipeSilver(std::vector<std::optional<int>>& recipe, std::vector<Block>& blocks, ESolve toSolve) const
    {
        auto itrFront{ blocks.begin() };
        auto itrBack{ blocks.end() - 1 };

        while (itrFront <= itrBack)
        {
            while (itrFront->_file > 0)
            {
                recipe.emplace_back(itrFront->_id);
                --itrFront->_file;
            }

            while (itrFront->_space > 0)
            {
                if (itrBack->_file <= 0)
                {
                    --itrBack;
                }
                if (itrFront >= itrBack)
                {
                    break;
                }

                recipe.emplace_back(itrBack->_id);
                --itrBack->_file;

                --itrFront->_space;
            }

            ++itrFront;
        }
    }

    void CDay09::fillRecipeGold(std::vector<std::optional<int>>& recipe, std::vector<Block>& blocks, ESolve toSolve) const
    {
        auto itrBack{ blocks.end() - 1 };

        for (auto itrBack{ blocks.end() - 1 }; itrBack != blocks.begin(); --itrBack)
        {
            for (auto itrFront{ blocks.begin() }; itrBack > itrFront; ++itrFront)
            {
                if (itrBack->_file <= itrFront->_space)
                {
                    std::prev(itrBack)->_space += (itrBack->_file + itrBack->_space);
                    itrBack->_space = itrFront->_space - itrBack->_file;
                    itrFront->_space = 0;

                    auto backCopy{ *itrBack };
                    auto frontPos{ std::distance(blocks.begin(), itrFront) };
                    auto backPos{ std::distance(blocks.begin(), itrBack) };

                    blocks.erase(itrBack);
                    blocks.insert(blocks.begin() + frontPos + 1, backCopy);

                    itrBack = blocks.begin() + backPos + 1;
                    break;
                }
            }
        }

        for (auto& block : blocks)
        {
            while (block._file-- != 0)
            {
                recipe.emplace_back(block._id);
            }
            while (block._space-- != 0)
            {
                recipe.emplace_back(std::nullopt);
            }
        }
    };

    uint64_t CDay09::solve(ESolve toSolve) const
    {
        uint64_t solution{};
        vecStr start{ parse2Container<vecStr>(getID()) };

        if (start.size() != 1)
        {
            std::cerr << "Error: file input isn't a single line" << std::endl;
            return 0;
        }

        // Parse in disk map into blocks of values 
        std::vector<Block> blocks{};
        int id{ 0 };
        for (auto itr{ start.front().begin() }; itr != start.front().end(); std::advance(itr, 2))
        {
            if (std::distance(itr, start.front().end()) < 2)
            {
                // Add the last solo element with 0 as the second value
                blocks.emplace_back(id++, c2Digit(*itr), 0);
                break;
            }

            blocks.emplace_back(
                id++,
                c2Digit(*itr),
                c2Digit(*std::next(itr))
            );
        }

        // Generate recipe
        std::vector<std::optional<int>> recipe{};
        if (toSolve == ESolve::SILVER)
        {
            fillRecipeSilver(recipe, blocks, toSolve);
        }
        else
        {
            fillRecipeGold(recipe, blocks, toSolve);
        }

        // Calculate recipe
        for (uint64_t i{}; i < recipe.size(); ++i)
        {
            solution += i * (recipe.at(i).has_value() ? recipe.at(i).value() : 0);
        }


        return solution;
    }

    std::string CDay09::calculateSilver() const
    {
        return std::to_string(solve(ESolve::SILVER));
    }

    std::string CDay09::calculateGold() const
    {
        return std::to_string(solve(ESolve::GOLD));
    }

} //end of namespace aoc