class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, c = 0, s = source.length(), t = target.length();
        
        while (j < t) {
            cout << i << ", " <<j<<endl;
            if (source[i] == target[j]) {
                i++;
                j++;
                cout <<"match"<<endl;
            }
            else {
                cout <<"not match"<<endl;
                int start_i = i;
                i++;
                while (i<s && source[i] != target[j]) i++;
                if (i == s) {
                    if (start_i == 0) return -1;
                    else {
                        c++;
                        i = 0;
                    }
                }
                else {
                    cout <<"found next match: "<<i<<", "<<j<< endl;
                    i++;
                    j++;
                }
            }
            if (i == s) {
                cout<<"increment c"<<endl;
                c++;
                i = 0;
            }
        }
        if (i!= s && i!= 0) c++;
        return c;

    }
};
