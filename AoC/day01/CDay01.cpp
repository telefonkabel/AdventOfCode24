#include "CDay01.h"

#include <vector>
#include <map>
#include <unordered_set>
#include <ctype.h>
#include <iostream>


namespace aoc
{
    CDay01::CDay01(ESolve toSolve) :CDay(01, toSolve) {};
    CDay01::~CDay01() = default;


    std::string CDay01::calculate(ESolve toSolve) const
    {
        vVecInt start{ parse2Container<vVecInt>(getID()) };

        int solution{};

        return std::to_string(solution);
    }

    std::string CDay01::calculateSilver() const
    {
        return calculate(ESolve::SILVER);
    }

    std::string CDay01::calculateGold() const
    {
        return calculate(ESolve::GOLD);
    }

} //end of namespace aoc