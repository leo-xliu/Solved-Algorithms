class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 12 || s.length() < 4){
            return {};
        }
        vector<string> res;
        dfs(res, s, 0, 1);
        return res;
    }

    void dfs(vector<string>& res, string& s, int start, int period){
        if (period == 4){
            if (stoi(s.substr(start, s.length()-start)) <= 255 && (s.length()-start == 1 || s[start] != '0')){
                res.push_back(s);
            }
            return;
        }
        for (int i = 1; i <=3; i++){
            if (start+i >= s.length() || i == 3 && stoi(s.substr(start, i)) > 255 || i != 1 && s[start] == '0'){
                break;
            }
            s.insert(start+i, ".");
            dfs(res, s, start+i+1, period+1);
            s.erase(start+i, 1);
        }
    }
};


//use string insert to add periods
//we are paritioning by using 3 periods
