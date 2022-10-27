class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<bool> validCourses(numCourses);
        int checkedCourses = 0;
        //remove each edge until none of edges
        while (checkedCourses != numCourses){
            queue<int> removePrereq;
            for (int i = 0; i < numCourses; i++){
                if (courses[i].empty() && !validCourses[i]){
                    validCourses[i] = true;
                    checkedCourses++;
                    removePrereq.push(i);
                }
            }
            if (removePrereq.empty()) return false;
            while (!removePrereq.empty()){
                int curCourse = removePrereq.front();
                removePrereq.pop();
                for (int i = 0; i < numCourses; i++){
                    courses[i].erase(curCourse);
                }
            }
        }
        return true;
    }
};


//cannot be a DAG
//search for a loop