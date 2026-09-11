class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //build linked list for each int
        //then populate it with edges & visited

        //then do dfs from n = 0, do dfs/bfs
        //return answer; 

        vector<int> parents(n, 0), sizes(n, 1);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        int answer = n;
        for (const auto&  edge : edges) {
            int first = edge[0], second = edge[1];

            int root1 = findParent(first, parents);
            int root2 = findParent(second, parents);

            if (root1 == root2) {
                continue;
            }
            else {
                //merge
                if (sizes[root1] >= sizes[root2]) {
                    parents[root2] = parents[root1];
                    sizes[root1] += 1;
                } else {
                    parents[root1] = parents[root2];
                    sizes[root2] += 1;
                }
                answer -= 1;
            }

        }
        return answer;
    }

    int findParent(int node, vector<int> &parents) {
        if (parents[node] == node) {
            return parents[node];
        }
        
        //path compression
        parents[node] = findParent(parents[node], parents);
        return parents[node];
    }
};
