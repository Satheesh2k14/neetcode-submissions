class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //dsu components 2 means not valid
        // dsu which already connected means invalid
        if (edges.size() != n - 1) return false;

        vector<int> parents(n, 0), ranks(n, 1);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }

        int components = n;
        //process edges
        for (auto const& edge: edges) {
            int first = edge[0], second = edge[1];
            
            int firstParent = findParent(first, parents), secondParent = findParent(second, parents);
            if (firstParent == secondParent) {
                //already connected false
                return false;
            }

            //merge trees to bigger tree size
            parents[firstParent] = secondParent;

            components--;

        }

        if (components > 1) return false;
        return true;

    }

    int findParent(int current, vector<int> &parents) {
        if(current == parents[current]) return current;

        parents[current] = findParent(parents[current], parents);

        return parents[current];
    }
};
