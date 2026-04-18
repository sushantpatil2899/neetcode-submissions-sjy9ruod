class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int l = 0, r = 0;
        dq.push_back(l);
        vector<int> out;
        while (r < nums.size()) {
            while (!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if (r - l + 1 == k) {
                while (dq.front() < l) dq.pop_front();
                out.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return out;
    }
};
