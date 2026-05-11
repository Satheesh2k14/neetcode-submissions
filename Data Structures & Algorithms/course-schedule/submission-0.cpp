class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) {
            return true;
        }

        vector<vector<int>> dependency(numCourses, vector<int>(numCourses, 0));

        //fill dependency
        for (vector<int> preReq : prerequisites) {
            dependency[preReq[0]][preReq[1]] = 1;
        }

        //find courses that can be executed without any pre-req
        set<int> visited;
        for (int i = 0; i < numCourses; i++) {
            bool preReqNeeded = false;
            for (int j = 0; j < numCourses; j++) {
                if (dependency[i][j] == 1) {
                    preReqNeeded = true;
                    break;
                }
            }
            if (preReqNeeded == false) {
                visited.insert(i);
            }
        }

        //return false if no starter nodes
        if(visited.size() == 0) return false;

        int prevVisitedCount;
        do {
            prevVisitedCount = visited.size();

            //bfs
            for (int startNode: visited) {
                for(int i = 0; i < numCourses; i++) {
                    if (dependency[i][startNode] == 1) {
                        dependency[i][startNode] = 0;
                    }
                }
            }

            //check if new courses are completed
            for (int i = 0; i < numCourses; i++) {
                bool preReqNeeded = false;
                for (int j = 0; j < numCourses; j++) {
                    if (dependency[i][j] == 1) {
                        preReqNeeded = true;
                        break;
                    }
                }
                if (preReqNeeded == false) {
                    visited.insert(i);
                }
            }

            if (visited.size() == numCourses) {
                return true;
            }
        } while (visited.size() > prevVisitedCount);

        return false;

    }
};
