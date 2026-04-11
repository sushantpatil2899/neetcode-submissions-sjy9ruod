class Graph {
private:
    unordered_map<int, vector<int>> gp;

public:
    Graph() {}

    void addEdge(int src, int dst) {
        if (!gp.count(src)) {
            gp.insert({src, {}});
        }
        if (!gp.count(dst)) {
            gp.insert({dst, {}});
        }
        gp[src].push_back(dst);
    }

    bool removeEdge(int src, int dst) {
        if (!gp.count(src) || !gp.count(dst)) return false;
        auto it = find(gp[src].begin(), gp[src].end(), dst);
        if (it != gp[src].end()) {
            gp[src].erase(it);
            return true;
        }
        return false;
    }

    bool hasPath(int src, int dst) {
        if (!gp.count(src) || !gp.count(dst)) return false;
        unordered_set<int> visit;
        deque<int> q;
        visit.insert(src);
        q.push_back(src);

        while (!q.empty()) {
            int size = q.size();
            cout<<endl<<"Queue Size"<<size;
            cout<<endl<<"Queue In Loop: ";
            for (auto &p:q) {
                cout<<p<<", ";
            }
            for (int i=0; i<size; i++) {
                int curr = q.front();
                q.pop_front();
                if (curr==dst) return true;

                for (int n:gp[curr]) {
                    if (!visit.count(n)) {
                        visit.insert(n);
                        q.push_back(n);
                    }
                }
            }
        }
        return false;
    }
};
