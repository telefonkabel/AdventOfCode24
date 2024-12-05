#include "CDay05.h"

#include <iostream>
#include <regex>


namespace aoc
{
    CDay05::CDay05(ESolve toSolve) :CDay(05, toSolve) {};
    CDay05::~CDay05() = default;

    int CDay05::solve(ESolve toSolve) const
    {
        int solution{};
        vecStr start{ parse2Container<vecStr>(getID()) };

        vVecInt orders{};
        vVecInt updates{};
        for (auto itr{ start.begin() }; itr != start.end(); ++itr)
        {
            if (*itr == "")
            {
                ;
            }
        }

        return solution;
    }

    std::string CDay05::calculateSilver() const
    {
        return std::to_string(solve(ESolve::SILVER));
    }

    std::string CDay05::calculateGold() const
    {
        return std::to_string(solve(ESolve::GOLD));
    }

} //end of namespace aoc