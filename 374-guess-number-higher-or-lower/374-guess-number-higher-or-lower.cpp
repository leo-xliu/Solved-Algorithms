/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        double l = 1, h(n);
        while (l <= h){
            int mid = floor(l/2 + h/2);
            int check = guess(mid);
            if (!check) return mid;
            if (check == 1) l = mid+1;
            else h = mid-1;
        }
        return -1;
    }
};