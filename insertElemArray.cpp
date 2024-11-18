#include <iostream>
using namespace std;

int main(){
    
    cout<< "How many Element for Array"<<endl;

    int n , array[10], element, position;

    cin>>n;

    cout<<"Enter your array"<<endl;

    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    cout<< "Enter your Elemet"<<endl;
    cin>>element;

    cout<<"Enter your position"<<endl;
    cin>>position;

    for(int j=n; j>position; j--){
        array[j] = array[j-1];
    }

    array[position] = element;
    n++;

    for(int i=0; i<n; i++){
        cout<< array[i]<<" ";
    }
}