#include <iostream>
#include <vector>
using namespace std;

int main(){
     vector<int> array1 = {1, 2, 3, 4, 5};
     vector<int> array2 = {4, 5, 6, 7, 8};

     vector<int> intersection;

     for(int i=0; i<array1.size(); i++){

        bool found = false;

        for(int j=0; j<array2.size(); j++){
            if(array1[i] == array2[j]){
                found = true;
                break;
            }
            
        }

        if(found){
            intersection.push_back(array1[i]);
        }

     }

     //Print Intersecton

     for(int i=0; i<intersection.size(); i++){
        cout<<intersection[i]<<" ";
     }
    
}