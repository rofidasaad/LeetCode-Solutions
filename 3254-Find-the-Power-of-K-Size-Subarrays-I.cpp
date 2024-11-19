class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> ans(n-k+1);
        for (int i=0; i<n-k+1; i++){
            int counter=1;
            for (int j=i+1; j<i+k;j++){
                if(nums[j] == nums[j-1]+1)
                counter++;
            }
            ans[i]= counter>=k? nums[i+k-1] :-1;
        }
        return ans;
        
    }
};