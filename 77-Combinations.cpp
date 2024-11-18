class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(1, n, k, temp, res);
        return res;
    }

private:
    void dfs(int start, int n, int k, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i <= n; ++i) {
            temp.push_back(i);
            dfs(i + 1, n, k, temp, res);
            temp.pop_back();
        }
    }
};
