#include <iostream>
#include <vector>
using namespace std;

bool pairInSortedRotated(vector<int>& arr, int target){
    int n = (int) arr.size();

    if(n < 2) return false;

    int pivot = -1;

    for(int i=0; i<n-1; ++i){
        if(arr[i] > arr[i+1]){
            pivot = i;
            break;
        }
    }

if(pivot == -1) pivot = n-1;

int left = (pivot + 1) % n;
int right = pivot;

while(left != right){

    int sum = arr[left] + arr[right];

    if(sum == target) return true;

    if(sum < target){

        left = (left + 1) % n;

    }else{

        right = (n + right -1) % n;

    }
    
}

return false;
}

int main(){

    vector<int> arr1 = {11, 15, 6, 8, 9, 10};
    int target1 = 16;
    cout<< (pairInSortedRotated(arr1, target1) ? "true" : "false")<<'\n';

    return 0;
}