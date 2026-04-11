class Solution {
public:
    bool binarySearch(vector<int> matrix, int target) {
        int left = 0;
        int right = matrix.size() -1;
        int mid = 0;

        while (left<=right) {
            mid = left + (right-left)/2;
            if (matrix[mid] < target) {
                left = mid + 1;
            }
            else if (matrix[mid] > target) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }

    bool binarySearchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() -1;
        int mid = 0;

        while (left<=right) {
            mid = left + (right-left)/2;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            }
            else if (matrix[mid][0] < target) {
                if (matrix[mid][matrix[mid].size()-1]<target) {
                    left = mid+1;
                }
                else if (matrix[mid][matrix[mid].size()-1]>target) {
                    return binarySearch(matrix[mid], target);
                }
                else {
                    return true;
                }
            }
            else {
                return true;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearchMatrix(matrix, target);
    }
};