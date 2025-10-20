#include <iostream>
#include <vector>
using namespace std;

vector<int> diagonalOrder(const vector<vector<int>>& mat){

    vector<int> res;

    int n = mat.size();
    int m = mat[0].size();

    for(int row=0; row<n; row++){
        int i=row, j=0;

        while(i>=0 && j<m){
            res.push_back(mat[i][j]);
            i--;
            j++;

        }
    }

    for(int col=1; col<m; col++){
        int i=n-1, j=col;
        while(i >= 0 && j<m){
            res.push_back(mat[i][j]);
            i--;
            j++;
        }
    }

    return res;
}

int main(){

    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    vector<int> res = diagonalOrder(mat);
    for(auto val : res) cout << val << " ";

    cout << endl;

    return 0;


}