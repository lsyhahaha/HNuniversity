#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

class NQueens {
public:
    // 回溯法解法
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        solveNQueensRecursive(result, board, 0, n);
        return result;
    }

    // 位运算法解法
    vector<vector<string>> solveNQueensBitwise(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        solveNQueensRecursiveBitwise(result, board, 0, 0, 0, 0, n);
        return result;
    }

private:
    // 回溯法递归函数
    void solveNQueensRecursive(vector<vector<string>>& result, vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solveNQueensRecursive(result, board, row + 1, n);
                board[row][col] = '.'; // 回溯
            }
        }
    }

    // 位运算法递归函数
    void solveNQueensRecursiveBitwise(vector<vector<string>>& result, vector<string>& board,
                                      int row, int colMask, int diagMask, int antiDiagMask, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int colBit = (1 << col);
            int diagBit = (1 << (row - col + n - 1));
            int antiDiagBit = (1 << (row + col));

            if (!(colMask & colBit) && !(diagMask & diagBit) && !(antiDiagMask & antiDiagBit)) {
                board[row][col] = 'Q';
                solveNQueensRecursiveBitwise(result, board, row + 1,
                                             colMask | colBit, diagMask | diagBit, antiDiagMask | antiDiagBit, n);
                board[row][col] = '.'; // 回溯
            }
        }
    }

    // 判断是否可以放置皇后
    bool isValid(const vector<string>& board, int row, int col, int n) {
        // 检查列是否有皇后
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 检查左上对角线是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 检查右上对角线是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    NQueens solution;

    // 回溯法
    cout << "Recursive Solution:" << endl;
    vector<vector<string>> result = solution.solveNQueens(n);
    for (const auto& board : result) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << "---------------------" << endl;
    }

    // 位运算法
    cout << "Bitwise Solution:" << endl;
    result = solution.solveNQueensBitwise(n);
    for (const auto& board : result) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << "---------------------" << endl;
    }

    return 0;
}
