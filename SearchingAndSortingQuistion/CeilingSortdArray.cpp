#include <iostream>
#include <vector>
using namespace std;


/*



int ceilSearch(vector<int>& arr, int x){

    if(arr[0] <= x) return 0;

    for(int i=0; i<arr.size(); i++){

        if(arr[i] == x)
        return i;

        if(arr[i] < x && arr[i + 1] >= x) 
            return i + 1;
    }

    return -1;


}

*/


// Ceiling in a sorted array Using Binary search;

int ceilSearch(vector<int>& number, int target){

    int start = 0;
    int end = number.size() - 1;
    int ceiling = -1;

    while(start <= end){
        int middle = start + (end - start) / 2;

        if(number[middle] < target){
            start = middle + 1;

        }else{

            ceiling = middle;
            end = middle - 1;

        }
    }

    return ceiling;

}



int main(){

     vector<int> arr = {1, 2, 8, 10, 10, 12, 19}; 
    int x = 3; 
    int index = ceilSearch(arr, x); 
    if(index == -1) 
        cout << "Ceiling of " << x << " doesn't exist in array "; 
    else
        cout << "ceiling of " << x << " is " << arr[index]; 
    return 0; 

}