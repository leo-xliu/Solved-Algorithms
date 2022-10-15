class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int Trues = 0;
        int Falses = 0;
        int l(0), r(0);
        int maxcount = 0;
        int res = 0;
        for (; r < answerKey.length(); r++){
            if (answerKey[r] == 'T'){
                Trues++;
                maxcount = max(Trues, maxcount);
            } 
            else{
                Falses++;
                maxcount = max(Falses, maxcount);
            } 
            if (r-l+1 - maxcount > k){
                if (answerKey[l] == 'T') Trues--;
                else Falses--;
                l++;
            }
            else {
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};