<h1 align="center">🧩 Sudoku Game in C++</h1>

<p align="center">
  A console Sudoku game with random puzzle generation, real-time move validation, and an automatic solver built on recursive backtracking.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/language-C%2B%2B-blue" alt="C++">
  <img src="https://img.shields.io/badge/interface-console-lightgrey" alt="Console">
  <img src="https://img.shields.io/badge/algorithm-backtracking-green" alt="Backtracking">
  <img src="https://img.shields.io/badge/platform-Windows-informational" alt="Windows">
</p>

---

##  Table of Contents

1. [Overview](#overview)
2. [Demo](#demo)
3. [Features](#features)
4. [Screenshots](#screenshots)
   - [Console boards by difficulty](#console-boards-by-difficulty)
5. [How It Works](#-how-it-works)
6. [Program Flow & Architecture](#program-flow--architecture)
7. [Technical Details](#technical-details)
8. [Getting Started](#getting-started)
9. [How to Play](#how-to-play)
10. [Known Limitations](#known-limitations)
11. [Future Improvements](#future-improvements)
12. [Learning Goals](#learning-goals)
13. [Author](#author)

---

##  Overview

This project implements a complete, playable Sudoku in the terminal. Players can generate puzzles at three difficulty levels, enter moves that are validated against the standard Sudoku rules, or let the built-in solver complete the board automatically.

It was built to practice recursion, backtracking, and constraint checking on a 2D grid.

---

## 🎬 Demo

A full walkthrough of the app: generating a puzzle, entering valid and invalid moves, and watching the solver complete the board.

▶️ **[Watch the demo video](YOUR_VIDEO_LINK_HERE)**

---

##  Features

- **Interactive console board** with clear 3×3 box separators
- **Move validation** that rejects out-of-range input, filled cells, and rule violations with a clear message
- **Automatic solver** using recursive backtracking
- **Random puzzle generator** with three difficulty levels:

  | Level | Cells removed |
  |---|---|
  | 🟢 Easy | 30 |
  | 🟡 Medium | 45 |
  | 🔴 Hard | 55 |

- **Complete rule enforcement** across rows, columns, and 3×3 sub-grids

---

##  Screenshots

[![Game board](https://i.postimg.cc/Y0Ps5zfT/sd.png)](https://postimg.cc/sGpmSSLJ)

##  Console Boards by Difficulty

Example boards as they appear in the console after choosing **3. Generate new puzzle**. A `.` marks an empty cell.

### 🟢 Easy (51 given numbers)

```text
-------------------------
| . . 3 | 4 5 . | 7 8 9 |
| 4 . 6 | 7 . 9 | . . 3 |
| 7 8 . | . . 3 | . 5 6 |
-------------------------
| 2 . . | 3 . . | . 9 7 |
| 3 6 . | . 9 7 | . . . |
| 8 9 . | . . 4 | 3 6 5 |
-------------------------
| 5 3 1 | 6 4 2 | 9 . 8 |
| 6 4 2 | 9 7 8 | . 3 . |
| 9 . 8 | 5 3 1 | . 4 . |
-------------------------
```

### 🟡 Medium (36 given numbers)

```text
-------------------------
| . 2 . | 4 5 6 | . . 9 |
| 4 . 6 | . . . | 1 . . |
| 7 8 . | 1 2 . | 4 . . |
-------------------------
| . 1 . | 3 . . | . 9 . |
| 3 . . | . 9 7 | 2 1 4 |
| 8 9 . | . . . | . . 5 |
-------------------------
| . . . | . 4 . | 9 7 8 |
| 6 . 2 | . . 8 | 5 . . |
| . . . | 5 3 . | 6 . . |
-------------------------
```

### 🔴 Hard (26 given numbers)

```text
-------------------------
| . . . | 4 . . | 7 8 9 |
| . 5 . | . 8 . | . 2 . |
| . . . | 1 . . | 4 . . |
-------------------------
| . 1 . | . . . | . . . |
| . . 5 | . 9 . | . . . |
| . . . | . . 4 | 3 . . |
-------------------------
| . . . | . 4 . | . 7 . |
| . . 2 | . . 8 | . 3 1 |
| 9 7 . | 5 3 . | 6 4 . |
-------------------------
```

---

##  How It Works

### Sudoku rules enforced
- Each **row** contains 1–9 without repetition
- Each **column** contains 1–9 without repetition
- Each **3×3 sub-grid** contains 1–9 without repetition

### Solver (backtracking)
1. Scan the board for the first empty cell.
2. Try values 1–9, keeping only those that pass `isValidMove`.
3. Place a value and recurse to the next empty cell.
4. If the recursion fails, reset the cell to 0 (**backtrack**) and try the next value.
5. When no empty cells remain, the puzzle is solved.

### Puzzle generation
1. Clear the board.
2. Solve it completely with the backtracking solver.
3. Remove a random set of cells according to the chosen difficulty.

| Concept | Used for |
|---|---|
| Recursive DFS / backtracking | Solving the board |
| Constraint checking | Validating every move |
| Randomization | Choosing which cells to remove |
| 2D grid manipulation | Storing, displaying, and traversing the board |

---

##  Program Flow & Architecture

**Program flow**

[![Program flow](https://i.postimg.cc/65RBwMyW/s1.png)](https://postimg.cc/HVpq94wR)

**Function architecture**

[![Function architecture](https://i.postimg.cc/1tLbjZ0v/s2.png)](https://postimg.cc/njGdXgPm)

| Function | Responsibility |
|---|---|
| `displayBoard()` | Clears the screen and renders the board |
| `isValidMove(row, col, val)` | Checks row, column, and 3×3 box constraints |
| `userMove()` | Reads, range-checks, and validates a player move |
| `solveSudoku()` | Recursive backtracking solver |
| `generatePuzzle(difficulty)` | Builds a solved board, then removes cells |
| `printMenu()` | Prints the main menu |

---

##  Technical Details

| | |
|---|---|
| **Language** | C++ (C++11 or newer) |
| **Board** | 9×9, stored in a `vector<vector<int>>` |
| **Indexing** | 1-based |
| **Solver** | Recursive backtracking |
| **Platform** | Windows (uses `system("cls")` / `system("pause")`) |

---

##  Getting Started

### Prerequisites
A C++ compiler such as `g++` (MinGW) or MSVC.

### Build and run

```bash
git clone <your-repo-url>
cd <your-repo-folder>
g++ -std=c++17 main.cpp -o sudoku
./sudoku
```

> On Linux/macOS, replace `system("cls")` with `system("clear")` and `system("pause")` with a "press Enter" prompt.

---

##  How to Play

Choose an option from the menu:

```
MENU:
1. Enter a move
2. Solve automatically
3. Generate new puzzle
4. Exit
```

To enter a move, type **row**, **column**, and **value** (each 1–9):

```
Enter row (1-9), col (1-9), value (1-9): 3 5 7
Move accepted!
```

Possible responses: `Invalid input range!`, `Cell already filled!`, `Move violates Sudoku rules!`.

---

##  Known Limitations

- The solver starts from an empty board, so the underlying full solution is the same for every generated puzzle; only the removed cells change.
- Puzzles are not checked for a unique solution.
- Screen-clearing commands are Windows-specific.

---

##  Future Improvements

- [ ] Randomized full-board generation
- [ ] Unique-solution guarantee
- [ ] Hint system
- [ ] Timer mode
- [ ] Save & load game
- [ ] Cross-platform support
- [ ] GUI version (SFML / Qt / Web)

---

##  Learning Goals

- Strengthen recursion and backtracking skills
- Improve problem-solving ability
- Practice real-world algorithm design

---

##  Author

Built for learning Data Structures, Algorithms, and Backtracking techniques.
