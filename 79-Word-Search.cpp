class Solution {
    bool dfs(vector<vector<char>>& b, string& w, int i, int x, int y) {
        if (i == w.size()) return true;
        if (x < 0 || y < 0 || x >= b.size() || y >= b[0].size() || b[x][y] != w[i]) return false;
        char temp = b[x][y];
        b[x][y] = '#';
        bool found = dfs(b, w, i + 1, x + 1, y) || dfs(b, w, i + 1, x - 1, y) ||
                     dfs(b, w, i + 1, x, y + 1) || dfs(b, w, i + 1, x, y - 1);
        b[x][y] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(board, word, 0, i, j)) return true;
        return false;
    }
};