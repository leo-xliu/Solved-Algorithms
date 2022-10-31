class Solution {
public:
    int hammingDistance(int x, int y) {
        int xXORy = x^y;
        int hamming = 0;
        for (int i = 0; i < 32; i++){
            hamming += (xXORy & 1);
            xXORy = xXORy >> 1;
        }
        return hamming; 
    }
};