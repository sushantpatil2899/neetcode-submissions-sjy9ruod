class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        int count = 0;
        int output = 0;

        while (count != n) {
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                    count++;
                    output++;
                    break;
                }
            }

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (const auto& neighbour: adjList[node]) {
                    if (!vis[neighbour]) {
                        vis[neighbour] = 1;
                        q.push(neighbour);
                        count++;
                    }
                }
            }
        }

        return output;
    }
};
