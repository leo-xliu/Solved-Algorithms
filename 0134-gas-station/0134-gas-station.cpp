class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int sum = 0;
        for (int i = 0; i < gas.size(); i++){
            diff.push_back(gas[i]-cost[i]);
            sum += diff[i];
        }
        if (sum < 0 || !diff.size()){
            return -1;
        }
        sum = 0;
        int station = 0;
        for (int i = 0; i < diff.size(); i++){
            if (sum < 0){
                sum = 0;
                station = i;
            }
            sum += diff[i];
        }
        return station;
    }
};

