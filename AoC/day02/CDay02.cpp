#include "CDay02.h"

#include <vector>
#include <map>
#include <unordered_set>
#include <ctype.h>
#include <iostream>


namespace aoc
{
    CDay02::CDay02(ESolve toSolve) :CDay(02, toSolve) {};
    CDay02::~CDay02() = default;

    bool CDay02::checkWithRemove(const vecInt& vec, const ESolve toSolve) const
    {
        for (size_t removeIndex = 0; removeIndex < vec.size(); ++removeIndex)
        {
            vecInt vecCopy = vec;
            vecCopy.erase(vecCopy.begin() + removeIndex);
            if (check(vecCopy, toSolve, true))
            {
                return true;
            }
        }
        return false;
    }

    bool CDay02::check(const vecInt& vec, const ESolve toSolve, const bool failedOnce) const
    {
        if (vec.size() < 2)
        {
            std::cerr << "Error: Parsed vectors should have min size of 2" << std::endl;
            return false;
        }

        vecInt deltas{};
        for (size_t i{ 0 }; i < vec.size() - 1; ++i)
        {
            int delta{ vec[i] - vec[i + 1] };
            deltas.emplace_back(delta);
            if (std::abs(delta) < 1 || std::abs(delta) > 3)
            {
                if (toSolve != ESolve::SILVER && !failedOnce)
                {
                    return checkWithRemove(vec, toSolve);
                }
                return false;
            }
        }

        // Check monotonicity
        int tmpNegative{ deltas[0] };
        int tmpPositive{ deltas[0] };
        for (size_t i{ 1 }; i < deltas.size(); ++i)
        {
            tmpNegative &= deltas[i];
            tmpPositive |= deltas[i];
        }

        if (tmpNegative < 0 || tmpPositive >= 0)
        {
            return true;
        }
        if (toSolve != ESolve::SILVER && !failedOnce)
        {
            return checkWithRemove(vec, toSolve);
        }

        return false;
    }

    int CDay02::solve(const ESolve toSolve) const
    {
        int solution{};
        vVecInt start{ parse2Container<vVecInt>(getID()) };

        for (const auto& vec : start)
        {
            if (check(vec, toSolve))
            {
                ++solution;
            }
        }

        return solution;
    }

    std::string CDay02::calculateSilver() const
    {
        return std::to_string(solve(ESolve::SILVER));
    }

    std::string CDay02::calculateGold() const
    {
        return std::to_string(solve(ESolve::GOLD));
    }

} //end of namespace aoc