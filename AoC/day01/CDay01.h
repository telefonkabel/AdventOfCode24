#pragma once

#include "CDay.h"


namespace aoc
{
	class CDay01 : public CDay
	{
	public:
        CDay01(ESolve toSolve = ESolve::ALL);
        ~CDay01();

    private:
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
	};

} //end of namespace aoc