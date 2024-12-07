class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return \\;

        string prefix = strs[0];
        int prefixLen = prefix.length();

        for (int i = 1; i < strs.size(); i++) {
            string s = strs[i];
            while (prefixLen > s.length() || prefix != s.substr(0, prefixLen)) {
                prefixLen--;
                if (prefixLen == 0) {
                    return \\;
                }
                prefix = prefix.substr(0, prefixLen);
            }
        }

        return prefix;        
    }
};