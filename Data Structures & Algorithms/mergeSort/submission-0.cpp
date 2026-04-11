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
    vector<Pair> mergeSubParts(vector<Pair>& pairs, int s, int m, int e) {
        vector<Pair> left_array(pairs.begin()+s, pairs.begin()+m+1);
        vector<Pair> right_array(pairs.begin()+m+1, pairs.begin()+e+1);
        int i = s;
        int l = 0;
        int r = 0;
        while (l<left_array.size() && r<right_array.size()) {
            if (left_array[l].key<=right_array[r].key) {
                pairs[i] = left_array[l];
                l++;
            }
            else {
                pairs[i] = right_array[r];
                r++;
            }
            i++;
        }

        if (l<left_array.size()) {
            for (int j = l; j<left_array.size(); j++) {
                pairs[i] = left_array[j];
                i++;
            }
        }
        else if (r<right_array.size()) {
            for (int j = l; j<right_array.size(); j++) {
                pairs[i] = right_array[j];
                i++;
            }
        }

        return pairs;
    }

    vector<Pair> mergeSortRecursive(vector<Pair>& pairs, int s, int e) {
        if (e-s+1<=1) {
            return pairs;
        }

        int m = s + ((e-s)/2);
        mergeSortRecursive(pairs, s, m);
        mergeSortRecursive(pairs, m+1, e);

        mergeSubParts(pairs, s, m, e);
        return pairs;
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) {
        return mergeSortRecursive(pairs, 0, pairs.size()-1);
    }
};
