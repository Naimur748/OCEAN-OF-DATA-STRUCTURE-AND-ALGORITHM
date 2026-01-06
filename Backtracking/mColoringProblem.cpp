#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(int node, int color[], vector<vector<int>> &graph, int v, int c) {
        for(int k = 0; k < v; k++) {
            if(graph[node][k] && color[k] == c)
                return false;
        }
        return true;
    }

    bool solve(int node, int color[], vector<vector<int>> &graph, int v, int m) {
        if(node == v)
            return true;

        for(int c = 1; c <= m; c++) {
            if(isSafe(node, color, graph, v, c)) {
                color[node] = c;

                if(solve(node + 1, color, graph, v, m))
                    return true;

                color[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {

        // Edge list → Adjacency Matrix
        vector<vector<int>> graph(v, vector<int>(v, 0));
        for(auto &e : edges) {
            graph[e[0]][e[1]] = 1;
            graph[e[1]][e[0]] = 1;
        }

        int color[v];
        for(int i = 0; i < v; i++)
            color[i] = 0;

        return solve(0, color, graph, v, m);
    }
};

int main() {
    Solution obj;

    int v = 4;   // number of vertices
    int m = 3;   // number of colors

    // Edge list (undirected graph)
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3}
    };

    if(obj.graphColoring(v, edges, m))
        cout << "Graph coloring is POSSIBLE\n";
    else
        cout << "Graph coloring is NOT POSSIBLE\n";

    return 0;
}
