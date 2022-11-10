class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> deq;
        string res;
        for (int i = 0; i < s.length(); i++){
            if (!deq.empty() && deq.back() == s[i]){
               deq.pop_back();
            }
            else {
                deq.push_back(s[i]);
            }
        }
        while (!deq.empty()){
            res.push_back(deq.front());
            deq.pop_front();
        }
        return res;
    }
};