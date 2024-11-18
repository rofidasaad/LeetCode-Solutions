class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        generate(nums, 0, subset, res);
        return res;
    }
    
private:
    void generate(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(subset);
            return;
        }
        generate(nums, index + 1, subset, res);
        subset.push_back(nums[index]);
        generate(nums, index + 1, subset, res);
        subset.pop_back();
    }
};