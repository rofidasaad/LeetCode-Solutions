class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int val = 1, left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) mat[top][i] = val++;
            top++;
            for (int i = top; i <= bottom; ++i) mat[i][right] = val++;
            right--;
            if (left <= right) {
                for (int i = right; i >= left; --i) mat[bottom][i] = val++;
                bottom--;
            }
            if (top <= bottom) {
                for (int i = bottom; i >= top; --i) mat[i][left] = val++;
                left++;
            }
        }
        return mat;
    }
};
