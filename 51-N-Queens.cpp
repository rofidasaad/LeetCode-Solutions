class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> board(n, -1);
        solve(n, 0, board, result);
        return result;
    }

private:
    void solve(int n, int row, vector<int>& board, vector<vector<string>>& result) {
        if (row == n) {
            vector<string> solution(n, string(n, '.'));
            for (int i = 0; i < n; ++i)
                solution[i][board[i]] = 'Q';
            result.push_back(solution);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, board)) {
                board[row] = col;
                solve(n, row + 1, board, result);
                board[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, vector<int>& board) {
        for (int i = 0; i < row; ++i)
            if (board[i] == col || abs(board[i] - col) == row - i)
                return false;
        return true;
    }
};