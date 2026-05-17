#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(){

    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};

    int k = 3;

    priority_queue<int , vector<int>, greater<int>> minHeap;

    for(int i = 0; i < arr.size(); i++){

        if(minHeap.size() < k){

            minHeap.push(arr[i]);
        }
        else{

            if(arr[i] > minHeap.top()){

                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
    }


    vector<int> result;

    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    reverse(result.begin(), result.end());

    cout << "K Largest Element: ";

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    return 0;
}