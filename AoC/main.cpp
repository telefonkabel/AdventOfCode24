#include "CDay.h"
#include "solvedPuzzles.h"

#include <vector>
#include <iostream>
#include <windows.h>

int main()
{
    ShowWindow(GetConsoleWindow(), SW_NORMAL);
    std::vector<std::unique_ptr<aoc::CDay>> puzzles{};
	
    // Solve puzzles
    puzzles.push_back(std::make_unique<aoc::CDay01>(ESolve::ALL));
    puzzles.push_back(std::make_unique<aoc::CDay07>(ESolve::ALL));

    for (auto& puzzle : puzzles)
    {
        puzzle->solve();
    }

    std::cout << std::endl << "Press Enter to continue...";
    std::cin.get();
	return 0;
}