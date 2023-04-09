#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 定义雷区大小
const int ROWS = 20;
const int COLS = 20;

// 定义雷区
vector<vector<int>> board(ROWS, vector<int>(COLS, 0));

// 随机生成雷
void generateMines(int numMines) {
    srand(time(NULL));
    int count = 0;
    while (count < numMines) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] != -1) {
            board[row][col] = -1;
            count++;
        }
    }
}

// 显示雷区
void displayBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                cout << "* ";
            } else {
                int count = 0;
                for (int x = max(0, i - 1); x <= min(i + 1, ROWS - 1); x++) {
                    for (int y = max(0, j - 1); y <= min(j + 1, COLS - 1); y++) {
                        if (board[x][y] == -1) {
                            count++;
                        }
                    }
                }
                cout << count << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    // 生成10个雷
    generateMines(30);

    // 显示雷区
    displayBoard();

    return 0;
}
