#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(candidates, target, 0, comb, res);
        return res;
    }
    
private:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                comb.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i, comb, res);
                comb.pop_back();
            }
        }
    }
};
