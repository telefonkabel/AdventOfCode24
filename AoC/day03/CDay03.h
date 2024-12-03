#pragma once

#include "CDay.h"


namespace aoc
{
	class CDay03 : public CDay
	{
	public:
        CDay03(ESolve toSolve = ESolve::ALL);
        ~CDay03();

    private:
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
        int solve(const ESolve toSolve) const;
	};

} //end of namespace aoc