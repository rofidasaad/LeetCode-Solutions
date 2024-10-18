class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int total_length = m + n;
        int half = (total_length + 1) / 2;
        
        int left = 0;
        int right = m;
        
        while (left <= right) {
            int partition_x = (left + right) / 2;
            int partition_y = half - partition_x;
            
            double max_left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
            double min_right_x = (partition_x == m) ? INT_MAX : nums1[partition_x];
            
            double max_left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];
            double min_right_y = (partition_y == n) ? INT_MAX : nums2[partition_y];
            
            if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
                if (total_length % 2 == 1) {
                    return max(max_left_x, max_left_y);
                }
                return (max(max_left_x, max_left_y) + min(min_right_x, min_right_y)) / 2.0;
            }
            else if (max_left_x > min_right_y) {
                right = partition_x - 1;
            }
            else {
                left = partition_x + 1;
            }
        }
        
        throw runtime_error(\Input arrays are not sorted\);
    }
};