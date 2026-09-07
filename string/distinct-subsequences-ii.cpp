class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long dp = 1;  // includes empty subsequence
        long long end[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long oldDp = dp;

            // Add subsequences formed by appending c
            dp = (2 * dp - end[x] + MOD) % MOD;

            // All subsequences ending in c now come from oldDp
            end[x] = oldDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};