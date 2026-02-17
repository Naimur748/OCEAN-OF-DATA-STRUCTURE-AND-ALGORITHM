#include <bits/stdc++.h>
using namespace std;

int orangeRotting(vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    //-------Step 1: All rotten orange Keep in queue---------
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(grid[i][j] == 2){
                q.push({i,j});
            }

            if(grid[i][j] == 1){
                fresh++;
            }
        }
    }


    int time = 0;

    // 4 direction (up, down, left, right)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    //--------step 2: Start BFS---------
    while(!q.empty() && fresh > 0){

        int size = q.size();

        bool rotted = false;

        for(int i = 0; i < size; i++){

            pair<int,int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            // Check around the matrix
            for(int d = 0; d < 4; d++){

                int nx = x + dx[d]; // new row
                int ny = y + dy[d]; // new column

                // boundary check + fresh orange check
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                    rotted = true;

                }
            }
        }

        if(rotted) time++;

    }

    //--------step 3: final check---------
    if(fresh == 0) return time;
    return -1;

}

int main(){

    vector<vector<int>> grid = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}

    };

    int result = orangeRotting(grid);

    cout << "Minimum Time: " << result << endl;

    return 0;
}