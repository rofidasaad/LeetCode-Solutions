

class Solution {
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    
    function<void(int, int)> dfs = [&](int index, int remaining) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > remaining) break;
            current.push_back(candidates[i]);
            dfs(i, remaining - candidates[i]);
            current.pop_back();
        }
    };
    
    dfs(0, target);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);

    for (auto& comb : result) {
        for (int num : comb) {
            cout << num << \ \;
        }
        cout << endl;
    }

    return 0;
}

};
