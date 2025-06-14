# 🎮 Tic-Tac-Toe Game in C

This project was created for me to learn and practice programming in the C language by developing a simple terminal-based Tic-Tac-Toe game.

## ✅ Features

- Simple and clean terminal interface.
- Two-player mode (no AI).
- Move validation:
  - Prevents overlapping moves.
  - Prevents invalid moves (only numbers 1 to 9 allowed).
- Detects win by row, column, or diagonal.
- Detects draw when all spaces are filled.
- Displays custom messages for wins or draws.

---

## 🕹️ How to Play

1. Compile the code with a C compiler (e.g., `gcc`).
2. Run the program in your terminal.
3. Enter the number of the cell where you want to play (1 to 9), according to the board numbering.
4. The game alternates between players until someone wins or the game ends in a draw.

---

## ⚙️ How to Compile

Download the executavel.exe and run. Or download main.c archive and compile in your terminal.

---

🔍 Function Details

#checkMove(board, move)
  Ensures the player inputs a number between 1 and 9.
  Checks if the corresponding cell is still free.
  If invalid, asks repeatedly for a new valid input.

#checkWinner(board, moves, player)
  After each move, checks if the player has won.
  If all spaces are filled (moves > 9) without a winner, returns a draw.
  
#checkRowWin, checkCollumnWin, checkDiagonalsWin
  Check if the 3 positions in a row/column/diagonal contain the same symbol.

  ---

Developed with 💻 by me.
