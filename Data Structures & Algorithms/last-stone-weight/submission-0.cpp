class Solution {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
public:
    int lastStoneWeight(vector<int>& stones) {
        for (int stone:stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size()>1) {
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if (stone1!=stone2) {
                maxHeap.push(stone1-stone2);
            }
        }
        if (maxHeap.size()==0) {
            return 0;
        }
        return maxHeap.top();
    }
};