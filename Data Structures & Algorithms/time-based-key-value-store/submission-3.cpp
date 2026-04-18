class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyValues;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyValues[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> valuePairs = keyValues[key];
        int l = 0, r = valuePairs.size() - 1;
        string result = "";
        while (l <= r) {
            int m = l + (r - l)/2;
            int currTimestamp = valuePairs[m].first;
            if (currTimestamp <= timestamp) {
                result = valuePairs[m].second;
                l = m + 1;
            }
            else r = m - 1;
        }
        
        return result;
    }
};
