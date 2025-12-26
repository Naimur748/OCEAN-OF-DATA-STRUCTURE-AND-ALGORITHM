
#include <iostream>
using namespace std;

class Solution {
    public:

    bool isSafe(int node, int color[], bool graph[101][101], int V, int c){
        for(int k = 0; k < V; k++){
            if(graph[node][k] && color[k]== c){
                return false;
            }
            return true;
        }
    }

    bool solve(int node, int color[], bool graph[101][101], int V, int m){
        if(node == V)
            return true;

            for(int c = 1; c <= m; c++){
                if(isSafe(node, color, graph, V, c)){
                    color[node] = c;

                    if(solve(node + 1, color, graph, V, m))
                        return true;

                        color[node] = 0;

                }
            }
            return false;
    }

    bool graphColoring(bool graph[101][101], int m, int V){
      int color[V];

      for(int i=0; i < V; i++)
        color[i] = 0;

        return solve(0, color, graph, V, m);

   }


};

int main() {
    Solution sol;

    // 🔹 Example graph
    int V = 4;      // vertex সংখ্যা
    int m = 3;      // max রঙ সংখ্যা

    // 🔹 adjacency matrix তৈরি
    bool graph[101][101] = {0};

    // edges
    int edges[][2] = { {0,1}, {1,3}, {2,3}, {3,0}, {0,2} };
    int E = 5; // edges সংখ্যা

    // adjacency matrix populate করা
    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = true;
        graph[v][u] = true; // undirected
    }

    // 🔹 check graph coloring
    if(sol.graphColoring(graph, m, V))
        cout << "Graph can be colored with " << m << " colors.\n";
    else
        cout << "Graph cannot be colored with " << m << " colors.\n";

    return 0;
}