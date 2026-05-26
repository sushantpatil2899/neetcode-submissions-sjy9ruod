class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (const auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        int count = 1;
        vis[0] = 1;
        q.push({0, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (const auto& neighbour : adjList[node]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = 1;
                    q.push({neighbour, node});
                    count++;
                }
                else if (neighbour != parent) return false;
            }
        }

        return (count == n);
    }
};
