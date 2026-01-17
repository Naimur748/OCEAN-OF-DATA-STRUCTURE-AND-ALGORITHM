#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int count, int n){
        if(count == n)
            return true;

            for(int next : adj[node]){
                if(!visited[next]){
                    visited[next] = true;

                    if(dfs(next, adj, visited, count + 1, n))
                        return true;
                    visited[next] = false;
                }    
            }
            return false;

    }

    bool check(int n, int m, vector<vector<int>> edges){
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i < n; i++){
            vector<bool> visited(n, false);
            visited[i] = true;

            if(dfs(i,  adj, visited, 1, n))
                return true;
        }
        return false;
    }
};



int main() {
    Solution sol;

    // ---- Hardcoded Input ----
    int n = 4;
    int m = 4;

    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {2, 4}
    };

    // ---- Function Call ----
    bool result = sol.check(n, m, edges);

    // ---- Output ----
    if (result)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}