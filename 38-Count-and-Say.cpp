
class Solution {
public:
    string countAndSay(int n) {
        string s = \1\;
        while (--n) {
            string temp;
            for (int i = 0; i < s.size(); i++) {
                int count = 1;
                while (i + 1 < s.size() && s[i] == s[i + 1]) {
                    count++;
                    i++;
                }
                temp += to_string(count) + s[i];
            }
            s = temp;
        }
        return s;
    }
};