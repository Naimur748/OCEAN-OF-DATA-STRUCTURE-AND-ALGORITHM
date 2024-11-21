#include <iostream>
using namespace std;

int main(){
    int n, position, array[20];

    cout<<"How many array range you need";
    cin>>n;

    cout<<"Enter you array Element";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    cout<<"Enter your position you want to delete";
    cin>>position;

    for(int i=position; i<n-1; i++){
        array[i] = array[i+1];

    }
    n--;

    cout<<"The final array is"<<endl;
    for(int i=0; i<n; i++){
        cout<< array[i]<<endl;
    }


}