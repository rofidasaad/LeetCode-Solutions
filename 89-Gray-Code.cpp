class Solution {
public:
    void buildGrayCode(int bitCount,vector<int>& sequence) {
        if (bitCount==1) {
        sequence.push_back(0);
           sequence.push_back(1);
            return;
        }
        buildGrayCode(bitCount-1,sequence);

        int lastIndex=sequence.size() - 1;

        while (lastIndex >= 0) {
            int grayValue=(1<<(bitCount-1))| sequence[lastIndex];
            sequence.push_back(grayValue);
            lastIndex--;
        }
        return;
    }
    vector<int> grayCode(int numBits) {
        vector<int> graySequence;
        buildGrayCode(numBits, graySequence);
        return graySequence;   
    }
};
