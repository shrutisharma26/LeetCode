class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=n*n;
        vector<int>ans;
        map<int, int>mpp;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mpp[grid[i][j]]++;
            }
        }
        int sum1 = m*(m+1)/2;
        int sum2=0;
        for(auto it:mpp){
            if(it.second==2) ans.push_back(it.first);
            sum2+=it.first;
        }
        ans.push_back(abs(sum1-sum2));

        return ans;
    }
};