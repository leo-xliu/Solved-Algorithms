class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int tar0(target[0]), tar1(target[1]), tar2(target[2]);
        vector<int> res(3);
        for (auto trip : triplets){
            if (trip[0] <= tar0 && trip[1] <= tar1 && trip[2] <= tar2){
                res = {max(res[0], trip[0]), max(res[1], trip[1]), max(res[2], trip[2])};
            }
        }
        return (res == target);
    }
};