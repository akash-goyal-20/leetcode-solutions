class disjointSet {
    vector<int> rank;
    vector<int> parent;

public:
    int components;
    disjointSet(int n) {
        components = n;
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = findUparent(parent[n]);
    }

    void unite(int u, int v) {
        int pU = findUparent(u);
        int pV = findUparent(v);

        if (pU == pV) {
            return;
        }

        if (rank[pU] > rank[pV]) {
            parent[pV] = pU;
        } else if (rank[pU] < rank[pV]) {
            parent[pU] = pV;
        } else {
            parent[pV] = pU;
            rank[pU]++;
        }
        components--;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (k >= n)
            return 0;
        disjointSet ds(n);
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            ds.unite(u, v);
            if (ds.components <= k) {
                return wt;
            }
        }

        return -1;
    }
};