// #include <iostream>
// using namespace std;

// int main(){

//     int arr[] = {4, 6, 8, 9, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     for( int i=n-1; i>=0; i--){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main(){

//     int arr[] = {3, 7, 5, 2, 8, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     for(int i=n-1; i >= 0; i--){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }



#include <iostream>
using namespace std;


int main(){

    int arr[] = {4, 5, 7, 2, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=n-1; i>=0; i--){
        cout<<arr[i]<<" ";
    }

    return 0;
}


