class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> monoinc;
        int maxres = 0;
        int i = 0;
        for (; i < heights.size(); i++){
            if (monoinc.empty() || monoinc.top().second < heights[i]) {
                monoinc.push({i, heights[i]});
                continue;
            }
            else if (monoinc.top().second == heights[i]) continue;
            int leftind;
            while (!monoinc.empty() && monoinc.top().second > heights[i]){
                leftind = monoinc.top().first;
                int width = i-leftind;
                int height = monoinc.top().second;
                monoinc.pop();
                int temparea = width*height;
                maxres = max(temparea, maxres);
            }
            monoinc.push({leftind, heights[i]});
        }
        while (!monoinc.empty()){
            int width = i-monoinc.top().first; 
            int height = monoinc.top().second;
            monoinc.pop();
            maxres = max(width*height, maxres);
        }
        return maxres;
    }
};


//we will keep a monotonic increasing stack with all the indexes and their heights
//the indexes will actually the the index of the farthest left value their rectangle of their height can extend to
//everytime we reach a shorter height, we must pop the top until it becomes monotonically increasing again
//each time we pop, we record the max size it can obtain at its height
//so it will be current index - stored index which gives the max width it has at its height
//then multiplied by its height
//then we store the newest height with the farthest left possible index because all of those index has its height
//we know this as a fact because the stack is monotonically increasing so all that we just popped will have at least the height 
//so that gives us an easy way of finding the left most valid index (which is the same as the last popped index)
