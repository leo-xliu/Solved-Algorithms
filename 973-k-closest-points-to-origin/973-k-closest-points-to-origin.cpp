class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            double sqr = (double) sqrt(x*x+y*y);
            pq.push({sqr, points[i]});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()){
            pair<double, vector<int>> temp = pq.top();
            pq.pop();
            res.push_back(temp.second);
        }
        return res;
    }
};

//to make solution nlogk, use a max heap of size k 
//this stores the k smallest values since we always remove max
// min heap with size k stores k largest values since we always remove min