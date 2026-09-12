class Solution {
public:
    vector<vector<long long>> dp;
    vector<vector<int>> a;
    vector<int> starts;

    long long solve(int i, int k) {
        if (i >= a.size() || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        // Skip current interval
        long long skip = solve(i + 1, k);

        // Take current interval
        int next = upper_bound(
            starts.begin(),
            starts.end(),
            a[i][1]
        ) - starts.begin();

        long long take =
            a[i][2] + solve(next, k - 1);

        return dp[i][k] = max(skip, take);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        a.resize(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end());

        starts.resize(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        dp.assign(n, vector<long long>(5, -1));

        solve(0, 4);

        vector<int> ans;

        int i = 0;
        int k = 4;

        while (i < n && k > 0) {

            long long skip = solve(i + 1, k);

            int next = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();

            long long take =
                a[i][2] + solve(next, k - 1);

            if (take >= skip) {
                ans.push_back(a[i][3]);
                i = next;
                k--;
            } else {
                i++;
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};