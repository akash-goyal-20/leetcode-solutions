class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<long long, vector<int>>> pq;

        for (auto &point : points) {

            long long x = point[0];
            long long y = point[1];

            long long dist = x * x + y * y;

            pq.push({dist, point});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};