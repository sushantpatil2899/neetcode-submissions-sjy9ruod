class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        vector<int> prev;
        for (int i=0; i<numRows; i++) {
            vector<int> temp(i+1,0);
            temp[0] = 1;
            temp[i] = 1;
            for (int j=1; j<i; j++) {
                if (j<=prev.size()) temp[j] = prev[j-1] + prev[j];
                else temp[j] = prev[j-1];

            }
            output.push_back(temp);
            prev = temp;
        }
        return output;
    }
};