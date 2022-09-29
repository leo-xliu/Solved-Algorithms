// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l(1), h(n);
        int res = n;
        while (l <= h){
            int mid = floor((double) h/2 + (double) l/2);
            if (isBadVersion(mid)){
                res = min(res, mid);
                h = mid-1;
            }
            else l = mid+1;
        }
        return res;
    }
};