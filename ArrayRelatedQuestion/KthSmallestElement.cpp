#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallest(vector<int>& arr, int k){

    priority_queue<int> maxHeap;

    for(int i=0; i<arr.size(); i++){

        maxHeap.push(arr[i]);

        if(maxHeap.size() > k){

            maxHeap.pop();
        }
    }

    return maxHeap.top();

}

int main(){

    vector<int> arr1 = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    cout << k1 << "rd smallest element is "<<kthSmallest(arr1, k1) << endl;

    vector<int> arr2 = {2, 3, 1, 20, 15};
    int k2 = 4;
    cout << k2 << "rd smallest element is "<< kthSmallest(arr2, k2) << endl;

    return 0;

}