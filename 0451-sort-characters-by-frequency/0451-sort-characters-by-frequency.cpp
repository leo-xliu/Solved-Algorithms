class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (int i = 0; i < s.length(); i++){
            count[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto p = count.begin(); p != count.end(); p++){
            pq.push({p->second, p->first});
        }
        string res = "";
        while (!pq.empty()){
            pair<int, char> curChar = pq.top();
            pq.pop();
            res += string(curChar.first, curChar.second);
        }
        return res;
    }
};