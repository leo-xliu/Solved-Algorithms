class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool trip1(false), trip2(false), trip3(false);
        int tar1(target[0]), tar2(target[1]), tar3(target[2]);
        int t1, t2, t3;
        for (int i = 0; i < triplets.size(); i++){
            t1 = triplets[i][0];
            t2 = triplets[i][1];
            t3 = triplets[i][2];
            if (tar1 == t1 && t2 <= tar2 && t3 <= tar3){
                trip1 = true;
            }
            if (tar2 == t2 && t1 <= tar1 && t3 <= tar3){
                trip2 = true;
            }
            if (tar3 == t3 && t2 <= tar2 && t1 <= tar1){
                trip3 = true;
            }
        }
        return (trip1 && trip2 && trip3);
    }
};