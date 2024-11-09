class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> board(n, -1);
        function<void(int)> solve = [&](int row) {
            if (row == n) { count++; return; }
            for (int col = 0; col < n; col++) {
                bool valid = true;
                for (int i = 0; i < row; i++) {
                    if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    board[row] = col;
                    solve(row + 1);
                    board[row] = -1;
                }
            }
        };
        solve(0);
        return count;
    }
};