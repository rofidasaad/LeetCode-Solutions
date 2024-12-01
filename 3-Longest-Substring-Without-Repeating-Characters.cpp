class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map <char , int >np;

        int mx =0;
        int l=0;

        for( int i =0; i < s.size(); i++){
            while ( np [s[i]] !=0){
                np [s [l]]=0;
                 l++;
            }
            np [s[i]]++;
           
           mx = max(mx, i - l + 1);
        }
        return mx;
    }
};

