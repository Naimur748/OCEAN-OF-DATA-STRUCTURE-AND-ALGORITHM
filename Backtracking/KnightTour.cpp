
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  bool checkValidGrid(vector<vector<int>>& grid){
    int n = grid.size();

    if(grid[0][0] != 0) return false;

    vector<pair<int, int>> pos(n * n);

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        pos[grid[i][j]] = {i, j};
      }
    }


    for(int i=1; i < n * n; i++){
      int x1 = pos[i -1].first;
      int y1 = pos[i - 1].second;
      int x2 = pos[i].first;
      int y2 = pos[i].second;

      int dx = abs(x1 - x2);
      int dy = abs(y1 - y2);

      if(!((dx == 2 && dy == 1)|| (dx == 1 && dy == 2))){
        return false;
      }

    }
    return true;

  }
};

int main(){

     vector<vector<int>> grid = {
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };

    Solution sol;
    bool result = sol.checkValidGrid(grid);

    if (result)
        cout << "true";
    else
        cout << "false";

    return 0;
}


