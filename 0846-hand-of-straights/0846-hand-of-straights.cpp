class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int i = 0; i < hand.size(); i++){
            if (count.find(hand[i]) == count.end()){
                minheap.push(hand[i]);
            }
            count[hand[i]]++;
        }
        while (!minheap.empty()){
            int min = minheap.top();
            for (int i = min; i < min+groupSize; i++){
                if (count.find(i) == count.end()){
                    return false;
                }
                if (--count[i] == 0){
                    count.erase(i);
                    minheap.pop();
                }
            }
        }
        return true;
    }
};