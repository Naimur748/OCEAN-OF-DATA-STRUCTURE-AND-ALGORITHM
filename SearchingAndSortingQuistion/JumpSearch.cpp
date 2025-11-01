#include <iostream>
#include <vector>
using namespace std;

int searchInStepArray(const vector<int>& arr, int k, int x){

 int n  =  arr.size();
 int i = 0;

 while(i < n){
     if(arr[i] == x) return i;
    
     int diff = abs(arr[i] -  x);

     int step = 1;
     if(k > 0){
         step = (diff + k -1) / k;

         if(step < 1) step = 1;
      }

      i += step;

    }

   return -1;


}


int main(){

     // Example 1
    vector<int> arr1 = {4, 5, 6, 7, 6};
    int k1 = 1, x1 = 6;
    cout << "Index of " << x1 << " is " << searchInStepArray(arr1, k1, x1) << "\n"; // expected 2

    // Example 2
    vector<int> arr2 = {20, 40, 50, 70, 70, 60};
    int k2 = 20, x2 = 60;
    cout << "Index of " << x2 << " is " << searchInStepArray(arr2, k2, x2) << "\n"; // expected 5

    return 0;
}