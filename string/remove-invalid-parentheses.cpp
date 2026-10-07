class Solution {
public:
    vector<string> ans;

    void dfs(string& s, int index, int leftRem, int rightRem,
             int balance, string& path) {

        // Reached end
        if (index == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0) {
                ans.push_back(path);
            }
            return;
        }

        char ch = s[index];

        // Case 1: '('
        if (ch == '(') {

            // Option 1: remove '('
            if (leftRem > 0) {
                dfs(s, index + 1, leftRem - 1, rightRem,
                    balance, path);
            }

            // Option 2: keep '('
            path.push_back('(');

            dfs(s, index + 1, leftRem, rightRem,
                balance + 1, path);

            path.pop_back();
        }

        // Case 2: ')'
        else if (ch == ')') {

            // Option 1: remove ')'
            if (rightRem > 0) {
                dfs(s, index + 1, leftRem, rightRem - 1,
                    balance, path);
            }

            // Option 2: keep ')'
            if (balance > 0) {
                path.push_back(')');

                dfs(s, index + 1, leftRem, rightRem,
                    balance - 1, path);

                path.pop_back();
            }
        }

        // Case 3: normal character
        else {
            path.push_back(ch);

            dfs(s, index + 1, leftRem, rightRem,
                balance, path);

            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum number of parentheses to remove
        for (char ch : s) {

            if (ch == '(') {
                leftRem++;
            }

            else if (ch == ')') {

                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        string path;

        dfs(s, 0, leftRem, rightRem, 0, path);

        // Remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};