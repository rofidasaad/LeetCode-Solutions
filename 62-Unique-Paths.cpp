class Solution {
public:
    int uniquePaths(int m, int n) {
        long long paths = 1;
        for (int i = 1; i < min(m, n); ++i)
            paths = paths * (m + n - 1 - i) / i;
        return paths;
    }
};
