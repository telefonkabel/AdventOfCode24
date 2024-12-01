#include "CHand.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


namespace aoc
{

    CHand::CHand(const std::string& strHand, ESolve toSolve) :
        _type{ HIGH },
        _toSolve{toSolve}
    {
        calcType(strHand);
    }

    void CHand::calcType(const std::string& strHand)
    {
        int firstFind{ 0 };
        int firstDuplicates{ 0 };
        int secondFind{ 0 };
        int secondDuplicates{ 0 };
        int countJ{ 0 };
        for (char chrFinger : strHand)
        {
            int finger{ map(chrFinger) };
            if (_toSolve == ESolve::GOLD && chrFinger == JOKER)
            {
                ++countJ;
            }
            else
            {
                if (std::find(_hand.begin(), _hand.end(), finger) != _hand.end())
                {
                    if (!firstFind || firstFind == finger)
                    {
                        firstFind = finger;
                        ++firstDuplicates;
                    }
                    else if (!secondFind || secondFind == finger)
                    {
                        secondFind = finger;
                        ++secondDuplicates;
                    }
                }
            }
            _hand.push_back(finger);
        }

        int second{ std::min(firstDuplicates, secondDuplicates) };
        int max{ std::max(firstDuplicates, secondDuplicates) };

        if (_toSolve == ESolve::GOLD)
        {
            if (countJ >= 4)
            {
                max = 4;
            }
            else
            {
                max += countJ;
            }
        }
        else if (_toSolve == ESolve::SILVER)
        {
            second = std::max(second, countJ);
            max = std::max(max, countJ);
        }
        else
        {
            std::cout << "Unknown metal - This should not happen!" << std::endl;
        }

        switch (max)
        {
        case 0:
        {
            _type = HIGH;
            break;
        }
        case 1:
        {
            if (second == 1)
            {
                _type = TWO;
            }
            else
            {
                _type = ONE;
            }
            break;
        }
        case 2:
        {
            if (second > 0)
            {
                _type = HOUSE;
            }
            else
            {
                _type = THREE;
            }
            break;
        }
        case 3:
        {
            _type = FOUR;
            break;
        }
        case 4:
        {
            _type = FIVE;
            break;
        }
        default:
        {
            std::cout << "Type too high - This should not happen!" << std::endl;
        }
        }
    }


    int CHand::map(const char ch)
    {
        if (isdigit(ch))
        {
            return ch - ZERO;
        }
        else if (ch == TEN)
        {
            return 10;
        }
        else if (ch == JOKER)
        {
            if (_toSolve == ESolve::SILVER)
            {
                return 11;
            }
            else if (_toSolve == ESolve::GOLD)
            {
                return 1;
            }
            else
            {
                std::cout << "Unknown metal - This should not happen!" << std::endl;
                return 0;
            }
        }
        else if (ch == QUEEN)
        {
            return 12;
        }
        else if (ch == KING)
        {
            return 13;
        }
        else if (ch == ACE)
        {
            return 14;
        }
        else
        {
            std::cout << "Unknown char - This should not happen!" << std::endl;
            return 0;
        }
    }

} //end of namespace aoc