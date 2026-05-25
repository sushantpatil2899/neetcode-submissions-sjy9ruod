class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preMap(numCourses);
        vector<int> inDeg(numCourses, 0);
        for (const auto& preReq: prerequisites) {
            preMap[preReq[1]].push_back(preReq[0]);
            inDeg[preReq[0]]++;
        }

        queue<int> q;
        for (int i = 0; i<numCourses; i++) {
            if (inDeg[i] == 0) q.push(i);
        }

        int finish = 0;
        vector<int> output(numCourses);
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            finish++;
            output.push_back(course);
            for (const auto& nextCourse: preMap[course]) {
                inDeg[nextCourse]--;
                if (inDeg[nextCourse]==0) q.push(nextCourse);
            }
        }

        if (finish == numCourses) return output;
        return {};
    }
};
