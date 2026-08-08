class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        // suf[i] = maximum suffix length of word2 that can be matched
        // using word1 starting from i.
        vector<int> suf(n + 1, 0);

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
                suf[i]++;
            }
        }

        // Even after one modification, impossible.
        if (suf[0] < m - 1)
            return {};

        vector<int> ans;
        bool changed = false;

        j = 0;

        for (int i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!changed) {
                // Can we spend our one modification here?
                if (j + suf[i + 1] + 1 >= m) {
                    changed = true;
                    ans.push_back(i);
                    j++;
                }
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};