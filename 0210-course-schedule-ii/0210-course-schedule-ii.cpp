class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_set<int> ordered;
        vector<unordered_set<int>> courses(numCourses);
        for (int i = 0; i < prerequisites.size(); i++){
            vector<int> prereq = prerequisites[i];
            courses[prereq[0]].insert(prereq[1]);
        }
        for (int i = 0; i < numCourses; i++){
            if (ordered.find(i) == ordered.end()){
                vector<bool> visited(numCourses);
                if (!dfs(courses, visited, res, ordered, i)){
                    return {};
                } 
            }
        }
        return res;
    }
    
    bool dfs(vector<unordered_set<int>>& courses, vector<bool>& visited, vector<int>& res, unordered_set<int>& ordered, int course){
        if (ordered.find(course) != ordered.end()){
              return true;
        }
        if (visited[course]){
            return false;
        }
        visited[course] = true;
        for (auto p = courses[course].begin(); p != courses[course].end();){
            if (dfs(courses, visited, res, ordered, *p)){
                auto temp = p; 
                p++;
                courses[course].erase(*temp);
            }
            else {
                return false;
            }
        }
        res.push_back(course);
        ordered.insert(course);
        return true;
    }
};