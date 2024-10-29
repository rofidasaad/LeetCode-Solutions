class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        vector<string> mappings = {\\, \\, \abc\, \def\, \ghi\, \jkl\, \mno\, \pqrs\, \tuv\, \wxyz\};
        backtrack(result, mappings, digits, \\, 0);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, vector<string>& mappings, const string& digits, string current, int index) {
        if (index == digits.size()) { result.push_back(current); return; }
        for (char c : mappings[digits[index] - '0']) backtrack(result, mappings, digits, current + c, index + 1);
    }
};
