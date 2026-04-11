// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> quickSortRecursive(vector<Pair>& pairs,int s, int e){
        if (e-s+1<=1) {
            return pairs;
        }

        int pivot = pairs[e].key;
        int left = s;

        for (int i = s; i<e; i++) {
            if (pairs[i].key < pivot) {
                Pair tmp = pairs[i];
                pairs[i] = pairs[left];
                pairs[left] = tmp;
                left++;
            }
        }
        Pair tmp = pairs[e];
        pairs[e] = pairs[left];
        pairs[left] = tmp;

        quickSortRecursive(pairs, s, left-1);
        quickSortRecursive(pairs, left+1, e);

        return pairs;
    }

    vector<Pair> quickSort(vector<Pair>& pairs) {
        return quickSortRecursive(pairs, 0, pairs.size()-1);
    }
};
