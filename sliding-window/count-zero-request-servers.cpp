class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m);
        unordered_map<int, int> cnt;

        int left = 0, right = 0;
        int active = 0;
        int len = logs.size();

        for (auto [time, idx] : q) {

            // Add logs with time <= query time
            while (right < len && logs[right][1] <= time) {
                int server = logs[right][0];

                if (cnt[server] == 0)
                    active++;

                cnt[server]++;
                right++;
            }

            // Remove logs outside the window
            while (left < right && logs[left][1] < time - x) {
                int server = logs[left][0];

                cnt[server]--;

                if (cnt[server] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};