class Solution {
public:
    void backtrack(string &curr, int open, int close, int n,
                   vector<string> &ans) {

        // We have used all brackets
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add '(' if we still have some left
        if (open < n) {
            curr.push_back('(');

            backtrack(curr, open + 1, close, n, ans);

            curr.pop_back();
        }

        // We can add ')' only if it won't make the sequence invalid
        if (close < open) {
            curr.push_back(')');

            backtrack(curr, open, close + 1, n, ans);

            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        backtrack(curr, 0, 0, n, ans);

        return ans;
    }
};