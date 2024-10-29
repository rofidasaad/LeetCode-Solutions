class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, \\, res);
        return res;
    }
private:
    void generate(int open, int close, string current, vector<string> &res) {
        if (open == 0 && close == 0) res.push_back(current);
        if (open > 0) generate(open - 1, close, current + \(\, res);
        if (close > open) generate(open, close - 1, current + \)\, res);
    }
};