class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        // suf[i] = smallest index in word2 that still needs to be matched
        // using word1[i...]
        vector<int> suf(n1 + 1);
        suf[n1] = n2;

        int j = n2 - 1;
        for (int i = n1 - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1;
        }

        vector<int> ans;
        bool used = false;
        j = 0;

        for (int i = 0; i < n1; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
                if (j == n2) return ans;
            }
            else if (!used && suf[i + 1] <= j + 1) {
                used = true;
                ans.push_back(i);
                j++;
                if (j == n2) return ans;
            }
        }

        return {};
    }
};