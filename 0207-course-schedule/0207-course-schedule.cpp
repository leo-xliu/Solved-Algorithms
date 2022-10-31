class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create our prerequisite hashmap 
        vector<unordered_set<int>> courses(numCourses);
        for (int i = 0; i < prerequisites.size(); i++){
            vector<int> pair = prerequisites[i];
            int course = pair[0];
            int prereq = pair[1];
            if (course == prereq){
                return false;
            }
            courses[course].insert(prereq);
        }
        
        //remove each edge until none have prereqs
        //check if each course is valid
        for (int i = 0; i < numCourses; i++){
            if (courses[i].empty()){
                continue;
            }
            vector<bool> visited(numCourses);
            if (!dfs(courses, visited, i)){
                return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<unordered_set<int>>& courses, vector<bool>& visited, int curCourse){
        if (courses[curCourse].empty()){
            return true;
        }
        if (visited[curCourse]){
            return false;
        }
        visited[curCourse] = true;
        for (auto p = courses[curCourse].begin(); p != courses[curCourse].end();){
            if (dfs(courses, visited, *p)){
                auto temp = p;
                p++;
                courses[curCourse].erase(*temp);
            }  
            else {
                return false;
            }
        }
        return true;
    }
};


//cannot be a DAG
//search for a loop