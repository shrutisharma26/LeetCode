class Solution {
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, long long delta) {
            for (; i <= n; i += i & -i)
                bit[i] += delta;
        }

        long long query(int i) {
            long long sum = 0;
            for (; i > 0; i -= i & -i)
                sum += bit[i];
            return sum;
        }

        int kth(int k) {
            int idx = 0;

            for (int step = 1 << 17; step; step >>= 1) {
                int next = idx + step;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> maritovexi = nums;

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        Fenwick cnt(m), sum(m);

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(
                vals.begin(), vals.end(), nums[i]
            ) - vals.begin() + 1;
        }

        long long totalSum = 0;

        auto add = [&](int i, int delta) {
            cnt.update(rank[i], delta);
            sum.update(rank[i], 1LL * nums[i] * delta);
            totalSum += 1LL * nums[i] * delta;
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(i, 1);

        for (int i = 0; i <= n - x; i++) {
            int medRank = cnt.kth((x + 1) / 2);
            long long median = vals[medRank - 1];

            long long leftCount = cnt.query(medRank);
            long long leftSum = sum.query(medRank);

            long long rightCount = x - leftCount;
            long long rightSum = totalSum - leftSum;

            cost[i] =
                median * leftCount - leftSum +
                rightSum - median * rightCount;

            if (i < n - x) {
                add(i, -1);
                add(i + x, 1);
            }
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int t = 0; t <= k; t++) {
            for (int i = 0; i <= n; i++) {
                if (dp[t][i] == INF)
                    continue;

                if (i < n)
                    dp[t][i + 1] = min(
                        dp[t][i + 1], dp[t][i]
                    );

                if (t < k && i + x <= n) {
                    dp[t + 1][i + x] = min(
                        dp[t + 1][i + x],
                        dp[t][i] + cost[i]
                    );
                }
            }
        }

        return *min_element(dp[k].begin(), dp[k].end());
    }
};