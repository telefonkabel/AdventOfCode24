#pragma once

#include "CDay.h"

#include <optional>


namespace aoc
{
    struct Block
    {
        int _id;
        int8_t _file;
        int8_t _space;

        Block(int id, int8_t file, int8_t space) :
            _id{id}, _file{file}, _space{space} {}
    };

	class CDay09 : public CDay
	{
	public:
        CDay09(ESolve toSolve = ESolve::ALL);
        ~CDay09();

    private:
        std::string calculateSilver() const override;
        std::string calculateGold() const override;
        uint64_t solve(const ESolve toSolve) const;
        int8_t c2Digit(const char c) const;
        void fillRecipeGold(std::vector<std::optional<int>>& recipe, std::vector<Block>& blocks, ESolve toSolve) const;
        void fillRecipeSilver(std::vector<std::optional<int>>& recipe, std::vector<Block>& blocks, ESolve toSolve) const;
	};

} //end of namespace aoc