class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            double sqr = (double) sqrt(x*x+y*y);
            pq.push({sqr, points[i]});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++){
            pair<double, vector<int>> temp = pq.top();
            pq.pop();
            res.push_back(temp.second);
        }
        return res;
    }
};