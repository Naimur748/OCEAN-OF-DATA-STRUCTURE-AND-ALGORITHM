#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix){

    if(matrix.empty()) return {};

    int m = matrix.size();
    int n = matrix[0].size();


    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    vector<int> result;
    result.reserve(m * n);

    while(top <= bottom && left <= right){
        
        // 1) Top row: left -> right
        for(int j=left; j <= right; j++)
        result.push_back(matrix[top][j]);
            ++top;
        
        //2) Right colum: top -> bottop
        for(int i=top; i <= bottom; i++)
        result.push_back(matrix[i][right]);
        --right;

        // 3) Bottom row: right -> left (only if still valid row)
        if(top <= bottom){
            for(int j=right; j>0; --j)
            result.push_back(matrix[bottom][j]);
            --bottom;
        }

        // 4) Left colum: bottom -> top (only if still valid column)
        if(left <= right){
            for(int i=bottom; i>=top; --i){
                result.push_back(matrix[i][left]);
                ++left;            
            }

        }
        
    }

    return result;

}

// Helper to print vector in one line
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]";
}


int main(){

    // Example 1
    vector<vector<int>> mat1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> res1 = spiralOrder(mat1);
    printVector(res1); // Expected: [1,2,3,6,9,8,7,4,5]
    cout << "\n";

    // Example 2
    vector<vector<int>> mat2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> res2 = spiralOrder(mat2);
    printVector(res2); // Expected: [1,2,3,4,8,12,11,10,9,5,6,7]
    cout << "\n";

    return 0;
}

