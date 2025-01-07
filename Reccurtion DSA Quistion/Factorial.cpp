#include <iostream>
using namespace std;

/*

int factorial(int n){

    if(n==1 || n==0) return 1;
    
    int recAns = n * factorial(n-1);
    return recAns;
}

int main(){
    int n;
    cout<<"Enter a number: "<<endl;

    cin>>n;

    int fact = factorial(n);

    cout<<fact<<endl;

return 0;
}

*/


//Print sum 1 to n using reccurtion
void sumOfReccurtion(int n, int s){

    if(n == 0){
        cout<<s<<endl;
    }

    sumOfReccurtion(n-1, s+n);
    return;

}

int main(){
    int n;
    cout<<"Enter any numner: ";
    cin>>n;

    sumOfReccurtion(n, 0);

return 0;

}