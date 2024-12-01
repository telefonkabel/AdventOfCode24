#include "CDay.h"

#include <iostream>
#include <sstream>
#include <iterator>


namespace aoc
{
	void CDay::solve()
	{
        calculateAndDisplay(_toSolve);
	}

    void CDay::calculateAndDisplay(ESolve type)
    {
        switch (type)
        {
        case ESolve::SILVER:
        {
            std::cout << "\nThe silver solution of day " << _dayID << " is: " << std::endl << calculateSilver() << std::endl;
            break;
        }
        case ESolve::GOLD:
        {
            std::cout << "\nThe gold solution of day " << _dayID << " is: " << std::endl << calculateGold() << std::endl;
            break;
        }
        case ESolve::ALL:
        {
            calculateAndDisplay(ESolve::SILVER);
            calculateAndDisplay(ESolve::GOLD);
            break;
        }
        default:
        {
            std::cout << std::endl << "Day " << _dayID << " will be skipped." << std::endl;
        }
        }
        return;
    }

    std::ifstream CDay::parse(const int day) const
    {
        std::filesystem::path inputFile{ std::filesystem::current_path()
            / std::filesystem::path{ "AoC" }
            / std::filesystem::path{ "day" + formatDigits(2, day) }
            / std::filesystem::path{ "input" + formatDigits(2, day) + ".txt" } };

        std::ifstream inFile{ inputFile };
        if (!inFile)
        {
            std::cerr << "Error: Could not open " << inputFile << std::endl;
        }

        return inFile;
    }

    std::vector<std::string> CDay::splitBy(const std::string& input, const std::vector<std::string>& dels) const
    {
        std::vector<std::string> outputVec{};

        std::list<std::string> output{input};
        // This could/should be optimized with regex
        for (std::string del : dels)
        {
            for (auto itr{ output.begin() }; itr != output.end();)
            {
                std::list<std::string> replace{};
                size_t last{ 0 };
                size_t next{ 0 };
                while ((next = (*itr).find(del, last)) != std::string::npos)
                {
                    std::string replacing{ (*itr).substr(last, next - last) };
                    if (replacing != "")
                    {
                        replace.push_back(replacing);
                    }

                    last = next + del.size();
                }
                std::string remaining{};
                if ((remaining = (*itr).substr(last)) != "")
                {
                    replace.push_back(remaining);
                }
                if (replace.size() > 0)
                {
                    output.insert(itr, replace.begin(), replace.end());
                    output.erase(itr++);
                }
                else
                {
                    ++itr;
                }
            }
        }

        for (auto str : output)
        {
            outputVec.push_back(str);
        }

        return outputVec;
    }

    bool CDay::inRange(int low, int high, int x) const
    {
        return (x - high) * (x - low) <= 0;
    }

    std::string CDay::formatDigits(int width, int num) const
    {
        std::ostringstream oss{};
        oss << std::setw(width) << std::setfill('0') << num;
        return oss.str();
    }
 
    bool CDay::isValidInt(const std::string& line, int& value) const
    {
        try
        {
            size_t pos{};
            value = std::stoi(line, &pos);
            if (pos != line.size())
            {
                // Msg is redundant
                throw std::invalid_argument{ "Non-integer found after an integer in line: " + line };
            }
            return true;
        }
        catch (const std::invalid_argument&)
        {
            std::cerr << "Invalid input: Unable to parse '" << line << "' as an integer." << std::endl;
            return false;
        }
        catch (const std::out_of_range&)
        {
            std::cerr << "Invalid input: '" << line << "' exceeds the range for integers." << std::endl;
            return false;
        }
    }

} // namespace aoc