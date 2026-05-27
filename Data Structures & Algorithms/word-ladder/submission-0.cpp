class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord == endWord) return 0;

        wordList.push_back(beginWord);
        int m = wordList.size();
        int n = wordList[0].size();
        vector<vector<int>> adjList(m);
        unordered_map<string, int> wordIndex;

        for (int i = 0; i <m; i++) {
            wordIndex[wordList[i]] = i;
            for (int j = i+ 1; j < m; j++) {
                if (validWord(wordList[i], wordList[j], n)) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> q;
        vector<int> vis(m, 0);
        q.push({wordIndex[beginWord], 1});
        vis[wordIndex[beginWord]] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int level = q.front().second;
            q.pop();

            for (const int nei: adjList[node]) {
                if (!vis[nei]) {
                    if (wordList[nei] == endWord) return level + 1;
                    else {
                        vis[nei] = 1;
                        q.push({nei, level+1});
                    }
                }
            }
        }

        return 0;
    }

    bool validWord(string& word1, string& word2, int& n) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (word1[i] != word2[i]) {
                c++;
                if (c > 1) return false;
            }
        }
        return true;
    }
};
