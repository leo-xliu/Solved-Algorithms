class Solution {
public:
    int countOdds(int low, int high) {
        int n = high-low;
        if (low % 2) n++;
        if (high % 2) n++;
        return n/2;
    }
};