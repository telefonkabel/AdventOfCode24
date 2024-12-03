#include "CDay03.h"

#include <iostream>
#include <regex>


namespace aoc
{
    CDay03::CDay03(ESolve toSolve) :CDay(03, toSolve) {};
    CDay03::~CDay03() = default;

    int CDay03::solve(ESolve toSolve) const
    {
        int solution{};
        vecStr start{ parse2Container<vecStr>(getID()) };

        std::regex validMulRegex(R"(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\))");

        for (const auto& str : start)
        {
            auto begin{ std::sregex_iterator(str.begin(), str.end(), validMulRegex) };
            const auto end{ std::sregex_iterator{} };

            for (auto itr{ begin }; itr != end; ++itr)
            {
                static bool isValid{ true };

                if (itr->str() == "do()")
                {
                    isValid = true;
                    continue;
                }
                if (itr->str() == "don't()")
                {
                    isValid = false;
                    continue;
                }
                if (toSolve == ESolve::GOLD && !isValid)
                {
                    continue;
                }

                int x{ std::stoi((*itr)[1].str()) };
                int y{ std::stoi((*itr)[2].str()) };
                solution += x * y;
            }
        }

        return solution;
    }

    std::string CDay03::calculateSilver() const
    {
        return std::to_string(solve(ESolve::SILVER));
    }

    std::string CDay03::calculateGold() const
    {
        return std::to_string(solve(ESolve::GOLD));
    }

} //end of namespace aoc