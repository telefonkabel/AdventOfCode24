#pragma once

#include "CDay.h"


namespace aoc
{
	class CDay05 : public CDay
	{
	public:
        CDay05(ESolve toSolve = ESolve::ALL);
        ~CDay05();

    private:
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
        int solve(const ESolve toSolve) const;
	};

} //end of namespace aoc