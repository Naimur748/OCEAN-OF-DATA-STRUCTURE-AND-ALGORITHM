#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {40, 100, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    int current_width = 0;
    int current_count = 0;

    int next_width = 0;
    int next_count = 0;

    int height = 0;

    for(int i = 0; i < n; i++){
       
        next_width += arr[i];
        next_count++;
        
        if(next_width > current_width && next_count > current_count){

            height++;

            current_width = next_width;
            current_count = next_count;

            next_width = 0;
            next_count = 0;
        }
    }

    cout << "Maximum Height of Pyramid: " << height << endl;

    return 0;
}