class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 1){
            int temp = amount / coins[0];
            if (amount % coins[0] != 0) return -1;
            return temp;
        }
        vector<int> leastCoins(amount+1);
        for (int i = 0; i < coins.size(); i++){
            if (coins[i] > amount) continue;
            else if (coins[i] == amount) return 1;
            leastCoins[coins[i]]++;
        }
        for (int i = 1; i < amount+1; i++){
            if (leastCoins[i] != 0) continue;
            int least = amount+1;
            for (int j = 0; j < coins.size(); j++){
                int coinpath = i - coins[j];
                if (coinpath < 0) coinpath = amount+1;
                else coinpath = leastCoins[coinpath];
                least = min(least, coinpath);
            }
            if (least != amount+1) least++;
            leastCoins[i] = least;
        }
        int res = leastCoins[amount];
        if (res == amount+1) return -1;
        return res;
    }
};