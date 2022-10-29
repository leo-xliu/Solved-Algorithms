class Solution {
public:
    int addDigits(int num) {
        string sNum = to_string(num);
        while (sNum.size() != 1){
            int newNum = 0;
            for (int i = 0; i < sNum.size(); i++){
                newNum += (sNum[i]-'0');
            }
            sNum = to_string(newNum);
        }
        return stoi(sNum);
    }
};