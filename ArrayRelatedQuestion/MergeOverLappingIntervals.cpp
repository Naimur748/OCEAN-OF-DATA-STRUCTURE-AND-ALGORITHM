#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// vector<vector<int>> mergeIntervals(vector<vector<int>>& arr){
//     if(arr.empty()) return {};


//     sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){

//         if(a[0] != b[0]) return a[0] < b[0];
//         return a[1] < b[1];

//     });

//     vector<vector<int>> merged;
//     merged.push_back(arr[0]);

//     for(size_t i=1; i<arr.size(); ++i){
        
//         auto& last = merged.back();
//         const auto& curr = arr[i];

//         if(curr[0] <= last[1]){
//             last[1] = max(last[1], curr[1]);

//         }else{
//             merged.push_back(curr);
//         }
//     }

//     return merged;

// }





// vector<vector<int>> mergedIntervals(vector<vector<int>>& arr){

//     if(arr.empty()) return {};

// sort(arr.begin(), arr.end(), [](const vector<int>& a, vector<int>& b){

//     if(a[0] != b[0]) return a[0] < b[0];
//     return a[1] < b[1];

// });

// vector<vector<int>> merged;
// merged.push_back(arr[0]);

// for(size_t i=1; i<arr.size(); ++i){

//     auto& last = merged.back();
//     const auto& curr = arr[i];

//     if(last[1] <= curr[1]){

//         last[1] = curr[1];

//     }else{
//         merged.push_back(curr);
//     }
// }

// return merged;


// }








// int main(){

//     vector<vector<int>> a1 = {{1,3}, {2,4}, {6,8}, {9,10}};
//     vector<vector<int> res1 = mergeIntervals(a1);

//     vector<vector<int>> a2 = {{7,8}, {1,5},{2,4}, {4,6}};
//     vector<vector<int> res2 = mergeIntervals(a2);
// }




vector<vector<int>> mergeOverlap(vector<vector<int>>& arr){

    if(arr.empty()) return {};

    sort(arr.begin(), arr.end());

    vector<vector<int>> result;
    result.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++){

        if(arr[i][0] <= result.back()[1]){

            result.back()[1] = max(result.back()[1], arr[i][1]);

        }else{

            result.push_back(arr[i]);
        }

    }

    return result;
}


int main() {
   
vector<vector<int>> arr1 = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};

    vector<vector<int>> result = mergeOverlap(arr1);

    cout << "Output: ";
    for (auto &v : result) {
        cout << "[" << v[0] << ", " << v[1] << "] ";
    }
    cout << endl;

    return 0;

    
}