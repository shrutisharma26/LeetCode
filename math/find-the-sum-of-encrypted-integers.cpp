class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            if(nums[i]>=1 && nums[i]<=9) sum+=nums[i];
            else{
                string s = to_string(nums[i]);
                for(int j=0; j<s.length(); j++){
                    s[j] = s[0];
                }
                sum+=stoi(s);
            }
        }
        return sum;
    }
};