#include <bits/stdc++.h>
using namespace std;


int n, m;
int ans = INT_MAX;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool isValid(int x, int y,
            vector<vector<int>>& mat,
            vector<vector<bool>>& visited){

                if(x < 0 || y < 0 || x >= n || y >= m)
                    return false;

                if(mat[x][y] == 0)
                    return false;

                if(visited[x][y] == true)
                    return false;

                return true;

}


void dfs(int x, int y, int dist,
        vector<vector<int>>& mat,
        vector<vector<bool>>& visited){

            if(y == m - 1){
                ans = min(ans, dist);
                return;
            }

            visited[x][y] = true;

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(isValid(nx, ny, mat, visited)){
                    dfs(nx,ny, dist+1, mat, visited);
                }
            }
            visited[x][y] = false;
}



int shortestSafePath(vector<vector<int>>& mat){
    n = mat.size();
    m = mat[0].size();

    vector<vector<int>> safe = mat;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(mat[i][j] == 0){
                for(int k = 0; k < 4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && nj >= 0 && ni < n && nj < m){
                        safe[ni][nj] = 0;
                    }
                }
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        if(safe[i][0] == 1){
            dfs(i, 0, 0, safe, visited);
        }
    }

    if(ans == INT_MAX)
        return -1;

        return ans;
}



int main() {

    vector<vector<int>> mat = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    int result = shortestSafePath(mat);

    cout << "Shortest Safe Path Length: " << result << endl;

    return 0;
}