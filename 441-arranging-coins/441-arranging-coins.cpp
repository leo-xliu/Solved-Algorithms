class Solution {
public:
    int arrangeCoins(int n) {;
        int l(1), h(n);
        int res = 0;
        while (l <= h){
            int mid = (h-l)/2 + l;
            if (mid <= (double) n*2/(mid+1)){
                res = max(res, mid);
                l = mid+1;
            }
            else h = mid-1;
        }
        return res;
    }
};


