class Twitter {
    private: 
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, deque<pair<int, int>>> tweets;
    int time;
public:
    Twitter() : time(0) {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
        if (tweets[userId].size() > 10) tweets[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < tweets[userId].size(); i++){
            pq.push(tweets[userId][i]);
        }
        for (auto p = follows[userId].begin(); p != follows[userId].end(); p++){
            for (int i = tweets[*p].size()-1; i >= 0; i--){
                if (!pq.empty() && pq.top().first > tweets[*p][i].first && pq.size() == 10) break;
                pq.push(tweets[*p][i]);
                if (pq.size() > 10) pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()){
            int temp = pq.top().second;
            pq.pop();
            res.push_back(temp);
        }
        vector<int> res2;
        for (int i = res.size()-1; i >= 0; i--){
            res2.push_back(res[i]);
        }
        return res2;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


//data structure
//each user has their follow list, they are also on their follow list
//each time follow list gets updated, we want to update their feed
//store users in a 2 unordered_maps
//first unordered_map contains their follow list, including themselves
//second unordered_map contains their last 10 tweets as the rest will never be used again
//associated each tweet event with a timestamp which is a stream that can never go backwards
//we create a kminheap everytime posttweet is called