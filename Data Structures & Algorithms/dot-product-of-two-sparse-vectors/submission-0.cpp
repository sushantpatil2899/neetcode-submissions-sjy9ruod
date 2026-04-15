class SparseVector {
public:
    unordered_map<int, int> vectorRep;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) vectorRep[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int m = vectorRep.size();
        int n = vec.vectorRep.size();

        int product = 0;
        if (m < n) {
            for (const auto& [index, value]: vectorRep) {
                if (vec.vectorRep.contains(index)) {
                    product += (vec.vectorRep[index]*value);
                }
            }
        }
        else {
            for (const auto& [index, value]: vec.vectorRep) {
                if (vectorRep.contains(index)) {
                    product += (vectorRep[index]*value);
                }
            }
        }
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
