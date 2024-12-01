# Advent of Code 2024

This repository is my personal take on solving the Advent of Code riddles. AoC is a fun coding challenge held every December, where each day brings a new puzzle to solve. I enjoy the mix of algorithmic thinking and creative solutions it requires, so I built this setup to make working on the puzzles as smooth as possible.

## About This Repository

The code is structured to be modular and reusable, so I can quickly adapt to each day’s puzzle without repeating boilerplate. While I keep things clean and organized, I don’t go overboard with features like full error handling — it’s all about solving the puzzles and having fun.

## How to Run

- Open the project in Visual Studio (configured for VS19 with C++17).
- Place the input data for the specific day in `dayXX/inputXX.txt`.
- Build the solution and run the executable.

## How I Approach the Puzzles

Each puzzle is different, but the general workflow is:

- Parse the input data (often messy and challenging).
- Break down the problem into smaller parts.
- Use whatever algorithms or tricks fit best — sorting, searching, dynamic programming, or sometimes just brute force if it’s good enough.

I prioritize readability and maintainability, but I also enjoy squeezing out optimizations when needed.

## Project Structure

The repository is organized by day:

- **`dayXX` folders**: Contain the code and input files for each puzzle.
- **`solvedPuzzles.h`**: Keeps track of which days are implemented.
- **`main.cpp`**: Runs all the solved puzzles.

### Adding a New Day

1. Create a new folder for the day (`dayXX`).
2. Write your solution in `CDayXX.h` and `CDayXX.cpp`.
3. Add the header to `solvedPuzzles.h`.
4. Push it to the `puzzles` list in `main.cpp`.

That’s it! The setup takes care of the rest.

## Why I’m Doing This

I love coding challenges because they keep my skills sharp and let me play with algorithms in a creative way. Advent of Code is also a great tradition, and this repository is my way of capturing that journey.
