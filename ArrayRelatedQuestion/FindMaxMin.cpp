// #include <iostream>
// using namespace std;

// void findMaxMin(int arr[], int n){

//     int max = arr[0];
//     int min = arr[0];

//     for(int i=1; i<n; i++){
//         if(arr[i] > max){
//             max = arr[i];
//         }

//         if(arr[i] < min){
//             min = arr[i];
//         }
//     }

//     cout<<"Maximum:"<<max<<endl;
//     cout<<"Minimum:"<<min<<endl;


// }

// int main(){
//     int arr[] = {5, 7, 2, 9, 1, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     findMaxMin(arr, n);

//     return 0;
// }




// #include <iostream>
// using namespace std;

// void findMinMax(int arr[], int n){

//     int max = arr[0];
//     int min = arr[0];


//     for(int i=1; i<n; i++){
//         if(arr[i] > max){
//             max = arr[i];
//         }

//         if(arr[i] < min){
//             min = arr[i];
//         }
//     }

//     cout<<"Maximum number is:" <<max<<endl;
//     cout<<"Minimum number is: "<<min<<endl;



// }

// int main(){

//     int arr[] = {3, 4, 9, 2, 6, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     findMinMax(arr, n);

//     return 0;
// }


#include <iostream>
using namespace std;

void findMaxMin(int arr[], int n){

    int max = arr[0];
    int min = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }

        if(arr[i] < min){
            min = arr[i];
        }
    }

    cout<<"Maximum is:"<<max<<endl;
    cout<<"Mimimum is:"<<min<<endl;
}

int main(){
    
    int arr[] = {3, 6, 2, 8, 4, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMaxMin(arr, n);

    return 0;

}