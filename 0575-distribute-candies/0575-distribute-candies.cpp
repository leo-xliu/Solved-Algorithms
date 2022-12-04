class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types(candyType.begin(), candyType.end());
        int half = candyType.size()/2;
        int allTypes = types.size();
        return min(half, allTypes);
    }
};