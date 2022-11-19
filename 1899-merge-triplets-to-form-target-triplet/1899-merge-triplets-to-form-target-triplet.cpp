class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool trip1(false), trip2(false), trip3(false);
        int tar1(target[0]), tar2(target[1]), tar3(target[2]);
        for (auto trip : triplets){
            if (trip[0] == tar1 && trip[1] <= tar2 && trip[2] <= tar3){
                trip1 = true;
            }
            if (trip[1] == tar2 && trip[0] <= tar1 && trip[2] <= tar3){
                trip2 = true;
            }
            if (trip[2] == tar3 && trip[1] <= tar2 && trip[0] <= tar1){
                trip3 = true;
            }
        }
        return (trip1 && trip2 && trip3);
    }
};