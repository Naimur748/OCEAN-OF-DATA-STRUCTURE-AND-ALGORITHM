#include <bits/stdc++.h>
using namespace std;

int main(){

    int n = 39;

    int count = 0;

    //Usins maximum upper coin
    count += n / 10;
    n = n % 10;

    //using 5 taka coin
    count+= n / 5;
    n = n % 5;

    //using 2 coin
    count += n / 2;
    n = n % 2;

    //1 taka coin
    count += n / 1;

    cout << "Minimum number of coin required " << count << endl;

    return 0;

}