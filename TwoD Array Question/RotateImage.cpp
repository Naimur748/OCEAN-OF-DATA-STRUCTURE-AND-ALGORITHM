#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:

    void rotate(vector<vector<int>>& matrix){

        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }


        for(int j=0; j<n; j++){

            int start = 0, end = n-1;
            while(start < end){
                swap(matrix[j][start], matrix[j][end]);
                start++, end--;
            }
        }

    }
};

int main(){

    vector<vector<int>> mat = 
    {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

    Solution().rotate(mat);

    for(auto &row : mat){
        for(int x : row) cout << x << " ";
        cout << " \n";
    }
    return 0;
}