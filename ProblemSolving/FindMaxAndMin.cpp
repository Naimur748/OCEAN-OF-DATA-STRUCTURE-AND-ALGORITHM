#include <iostream>
using namespace std;

int main(){

    int arr[] = {3, 2, 5, 12, 44, 56, 34, 76, 88, 97, 21, 33,};

    int size = sizeof(arr) / sizeof(arr[0]);

    int max = 0;
    int min = 0;

    for(int i=0; i<size; i++){

        if(max < arr[i]){
            max = arr[i];
        }else{
            min  = arr[i];
        }
    }

    cout<<"Maximum number is : "<< max <<endl<<"Minimum number is : "<< min;
}