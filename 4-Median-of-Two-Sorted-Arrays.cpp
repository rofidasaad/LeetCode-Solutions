class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return Median(nums1, nums2);
    }

    double Median(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, count = 0;
        int m1 = 0, m2 = 0;
        int size = nums1.size() + nums2.size();

        while (count < size / 2 + 1) {
            m2 = m1;
            if (i < nums1.size() && j < nums2.size()) {
                if (nums1[i] <= nums2[j]) {
                    m1 = nums1[i];
                    i++;
                } else {
                    m1 = nums2[j];
                    j++;
                }
            } else if (i < nums1.size()) {
                m1 = nums1[i];
                i++;
            } else if (j < nums2.size()) {
                m1 = nums2[j];
                j++;
            }
            count++;
        }

        if (size % 2 == 0) {
            return (m1 + m2) / 2.0;
        } else {
            return m1;
        }
    }
};
