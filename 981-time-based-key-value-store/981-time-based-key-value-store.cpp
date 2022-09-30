class TimeMap {
private: 
    unordered_map<string, vector<pair<int, string>>> timemap;   
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back(pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int l(0), h(timemap[key].size()-1);
        int maxi = -1;
        while (l <= h){
            int mid = (h-l)/2 +l;
            if (timemap[key][mid].first <= timestamp){
                maxi = max(maxi, mid);
                l = mid+1;
            }
            else h = mid-1;
        }
        if (maxi == -1){
            return "";
        }
        return timemap[key][maxi].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */