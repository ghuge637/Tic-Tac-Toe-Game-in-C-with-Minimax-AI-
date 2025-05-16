# Tic-Tac-Toe-Game-in-C-with-Minimax-AI-
 Tic Tac Toe game with a Minimax algorithm for AI that can play against the user (Single Player) or allow two players to compete (Two Player mode).

Features
✅ Console-based UI
✅ Two Modes:
             🧠 Single Player Mode (with unbeatable AI using Minimax)
             👥 Two Player Mode
✅ Input validation
✅ Detects Win, Draw
✅ Clean and user-friendly interface

📚 Key Concepts and Learning Points
1. Minimax Algorithm (AI Logic)
Implements a recursive minimax algorithm to simulate all possible future moves.
Evaluates each game state and picks the optimal move for the AI.
Used evaluate() function to assign scores:
+10 for AI win
-10 for Player win
0 for draw

2. Game Logic
Board is represented as a 3x3 char array.
Each cell is initialized with digits 1-9 for easy input.
Win conditions are checked across:
Rows
Columns
Diagonals

3. Clean Input Handling
Validates if the user input is within range and not already occupied.
Uses cin.clear() and cin.ignore() to handle bad input stream.

4. Turn Management
Uses turn = 1 - turn to toggle between players.
Dynamic switching depending on selected mode.

5. Separation of Concerns
Functions are clearly divided:
initializeBoard() → Setup
displayBoard() → Render
playerMove() → Handle user input
minimax() & findBestMove() → AI logic
checkWin() & isDraw() → Game status

How the AI Works
The Minimax AI:
Simulates every possible move recursively.
Assumes the player plays optimally.
AI aims to maximize score, Player aims to minimize it.
Selects the move that leads to the best outcome.
