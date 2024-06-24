#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<char>& board);
void playerMove(vector<char>& board, char player);
bool checkWin(const vector<char>& board, char player);
bool checkDraw(const vector<char>& board);
void switchPlayer(char& player);
bool playAgain();

int main() {
    do {
        vector<char> board(9, ' '); // Create a 3x3 grid
        char currentPlayer = 'X'; // Assign 'X' to the first player

        while (true) {
            displayBoard(board);
            playerMove(board, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
                break;
            }

            switchPlayer(currentPlayer);
        }
    } while (playAgain());

    return 0;
}

void displayBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

void playerMove(vector<char>& board, char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
        } else {
            board[move - 1] = player;
            break;
        }
    }
}

bool checkWin(const vector<char>& board, char player) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto& pattern : winPatterns) {
        if (board[pattern[0]] == player && board[pattern[1]] == player && board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}
