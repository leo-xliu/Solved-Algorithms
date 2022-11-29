class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        vector<vector<int>> res; 
        int i = 0;
        for (; i < intervals.size(); i++){
            if (newStart > intervals[i][1]){//after next interval
                res.push_back(intervals[i]);
                continue;
            }
            else if (newStart > intervals[i][0]){
                newInterval[0] = intervals[i][0];//between next interval
            }
            while (i < intervals.size()){
                if (newEnd < intervals[i][0]){
                    break;
                }
                else if (newEnd < intervals[i][1]){
                    newInterval[1] = intervals[i++][1];
                    break;
                }
                i++;
            }
            break;
        }
        res.push_back(newInterval);
        for (; i < intervals.size(); i++){
            res.push_back(intervals[i]);
        }
        return res;
    }
};