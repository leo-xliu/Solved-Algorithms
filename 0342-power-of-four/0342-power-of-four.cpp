class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n > 0 && !(n & (n-1))){
            return(n & 1431655765);
        }
        return false;
    }
};