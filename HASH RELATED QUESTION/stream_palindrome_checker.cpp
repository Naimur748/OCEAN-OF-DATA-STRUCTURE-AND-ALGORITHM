#include <bits/stdc++.h>
using namespace std;

int main(){

    string stream = "abcba";

    const long long BASE = 31;

    long long forwardHash = 0;
    long long reverseHash = 0;

    long long power = 1;

    cout << "Character \tResult\n";

    for(int i = 0; i < stream.length(); i++){

        char ch = stream[i];

        long long value = ch - 'a' + 1;

        forwardHash = forwardHash * BASE + value;

        reverseHash = reverseHash + value * power;

        if(forwardHash == reverseHash){
            cout << ch << "\t\tYes\n";

        }
        else{

            cout << ch << "\t\tNo\n";
        }

        power = power * BASE;
    }

    return 0;
}