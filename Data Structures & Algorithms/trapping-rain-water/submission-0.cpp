class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int l = 0, r = height.size() - 1;
        int result = 0;
        int maxLeftHeight = height[l], maxRightHeight = height[r];

        while (l < r) {
            if (maxLeftHeight <= maxRightHeight) {
                l++;
                maxLeftHeight = max(maxLeftHeight, height[l]);
                result += maxLeftHeight - height[l];
            }
            else {
                r--;
                maxRightHeight = max(maxRightHeight, height[r]);
                result += maxRightHeight - height[r];
            }
        }

        return result;
    }
};
