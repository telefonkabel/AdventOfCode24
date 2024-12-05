#include "CDay05.h"

#include <deque>
#include <algorithm>


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
        bool areOrders{ true };
        for (const auto& str : start)
        {
            if (str.empty())
            {
                areOrders = false;
                continue;
            }

            vecInt input{};
            if (areOrders)
            {
                parseStr2Container(input, str, { "|" });
                orders.push_back(std::move(input));
            }
            else
            {
                parseStr2Container(input, str, { "," });
                updates.push_back(std::move(input));
            }
        }

        std::deque<bool> wereAlreadySorted{};
        for (auto& update : updates)
        {
            const auto updateCopy{ update };
            std::stable_sort(update.begin(), update.end(), [&orders](int a, int b)
                {
                    for (const auto& order : orders)
                    {
                        if (order.front() == a && order.back() == b)
                        {
                            return true;
                        }
                        else if (order.front() == b && order.back() == a)
                        {
                            return false;
                        }
                    }

                    return false;
                }
            );
            wereAlreadySorted.emplace_back(update == updateCopy);
        }

        for (size_t i{}; i < wereAlreadySorted.size(); ++i)
        {
            if (toSolve == ESolve::SILVER ? wereAlreadySorted[i] : !wereAlreadySorted[i])
            {
                solution += updates[i][updates[i].size() / 2];
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