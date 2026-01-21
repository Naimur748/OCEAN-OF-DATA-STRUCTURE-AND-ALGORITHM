#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> mat;

vector<vector<bool>> visited;

vector<pair<int, int>> path;

int midX, midY;

void dfs(int x, int y){

    if(x < 0 || y < 0 || x >= n || y >= n)
        return;

    if(visited[x][y])
        return;
    
    path.push_back({x, y});
    visited[x][y] = true;

    if(x == midX && y == midY){

        for(auto p : path)
            cout << "(" << p.first << ", " << p.second << ") ";
        cout << endl;

        visited[x][y] = false;
        path.pop_back();
        return;

    }

    int jump = mat[x][y];

    if(jump > 0){

        dfs(x - jump, y);
        dfs(x + jump, y);
        dfs(x, y + jump);
        dfs(x, y - jump);

    }

    visited[x][y] = false;
    path.pop_back();


};


int main() {

    mat = {
        {3,5,4,4,7,3,4,6,3},
        {6,7,5,6,6,2,6,6,2},
        {3,3,4,3,2,5,4,7,2},
        {6,5,5,1,2,3,6,5,6},
        {3,3,4,3,0,1,4,3,4},
        {3,5,4,3,2,2,3,3,5},
        {3,5,4,3,2,6,4,4,3},
        {3,5,1,3,7,5,3,6,4},
        {6,2,4,3,4,5,4,5,1}
    };

    n = mat.size();

    // middle cell নির্ধারণ
    midX = n / 2;
    midY = n / 2;

    // visited array initialize
    visited.assign(n, vector<bool>(n, false));

    cout << "Paths from Top-Left corner:\n";
    dfs(0, 0);

    return 0;
}