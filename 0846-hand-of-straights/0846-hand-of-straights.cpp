class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0){
            return false;
        }
        map<int, int> count;
        for (int i = 0; i < hand.size(); i++){
            count[hand[i]]++;
        }
        while (!count.empty()){
            int min = count.begin()->first;
            for (int i = min; i < min+groupSize; i++){
                if (count.find(i) == count.end()){
                    return false;
                }
                if (--count[i] == 0){
                    count.erase(i);
                }
            }
        }
        return true;
    }
};