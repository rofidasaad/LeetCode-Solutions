class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    for (char c : t) mp[c]++;
    int required = t.size(), l = 0, r = 0, minLen = INT_MAX, start = 0;
    while (r < s.size()) {
        if (mp[s[r++]]-- > 0) required--;
        while (required == 0) {
            if (r - l < minLen) minLen = r - l, start = l;
            if (++mp[s[l++]] > 0) required++;
        }
    }
    return minLen == INT_MAX ? \\ : s.substr(start, minLen);
}
};