class Solution {
public:
   
bool isNumber(string s) {
    bool num = false, exp = false, dot = false;
    int i = 0, n = s.size();
    if (s[i] == '+' || s[i] == '-') i++;
    for (; i < n; i++) {
        if (isdigit(s[i])) num = true;
        else if (s[i] == '.') {
            if (dot || exp) return false;
            dot = true;
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (!num || exp) return false;
            exp = true;
            num = false;
            if (i + 1 < n && (s[i + 1] == '+' || s[i + 1] == '-')) i++;
        } else return false;
    }
    return num;
}
};