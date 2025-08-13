#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& num){

    int startIndex = 0;
    int endIndex = num.size() - 1;

    while(startIndex < endIndex){

        int midIndex = startIndex + (endIndex - startIndex) / 2 ;

        if(num[midIndex] > num[endIndex]){

            startIndex = midIndex + 1;

        }else{

            endIndex = midIndex;
        }

    }

    return num[startIndex];
}


int main(){

    vector<int> num1  = {3, 4, 5, 1, 2};
    vector<int> num2 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> num3 = {11, 13, 15, 17};

    cout<< "Minumum of nums1: " << findMin(num1) << endl;
    cout<< "Minimum of num2: " << findMin(num2) << endl;
    cout<< "Minimum of num3: " << findMin(num3) << endl;

    return 0;
}