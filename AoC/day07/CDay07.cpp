#include "CDay07.h"

#include <vector>
#include <map>
#include <unordered_set>
#include <ctype.h>
#include <iostream>


namespace aoc
{
    CDay07::CDay07(ESolve toSolve) :CDay(07, toSolve) {};
    CDay07::~CDay07() = default;


    std::string CDay07::calculate(ESolve toSolve) const
    {
        vecStr start{ parse2Container<vecStr>(getID()) };

        int solution{};
        std::map<CHand, int> hands{};

        for (auto lineItr{ start.begin() }; lineItr != start.end(); ++lineItr)
        {
            vecStr line{ splitBy(*lineItr, { " " }) };
            auto duplicate{ hands.find(CHand{ *line.begin(), toSolve }) };
            if (duplicate != hands.end())
            {
                std::cout << "Identical entries - This should not happen!" << std::endl;
            }
            hands.emplace(CHand{ *line.begin(), toSolve }, std::stoi(line.back()));
        }

        int i{};
        for (auto entry : hands)
        {
            solution += ++i * entry.second;
        }

        return std::to_string(solution);
    }

    std::string CDay07::calculateSilver() const
    {
        return calculate(ESolve::SILVER);
    }

    std::string CDay07::calculateGold() const
    {
        return calculate(ESolve::GOLD);
    }

} //end of namespace aoc