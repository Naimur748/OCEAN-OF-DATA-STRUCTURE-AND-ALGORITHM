#include <bits/stdc++.h>
using namespace std;

int main(){

    int a = 5;
    int b = 8;

    int count = 0;

    while(a > 0 && b > 0){
        if(a == b){
            count++;
            break;
        }

        if(a > b){
            count += a / b;
            a = a % b;
        }else{

            count += b / a;
            b = b % a;
        }
    }

    cout << "Minimum number of squares: " << count << endl;

    return 0;
}