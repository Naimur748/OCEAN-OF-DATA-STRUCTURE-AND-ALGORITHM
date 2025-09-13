#include <iostream>
#include <vector>
using namespace std;

void moveZerosToEnd(vector<int>& arr){

        int n = arr.size();

        int index = 0;

        for(int i=0; i<n; i++){

            if(arr[i] != 0){

                arr[index] = arr[i];

                index++;
            }
            
        }

        while(index < n){
            arr[index] = 0;
            index++;
        }
}

int main(){
    vector <int> arr = {0, 1, 0, 3, 12};

    cout<<"Main array  "<<endl;

    for(int num: arr){
        cout<< num<<" ";
    }

    cout<<endl;

    moveZerosToEnd(arr); //Function call

    for(int num: arr){
        cout<<num<<" ";
    }
    return 0;


}0
