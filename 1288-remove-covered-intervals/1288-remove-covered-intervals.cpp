class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto&b){return a[0] < b[0];});
        int count = intervals.size();
        int n = intervals.size()-1;
        for (int i = 0; i < n; i++){
            if (intervals[i][1] >= intervals[i+1][1]){
                count--;
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = intervals[i][1]; 
            }
            else if (intervals[i][0] == intervals[i+1][0] && intervals[i][1] < intervals[i+1][1]){
                count--;
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
        }
        return count;
    }
};


//if we sort by start times, 1,2,..., n
//n cannot cover 2, and 2 cannot cover 1 
//thus, 1 can potentially cover 2-n, 2 can potentially cover 3-n, etc
//note if interval 1 does not cover 2, then it cannot cover 3-n
//if we have same starting position, then all but one will be covered