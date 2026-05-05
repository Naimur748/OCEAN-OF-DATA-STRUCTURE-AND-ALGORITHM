#include <iostream>
using namespace std;


int main(){
    Solution ob;

    cout << ob.lps("abab") << endl;
    cout << ob.lps("aabcdaabc") << endl;
    cout << ob.lps("aaaa") << endl;

    return 0;
}