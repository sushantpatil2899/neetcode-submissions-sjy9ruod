class WordDistance {
private:
    unordered_map<string, vector<int>> wordsDictMap;

public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            wordsDictMap[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int distance = numeric_limits<int>::max();
        for (const auto& i : wordsDictMap[word1]) {
            for (const auto& j: wordsDictMap[word2]) {
                distance = min(distance, abs(j-i));
            }
        }
        return distance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
