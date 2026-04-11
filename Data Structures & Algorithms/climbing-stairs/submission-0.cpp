class Solution {
public:
    int calculateWaysToClimb(int n, int s) {
        if (s == n) {
            return 1;
        }
        else if (s > n) {
            return 0;
        }
        else {
            return calculateWaysToClimb(n, s+1) + calculateWaysToClimb(n, s+2);
        }
    }
    int climbStairs(int n) {
        return calculateWaysToClimb(n, 1) + calculateWaysToClimb(n, 2);
    }
};