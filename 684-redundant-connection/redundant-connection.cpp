class disjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    disjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int n) {
        if (parent[n] == n) {
            return parent[n];
        }
        return parent[n] = findUparent(parent[n]);
    }

    void unite(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else {
            rank[ulp_u]++;
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> ans;
        disjointSet ds(n);

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (ds.findUparent(u) == ds.findUparent(v)) {
                ans = {u, v};
            }
            ds.unite(u, v);
        }

        return ans;
    }
};