class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;

        for(int num : nums) {
            string s = to_string(num);
            char mx = '0';

            for(char c : s) {
                mx = max(mx, c);
            }
            for(char &c : s) {
                c = mx;
            }
            
            ans += stoi(s);
        }

        return ans;
    }
};