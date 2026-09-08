class Solution {
public:
    bool equalFrequency(string word) {
        map<char, int>mpp;
        for(int i=0; i<word.length(); i++){
            mpp[word[i]]++;
        }
        int count=0;
        for(auto it:mpp){
            if(it.second>=2) count++;
        }
        if(count<=1) return true;
        else return false;
    }
};