class Solution {
public:
    int countCommas(int n) {
        if(n<=999) return 0;
        if(n>=1000 && n<=1999) return n%1000 + 1;

        //int s = n-1000;
       // int r = (n%1000)+1 ;

        return n - 1000 + 1;
    }
};