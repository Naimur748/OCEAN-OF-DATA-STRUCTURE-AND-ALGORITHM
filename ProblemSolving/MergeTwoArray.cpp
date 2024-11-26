#include <iostream>
using namespace std;

int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9,10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int totalSize = n1 + n2;

    int merzedArray[totalSize];


    for(int i=0; i< n1; i++){
        merzedArray[i] = arr1[i];
    }

    for(int j=0; j<n2; j++){
        merzedArray[n1+j] = arr2[j];
    }

    for(int i=0; i<totalSize; i++){
        cout<<merzedArray[i]<<" ";
    }
    return 0;
}
