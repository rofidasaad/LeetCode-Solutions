class Solution {
public:
   int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) for (int j = 0; j <= n; ++j)
        dp[i][j] = i == 0 ? j : j == 0 ? i : word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    return dp[m][n];
}

int main() {
    cout << minDistance(\horse\, \ros\) << endl;
    cout << minDistance(\intention\, \execution\) << endl;
    return 0;
}
};