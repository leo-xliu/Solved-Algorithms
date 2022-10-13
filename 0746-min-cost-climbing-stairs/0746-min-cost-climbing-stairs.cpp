class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> takestep(cost.begin(), cost.end());
        int i = 2;
        for (; i < cost.size(); i++){
            takestep[i] += min(takestep[i-1], takestep[i-2]);
        }
        return min(takestep[i-1], takestep[i-2]);
    }
};