class Solution {
public:
   vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0, n = words.size();
    while (i < n) {
        int width = words[i].size(), j = i + 1;
        while (j < n && width + words[j].size() + (j - i) <= maxWidth)
            width += words[j++].size();
        
        string line = words[i];
        int gaps = j - i - 1;
        if (j == n || gaps == 0) {
            for (int k = i + 1; k < j; k++)
                line += \ \ + words[k];
            line += string(maxWidth - line.size(), ' ');
        } else {
            int space = (maxWidth - width) / gaps, extra = (maxWidth - width) % gaps;
            for (int k = i + 1; k < j; k++) {
                line += string(space + (k - i <= extra), ' ') + words[k];
            }
        }
        result.push_back(line);
        i = j;
    }
    return result;
}
};