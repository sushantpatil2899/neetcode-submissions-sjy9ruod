class Solution {
private:
    priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>>> minHeap;

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (vector<int> point : points) {
            double dist = sqrt(pow(point[0], 2) + pow(point[1], 2));
            minHeap.push({dist, point});
        }

        vector<vector<int>> result;
        for (int i=0; i<k; i++) {
            pair<double, vector<int>> temp = minHeap.top();
            result.push_back(temp.second);
            minHeap.pop();
        }
        return result;
    }
};