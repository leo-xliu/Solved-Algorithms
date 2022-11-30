class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return (a[0] < b[0]);});
        int curStart = intervals[0][0];
        int curEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (curEnd < intervals[i][0]){
                res.push_back({curStart, curEnd});
                curStart = intervals[i][0];
                curEnd = intervals[i][1];
            }
            else if (curEnd >= intervals[i][0] && curEnd < intervals[i][1]){
                curEnd = intervals[i][1];
            }
        }
        res.push_back({curStart, curEnd});
        return res;
    }
};