#include <iostream>
#include <vector>

using namespace std;

// Function to display the game board
void printBoard(const vector<char>& board) {
    cout << "\n " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n\n";
}

// Function to check if the current player has won
bool checkWin(const vector<char>& board, char player) {
    // Winning combinations: rows, columns, diagonals
    int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[winCombinations[i][0]] == player &&
            board[winCombinations[i][1]] == player &&
            board[winCombinations[i][2]] == player) {
            return true;
        }
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') return false; // Game is still ongoing
    }
    return true;
}

// Main function to play the game
void playGame() {
    vector<char> board(9, ' ');  // 3x3 grid initialized with empty spaces
    char currentPlayer = 'X';    // Start with player X
    bool gameOngoing = true;

    while (gameOngoing) {
        printBoard(board);
        int move;

        // Get valid player input
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
            move--; // To match 0-based indexing

            if (move >= 0 && move < 9 && board[move] == ' ') {
                board[move] = currentPlayer;
                break;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameOngoing = false;
        }
        // Check for a draw
        else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            gameOngoing = false;
        }
        // Switch players if the game is still ongoing
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();
    } else {
        cout << "Thanks for playing!\n";
    }
}

int main() {
    playGame();
    return 0;
}
