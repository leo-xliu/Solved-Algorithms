class Solution {
public:
    bool isPerfectSquare(int num) {
        int l(1), h(num);
        while (l <= h){
            int mid = (h-l)/2 + l;
            double mid2 = (double) num/mid;
            if (mid2 == mid) return true;
            if (mid2 < mid) h = mid-1;
            else l = mid+1;
        }
        return false;
    }
};


