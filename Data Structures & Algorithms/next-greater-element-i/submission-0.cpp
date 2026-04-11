class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums_map;
        stack<int> s;
        vector<int> output;
        for (int i=nums2.size()-1; i>=0; i--) {
            while(!s.empty() && s.top()<=nums2[i]) s.pop();
            if (s.empty()) nums_map[nums2[i]]=-1;
            else nums_map[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for (int i=0; i<nums1.size(); i++) {
            output.push_back(nums_map[nums1[i]]);
        }
        return output;
    }
};