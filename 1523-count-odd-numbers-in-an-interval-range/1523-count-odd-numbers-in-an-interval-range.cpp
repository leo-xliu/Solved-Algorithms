class Solution {
public:
    int countOdds(int low, int high) {
        int n = high-low;
        if (low % 2 == 1 && high % 2 == 1){
            n = n + 2;
        }
        else if (low % 2 == 1 || high % 2 == 1){
            n++;
        }
        return n/2;
    }
};