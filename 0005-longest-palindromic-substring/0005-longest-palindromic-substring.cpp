class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dq;
        for (int i = 0; i < s.size(); i++){
            vector<bool> temp(s.size(), false);
            dq.push_back(temp);
        }
        for (int i = 0; i < s.size(); i++){
            dq[i][i] = true;
        }
        for (int i = 0; i < s.size()-1; i++){
            dq[i][i+1] = (s[i] == s[i+1]);
        }
        int maxi = 0;
        int maxj = 0;
        int maxlen = 0;
        for (int i = s.size()-3; i >= 0; i--){
            for (int j = i + 2; j < s.size(); j++){
                dq[i][j] = (s[i] == s[j] && dq[i+1][j-1]);
            }
        }
        for (int i = 0; i < s.size(); i++){
            for (int j = i; j < s.size(); j++){
                if (dq[i][j]){
                    if (maxlen < j-i){
                        maxi = i;
                        maxj = j;
                        maxlen = j-i;
                    }
                }
            }
        }
        return s.substr(maxi, maxj-maxi+1);
    }
};

//solved using 2d dp 
//half of 2d array 
//rows = start value 
//col = end value
//start and end value are outmost values so they must match 
//check array to see if middle matches then we're good