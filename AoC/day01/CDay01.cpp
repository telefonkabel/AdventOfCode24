#include "CDay01.h"

#include <vector>
#include <ostream>


namespace aoc
{
    CDay01::CDay01(ESolve toSolve) :CDay(01, toSolve) {};
    CDay01::~CDay01() = default;

    static bool lessBySecondVal(const vecInt& vec1, const vecInt& vec2)
    {
        if (vec1.size() != 2 || vec2.size() != 2)
        {
            std::cerr << "Error: Parsed vectors should have size of 2" << std::endl;
            return false;
        }

        return vec1.back() < vec2.back();
    }

    std::string CDay01::calculateSilver() const
    {
        int solution{};
        vVecInt start{ parse2Container<vVecInt>(getID()) };

        std::sort(start.begin(), start.end());

        vVecInt startCopy{ start };
        std::sort(startCopy.begin(), startCopy.end(), lessBySecondVal);

        for (int i{ 0 }; i < start.size(); ++i)
        {
            solution += std::abs(start[i].front() - startCopy[i].back());
        }

        return std::to_string(solution);
    }

    std::string CDay01::calculateGold() const
    {
        int solution{};
        vVecInt start{ parse2Container<vVecInt>(getID()) };

        std::sort(start.begin(), start.end());

        vVecInt startCopy{ start };
        std::sort(startCopy.begin(), startCopy.end(), lessBySecondVal);

        for (const vecInt& vec : start)
        {
            int target{ vec.front() };
            auto itr{ std::find_if(startCopy.begin(), startCopy.end(), [target](const vecInt& vecCopy)
                {
                    return !vecCopy.empty() && vecCopy.back() == target;
                }) };

            while (itr != startCopy.end() && itr->back() == target)
            {
                solution += target;
                ++itr;
            }
        }

        return std::to_string(solution);
    }

} //end of namespace aoc