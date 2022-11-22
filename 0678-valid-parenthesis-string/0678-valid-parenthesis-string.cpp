class Solution {
public:
    bool checkValidString(string s) {
        int leftmin = 0;
        int leftmax = 0;
        for (char ch : s){
            if (ch == '('){
                leftmin++;
                leftmax++;
            }
            else if (ch == ')'){
                leftmin--;
                leftmax--;
            }
            else if (ch == '*'){
                leftmin--;
                leftmax++;
            }
            if (leftmax < 0){
                return false;
            }
            if (leftmin < 0){
                leftmin = 0;
            }
        }
        if (leftmin > 0){
            return false;
        }
        return true;
    }
};