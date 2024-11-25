class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negative = 0, is0 = 0, min = abs(matrix[0][0]);
        long long result = 0;
        int length = matrix.size(); 
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (matrix[i][j] < 0) {
                    result -= matrix[i][j]; 
                    matrix[i][j] *= -1;     
                    negative++;     
                }
                else {
                    result += matrix[i][j]; 
                }
                if (matrix[i][j] < min) {
                    min = matrix[i][j];    
                }
                if (matrix[i][j] == 0) {
                    is0 = 1;            
                }
            }
        }
        if (negative %2 == 0 || is0 == 1) {
            return result;  
        }
        else {
            return result - 2 * min;  
        }
    }
};
