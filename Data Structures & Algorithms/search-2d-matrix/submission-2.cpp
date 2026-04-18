class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m - 1;
        
        while (l < r) {
            int mid = l + (r - l)/2;

            if (matrix[mid][n-1] >= target) r = mid;
            else l = mid + 1;
        }

        int row = l;

        l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l)/2;

            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};
