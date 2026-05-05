#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int nums[], int n){
    
    if(n == 0){
        return 0;
    }

    int i = 0;

    for(int j = 1; j < n; j++){

        if(nums[j] != nums[i]){

            i++;

            nums[i] = nums[j];

        }
    }

    return i + 1;
}

int main(){
    int nums[] = "0,0,1,1,1,2,3,3,4";

    int n = sizeof(nums) / sizeof([0]);

    int k = removeDuplicates(nums,n);

    cout << "Unique element count (k): " << k << endl;

    cout << "Array after removing duplicate: ";
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
    
    }

    return 0;
}