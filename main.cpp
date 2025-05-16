// Tic Tac Toe in C++ with Minimax AI (Single Player & Two Player Modes)
#include <iostream>
#include <limits>
using namespace std;

char board[3][3];
const char PLAYER = 'X';
const char AI = 'O';

void initializeBoard() {
    for (int i = 0, k = '1'; i < 3; i++)
        for (int j = 0; j < 3; j++, k++)
            board[i][j] = k;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != PLAYER && board[i][j] != AI)
                return true;
    return false;
}

int evaluate() {
    for (int row = 0; row < 3; row++)
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
            return (board[row][0] == AI) ? +10 : -10;

    for (int col = 0; col < 3; col++)
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
            return (board[0][col] == AI) ? +10 : -10;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return (board[0][0] == AI) ? +10 : -10;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return (board[0][2] == AI) ? +10 : -10;

    return 0;
}

int minimax(bool isMax) {
    int score = evaluate();
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != PLAYER && board[i][j] != AI) {
                    char temp = board[i][j];
                    board[i][j] = AI;
                    best = max(best, minimax(false));
                    board[i][j] = temp;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != PLAYER && board[i][j] != AI) {
                    char temp = board[i][j];
                    board[i][j] = PLAYER;
                    best = min(best, minimax(true));
                    board[i][j] = temp;
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove() {
    int bestVal = -1000;
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != PLAYER && board[i][j] != AI) {
                char temp = board[i][j];
                board[i][j] = AI;
                int moveVal = minimax(false);
                board[i][j] = temp;
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

bool checkWin(char symbol) {
    return evaluate() == (symbol == AI ? 10 : -10);
}

bool isDraw() {
    return isMovesLeft() == false && evaluate() == 0;
}

void playerMove(char symbol) {
    int move;
    while (true) {
        cout << "Enter your move (1-9): ";
        cin >> move;
        if (!cin || move < 1 || move > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] == PLAYER || board[row][col] == AI) {
            cout << "Cell already occupied. Try again.\n";
        } else {
            board[row][col] = symbol;
            break;
        }
    }
}

int main() {
    int mode;
    cout << "Tic Tac Toe Game\n1. Single Player\n2. Two Player\nChoose mode: ";
    cin >> mode;

    initializeBoard();
    displayBoard();

    int turn = 0; // 0 = Player X, 1 = Player O or AI
    while (true) {
        if (mode == 1 && turn == 1) {
            cout << "\nAI is making a move...\n";
            pair<int, int> bestMove = findBestMove();
            board[bestMove.first][bestMove.second] = AI;
        } else {
            cout << "\nPlayer " << (turn == 0 ? 'X' : (mode == 2 ? 'O' : 'X')) << "'s turn.\n";
            playerMove(turn == 0 ? PLAYER : (mode == 2 ? AI : PLAYER));
        }

        displayBoard();

        if (checkWin(turn == 0 ? PLAYER : AI)) {
            cout << "Player " << (turn == 0 ? 'X' : (mode == 2 ? 'O' : 'O')) << " wins!\n";
            break;
        }
        if (isDraw()) {
            cout << "Game is a draw!\n";
            break;
        }

        turn = 1 - turn; // Toggle turn
    }
    return 0;
}
