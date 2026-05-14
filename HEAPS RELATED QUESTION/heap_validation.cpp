

#include <bits/stdc++.h>
using namespace std;


bool isMaxHeap(vector<int>& arr){

    int n = arr.size();

    for(int i = 0; i <= (n / 2) - 1; i++){
        
        int left = 2 * i + 1;

        int right = 2 * i + 2;

        //Left child parent
        if(left < n && arr[i] > arr[left]){
            return false;
        }

        if(right < n && arr[i] < arr[right]){
            return false;
        }

    }

    return true;
}

int main(){

    vector<int> arr = {100, 50, 80, 20, 40, 60, 70};

    //Function call
    if(isMaxHeap(arr)){
        cout << "True " << endl;
        cout << "This array is a Max Heap." << endl;

    }
    else{

        cout << "False" << endl;
        cout << "This array is Not a Max Heap." << endl;

    }

    return 0;
}