#pragma once

#include "CDay.h"

#include <ostream>


namespace aoc
{
    using position = std::pair<int, int>;
    using direction = std::pair<int, int>;

	class CDay04 : public CDay
	{
	public:
        CDay04(ESolve toSolve = ESolve::ALL);
        ~CDay04();

    private:
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
        int solve(const ESolve toSolve) const;
        bool checkForXMAS(const vecStr& array, std::string_view chars, const position& pos,
            const direction& dir, const ESolve toSolve) const;
	};

} //end of namespace aoc