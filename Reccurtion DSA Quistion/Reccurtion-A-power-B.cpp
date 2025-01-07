#include <iostream>
using namespace std;

int findPower(int b, int p){


    if(p == 0) return 1;


   return b * findPower(b, p-1);
}

int main(){

    int b, p;
    cout<<"Enter you Base: ";
    cin>>b;

    cout<<"Eenter your Power: ";
    cin>>p;

    int ans = findPower(b, p);

    cout<<"Ans is: "<<ans;
    

    return 0;


}