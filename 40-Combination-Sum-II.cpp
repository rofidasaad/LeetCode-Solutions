class Solution {
public:


    vector<vector<int>>answer;
    vector<int>tmp;
    int n;
    void find(int index,int target,vector<int>& candidates){
        if(!target)
            answer.push_back(tmp);
        
        if(target <=0||index == n)return;
    
        tmp.push_back(candidates[index]);
       find(index+1,target - candidates[index] ,candidates);
        tmp.pop_back();
        while(index+1 <n && candidates[index] == candidates[index+1])index++;
        find(index+1,target,candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        n = candidates.size();
        sort(candidates.begin(),candidates.end());
       find(0,target,candidates);
        return answer;
    }
};