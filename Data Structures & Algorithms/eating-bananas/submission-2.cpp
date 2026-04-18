class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = 0;
        for (const int b : piles) {
            maxBananas = max(maxBananas, b);
        }

        int l = 1, r = maxBananas;
        int min_k = maxBananas + 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (totalHours(piles, m) > h) l = m + 1;
            else {
                min_k = min(min_k, m);
                r = m - 1;
            }
        }
        return min_k;
    }

    int totalHours(vector<int>& piles, int k) {
        int hours = 0;
        for (const int b: piles) {
            int h = (b+k-1)/k;
            hours += max(h, 1);
        }
        // cout << "hours: "<< hours <<" for k: "<< k << endl;
        return hours;
    }
};
