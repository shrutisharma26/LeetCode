class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        for(int x:nums1){
            if(x%2!=0) allEven = false;
        }
        return allEven || (*min_element(nums1.begin(), nums1.end()) % 2 == 1);
    }
};