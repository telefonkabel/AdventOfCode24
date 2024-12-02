#pragma once

#include "CDay.h"


namespace aoc
{
	class CDay02 : public CDay
	{
	public:
        CDay02(ESolve toSolve = ESolve::ALL);
        ~CDay02();

    private:
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
        int solve(const ESolve toSolve) const;
        bool check(const vecInt& vec, const ESolve toSolve, const bool failedOnce = false) const;
        bool checkWithRemove(const vecInt& vec, const ESolve toSolve) const;
	};

} //end of namespace aoc