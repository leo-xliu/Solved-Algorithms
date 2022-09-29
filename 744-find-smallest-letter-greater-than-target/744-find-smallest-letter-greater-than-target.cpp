class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters[letters.size()-1]){
            return letters[0];
        }
        if (target < letters[0]){
            return letters[0];
        }
        int res = letters[letters.size()-1]; 
        int l(0), h(letters.size()-2);
        while (l <= h){
            int mid = (l+h)/2;
            int letter = letters[mid];
            if (letter > target){
                res = min(res, letter);
                h = mid-1;
            }
            else l = mid+1;
        }
        return res;
    }
};