#include <iostream>
#include <vector>
using namespace std;


void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){

    cout<< node << " ";

    visited[node] = true;

    for(int neighbor : graph[node]){
        if(!visited[neighbor]){
            dfs(neighbor, graph, visited);
        }
    }



};


int main(){

    vector<vector<int>> graph = {
        {},
        {2, 3},
        {4},
        {},
        {}
    };

    vector<bool> visited(5, false);

    dfs(1, graph, visited);

    return 0;
}