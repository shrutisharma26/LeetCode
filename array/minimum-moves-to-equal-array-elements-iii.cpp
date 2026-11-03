class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_num = nums[0];
        for(int i=0; i<nums.size(); i++){
            max_num = max(max_num, nums[i]);
        }
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+= max_num - nums[i];
        }

        return sum;
    }
};