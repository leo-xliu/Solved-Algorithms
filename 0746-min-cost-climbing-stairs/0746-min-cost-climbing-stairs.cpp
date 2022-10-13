class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int taketwo = cost[0];
        int takeone = cost[1];
        for (int i = 2; i < cost.size(); i++){
            int temp = takeone;
            takeone = cost[i] + min(takeone, taketwo);
            taketwo = temp;
        }
        return min(takeone, taketwo);
    }
};