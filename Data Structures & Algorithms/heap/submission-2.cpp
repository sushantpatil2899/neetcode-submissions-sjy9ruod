class MinHeap {
private:
    vector<int> minHeap;
public:
    MinHeap() {
        minHeap.push_back(0);
    }

    void push(int val) {
        minHeap.push_back(val);
        int i = minHeap.size() - 1;

        while ((minHeap[i] < minHeap[i/2]) && i/2!=0){
            int temp = minHeap[i/2];
            minHeap[i/2] = minHeap[i];
            minHeap[i] = temp;
            i = i/2;
        }
    }

    int pop() {
        if (minHeap.size()<2) {
            return -1;
        }
        else if (minHeap.size()==2) {
            int temp = minHeap.back();
            minHeap.pop_back();
            return temp;
        }

        int temp = minHeap[1];
        minHeap[1] = minHeap.back();
        minHeap.pop_back();

        int i = 1;
        while (2*i < minHeap.size()) {
            if (2*i+1<minHeap.size() && minHeap[2*i+1]<minHeap[2*i] && minHeap[2*i+1]<minHeap[i]) {
                int temp = minHeap[i];
                minHeap[i] = minHeap[2*i+1];
                minHeap[2*i+1] = temp;
                i = 2*i+1;
            }
            else if (minHeap[2*i]<minHeap[i]) {
                int temp = minHeap[i];
                minHeap[i] = minHeap[2*i];
                minHeap[2*i] = temp;
                i = 2*i;
            }
            else {
                break;
            }
        }
        return temp;
    }

    int top() {
        if (minHeap.size()<2) {
            return -1;
        }
        return minHeap[1];
    }

    void heapify(const vector<int>& arr) {
        for (int num: arr) {
            minHeap.push_back(num);
        }

        int curr = minHeap.size()/2;
        while (curr>0) {
            int i = curr;
            while (2*i < minHeap.size()) {
                if (2*i+1<minHeap.size() && minHeap[2*i+1]<minHeap[2*i] && minHeap[2*i+1]<minHeap[i]) {
                    int temp = minHeap[i];
                    minHeap[i] = minHeap[2*i+1];
                    minHeap[2*i+1] = temp;
                    i = 2*i+1;
                }
                else if (minHeap[2*i]<minHeap[i]) {
                    int temp = minHeap[i];
                    minHeap[i] = minHeap[2*i];
                    minHeap[2*i] = temp;
                    i = 2*i;
                }
                else {
                    break;
                }
            }
            curr--;
        }
    }
};
