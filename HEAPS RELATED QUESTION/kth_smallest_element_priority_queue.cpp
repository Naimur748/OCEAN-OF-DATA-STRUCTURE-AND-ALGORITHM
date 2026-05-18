#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};

    int k =  4;

    priority_queue<int> maxHeap;

    for(int num : arr){

        maxHeap.push(num);

        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }

    cout << "K-th Smalllest Element: " << maxHeap.top() << endl;

    return 0;
}