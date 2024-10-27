#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, max_area = 0;
        while (left < right) {
            int width = right - left;
            max_area = max(max_area, min(height[left], height[right]) * width);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
};
