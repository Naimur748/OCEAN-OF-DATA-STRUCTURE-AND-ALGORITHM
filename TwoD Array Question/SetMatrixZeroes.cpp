#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

    void setZeroes(vector<vector<int>>& matrix){

        if(matrix.empty()) return ;

        int m = matrix.size();
        int n = matrix[0].size();

        // Check if first row has any Zero
        bool row0_has_zero = false;
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0){
                row0_has_zero = true;
                break;
            }
        }



        //Check if first column has any zer0;
        bool col0_has_zero = false;
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                col0_has_zero = true;
                break;
            }

        }


        //Use first row and first column as markers
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


        // Zero out cells based on markers (except first row / col)
        for(int i=1; i<m; i++){
            for(int j=1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        //Finally zero out first row if needed
        if(row0_has_zero){
            for(int j =0; j<n; j++) matrix[0][j] = 0;
        }

        // Finally zero out  first column if needed
        if(col0_has_zero){
            for(int i=0; i<m; i++) matrix[i][0] = 0;
        }


    }
};



int main(){
    Solution sol;

    vector<vector<int>> matrix = {{0 ,1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    sol.setZeroes(matrix);

    for(auto &row : matrix){
        for(int v : row) cout << v << ' ';
        cout << '\n';
    }

    return 0;
}