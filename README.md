# 🧩 Sudoku Game in C++

A console-based Sudoku game built in C++ featuring puzzle generation, user interaction, and a backtracking solver.

---

## 🎮 Features

- Interactive Sudoku board (console UI)
- Manual move validation
- Automatic Sudoku solver (Backtracking)
- Random puzzle generator
- Difficulty levels:
  - Easy
  - Medium
  - Hard
- Rule-based validation for rows, columns, and 3×3 sub-grids

---

## 🧠 Algorithms Used

- Backtracking (Recursive DFS)
- Constraint Checking
- Randomized Puzzle Generation
- 2D Grid Manipulation

---
## Game Flow Diagram:
Start
  ↓
Generate Board / Load Board
  ↓
Display Board
  ↓
Show Menu
  ↓
User Choice?
 ├── Enter Move → Validate → Update Board → Back to Menu
 ├── Solve Puzzle → Backtracking Solver → Show Result
 ├── Generate Puzzle → Create New Board → Back to Menu
 └── Exit → End

 ## Function Call Diagram

main()
 ├── displayBoard()
 ├── printMenu()
 ├── userMove()
 │     └── isValidMove()
 ├── solveSudoku()
 │     └── isValidMove()
 └── generatePuzzle()
       └── solveSudoku()

       
## 📌 How to Play

1. Run the program
2. Choose from the menu:
   - Enter a move
   - Solve automatically
   - Generate new puzzle
   - Exit
3. Input row, column, and value (1–9)

---

## 🧩 Sudoku Rules Implemented

- Each row must contain numbers 1–9 without repetition
- Each column must contain numbers 1–9 without repetition
- Each 3×3 sub-grid must contain numbers 1–9 without repetition

---

## ⚙️ Technical Details

- Language: C++
- Board Size: 9×9
- Indexing: 1-based
- Solver: Recursive backtracking algorithm

---

## 🧩 Future Improvements

- GUI version (SFML / Qt / Web)
- Hint system
- Timer mode
- Save & load game
- Puzzle generator with unique solution guarantee

---

## 👨‍💻 Author

Built for learning Data Structures, Algorithms, and Backtracking techniques.

---

## ⭐ Purpose

This project helps to:
- Strengthen recursion & backtracking skills
- Improve problem-solving ability
- Practice real-world algorithm design
