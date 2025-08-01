#include <iostream>
#include <unordered_set>
using namespace std;

int main(){

    int arr[] = {2, 4, 6, 1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_set<int> seen;

    bool isduplicate = false;

    for(int i=0; i<n; i++){
        if(seen.count(arr[i])){
            isduplicate = true;
            break;
        }
        seen.insert(arr[i]);   
    }

    if(isduplicate){

        cout<<"True"<<endl;

    }else{

        cout<<"False"<<endl;

    }
    
    return 0;
}


