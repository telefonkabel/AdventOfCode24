#pragma once

#include "ESolve.h"

#include <string>
#include <vector>


namespace aoc
{
    enum Type { HIGH, ONE, TWO, THREE, HOUSE, FOUR, FIVE };

    static constexpr char ZERO{ '0' };
    static constexpr char TEN{ 'T' };
    static constexpr char JOKER{ 'J' };
    static constexpr char QUEEN{ 'Q' };
    static constexpr char KING{ 'K' };
    static constexpr char ACE{ 'A' };

    class CHand
    {
    public:
        CHand(const std::string& strHand, ESolve toSolve);

        Type getType() const { return _type; }
        const std::vector<int>& getHand() const { return _hand; }

        void calcType(const std::string& strHand);


        bool operator <(const CHand& hand2) const
        {
            if (_type != hand2.getType())
            {
                return _type < hand2.getType();
            }
            else
            {
                auto itr1{ _hand.begin() };
                auto itr2{ hand2.getHand().begin() };
                while (itr1 != std::prev(_hand.end())
                    && itr2 != std::prev(hand2.getHand().end())
                    && *itr1 == *itr2)
                {
                    itr1++;
                    itr2++;
                }
                return *itr1 < *itr2;
            }
        }

    private:
        std::vector<int> _hand;
        Type _type;
        ESolve _toSolve;

        int map(const char ch);
    };

} // namespace aoc

