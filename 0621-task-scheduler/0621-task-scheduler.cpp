class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> wait;
        unordered_map<char, int> map;
        for (int i = 0; i < tasks.size(); i++){
            map[tasks[i]]++;
        }
        for (auto p = map.begin(); p != map.end(); p++){
            pq.push(p->second);
        }
        int time = 0;
        while(!pq.empty() || !wait.empty()){
            if (pq.empty() && !wait.empty() && time+1-wait.front().first <= n){
                time += 1+(n-(time+1-wait.front().first));
            }
            while (!wait.empty() && time+1-wait.front().first > n){
                int temp = wait.front().second;
                wait.pop();
                pq.push(temp);
            }
            int temp = pq.top();
            pq.pop();
            time++;
            if (temp-- > 1){
                wait.push({time, temp});
            }
        }
        return time;
    }
};


//check if we need to add idle time
//check if queue has items to pop
//find max pq value and add time