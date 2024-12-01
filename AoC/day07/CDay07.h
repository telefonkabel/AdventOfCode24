#pragma once

#include "CDay.h"
#include "CHand.h"


namespace aoc
{
	class CDay07 : public CDay
	{
	public:
        CDay07(ESolve toSolve = ESolve::ALL);
        ~CDay07();

    private:
        std::string calculate(ESolve toSolve) const;
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
	};

} //end of namespace aoc