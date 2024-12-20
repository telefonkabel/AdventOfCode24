#pragma once

#include "ESolve.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <list>
#include <vector>


namespace aoc
{
    using vecStr = std::vector<std::string>;
    using vecInt = std::vector<int>;
    using vVecStr = std::vector<std::vector<std::string>>;
    using vVecInt = std::vector<std::vector<int>>;

    //Base class for all puzzles (usually one per day).
	class CDay
	{
	public:
        CDay(int dayID, ESolve toSolve = ESolve::ALL):
            _dayID{ dayID }
            , _toSolve{ toSolve }
            {};
		virtual void solve();
        int getID() const { return _dayID; };

    protected:
        // Splits a string by multiple delimiters. Useful for diverse puzzle inputs.
        std::vector<std::string> splitBy(const std::string& str, const std::vector<std::string>& del) const;
        // Helper function for some puzzles. Checks if an integer lies within a specific range. 
        bool inRange(int low, int high, int x) const;

        // Parses the input file into a specified container type (e.g., list or vector).
        // Supports vectors of integers and strings, which is sufficient for most puzzles
        template <typename Container>
        void parseStr2Container(Container& input, const std::string str, const std::vector<std::string>& dels = { " " }) const
        {
            std::vector<std::string> vecLine{ splitBy(str, dels) };

            if constexpr (std::is_same_v<typename Container::value_type, int>)
            {
                for (const auto& val : vecLine)
                {
                    int value{};
                    if (!isValidInt(val, value))
                    {
                        return;
                    }
                    input.push_back(value);
                }
            }
            else if constexpr (std::is_same_v<typename Container::value_type, std::vector<int>>)
            {
                std::vector<int> vInt{};
                for (const auto& val : vecLine)
                {
                    int value{};
                    if (!isValidInt(val, value))
                    {
                        return;
                    }
                    vInt.push_back(value);
                }
                input.push_back(vInt);
            }
            else if constexpr (std::is_same_v<typename Container::value_type, std::vector<std::string>>)
            {
                input.push_back(vecLine);
            }
            else
            {
                // Default to string, since it is applicable for all puzzle types with input file
                input.push_back(str);
            }
        }

        template <typename Container>
        Container parse2Container(const int day, const std::vector<std::string>& dels = { " " }) const
        {
            std::ifstream inFile{ parse(day) };
            Container input{};
            std::string line{};

            while (std::getline(inFile, line))
            {
                parseStr2Container<Container>(input, line, dels);
            }
            return input;
        };

	private:
        int _dayID;
        ESolve _toSolve;
        // Calculates the silver or gold solution of this day. To be implemented by each Advent of Code day, but not necessary for others.
        virtual std::string calculateSilver() const { return std::string{}; };
        virtual std::string calculateGold() const { return std::string{}; };

        // Reads the input file for the corresponding day.
        std::ifstream parse(const int day) const;
        // Helper function for modular parsing.
        std::string formatDigits(int width, int num) const;
        // Helper function to validate an input line as an integer
        bool isValidInt(const std::string& line, int& value) const;
        // Helper function for output info
        void calculateAndDisplay(ESolve type);
	};

} // namespace aoc




