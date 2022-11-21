class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (edges.size() < n-1) return false;
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]][edges[i][1]] = 1;
            graph[edges[i][1]][edges[i][0]] = 1;
        }
        vector<int> visitStatus(n, 0);
        unordered_set<int> connectedComponents;
        return isValid(graph, visitStatus, connectedComponents);
    }

    bool isValid(vector<vector<int>> &graph, vector<int> &visitStatus, unordered_set<int> &connectedComponents) {
        connectedComponents.insert(0);
        if (!visitFromNodeN(graph, visitStatus, connectedComponents, 0) || connectedComponents.size() != graph.size()) return false;
        return true;
    }

    bool visitFromNodeN(vector<vector<int>> &graph, vector<int> &visitStatus, unordered_set<int> &connectedComponents, int n) {
        // visitStatus -> 0: initial; 1: visiting; 2: visited
        if (visitStatus[n] == 2) return true;
        else if (visitStatus[n] == 1) return false;
        visitStatus[n] = 1;
        for (int i = 0; i < graph.size(); i++) {
            // If there is an edge between node n and i
            if (graph[n][i] == 1) {
                connectedComponents.insert(i);
                // set graph[i][n] to 0 to prevent we traverse the same edge twice
                graph[i][n] = 0;
                if (!visitFromNodeN(graph, visitStatus, connectedComponents, i)) return 0;
                graph[i][n] = 1;
            }
        }
        visitStatus[n] = 2;
        return true;
    }
};