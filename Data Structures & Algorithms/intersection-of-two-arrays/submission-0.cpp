class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> output;

        while (i < nums1.size() && j < nums2.size()) {
            cout << i << ", " << j;
            if (nums1[i] == nums2[j]) {
                output.push_back(nums1[i]);
                i++;
                while (i<nums1.size() && nums1[i]==nums1[i-1]) i++;
                j++;
                while (j<nums2.size() && nums2[j]==nums2[j-1]) j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
                while (i<nums1.size() && nums1[i]==nums1[i-1]) i++;
            }
            else {
                j++;
                while (j<nums2.size() && nums2[j]==nums2[j-1]) j++;
            }
        }

        return output;
    }
};