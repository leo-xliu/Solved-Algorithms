class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> map;
        int res = cards.size()+1;
        for (int i = 0; i < cards.size(); i++){
            if (map.find(cards[i]) != map.end()){
                res = min(res, i-map[cards[i]]+1);
            }
            map[cards[i]] = i;
        }
        if (res == cards.size()+1) return -1;
        return res;
    }
};