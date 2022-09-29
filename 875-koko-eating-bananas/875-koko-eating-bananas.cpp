class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low(1), high(0);
        for (int i = 0; i < piles.size(); i++){
            high = max(high, piles[i]);
        }
        int res = high;
        while (low <= high){
            int k = (low+high)/2;
            long int temph = 0;
            for (int i = 0; i < piles.size(); i++){
                temph += ceil((double)piles[i]/k);
            }
            if (temph <= h){
                res = min(res, k);
                high = k-1;
            }
            else low = k+1;
        }
        return res;
    }
};

