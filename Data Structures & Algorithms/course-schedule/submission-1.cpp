class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        for (const auto& preReq: prerequisites) {
            preMap[preReq[0]].push_back(preReq[1]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);

        for (int i = 0; i<numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, preMap, vis, path)) return false;
            }
        }
        return true;
    }

    bool dfs(int course, vector<vector<int>>& preMap, vector<int>& vis, vector<int>& path) {
        vis[course] = 1;
        path[course] = 1;

        for (const auto& preCourse: preMap[course]) {
            if (!vis[preCourse]) {
                if (dfs(preCourse, preMap, vis, path)) return true;
            }
            else if (path[preCourse]) return true;
        }

        path[course] = 0;
        return false;
    }
};
