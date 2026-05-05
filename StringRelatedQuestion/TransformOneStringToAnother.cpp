#include <iostream>
#include <unordered_map>
using namespace std;

int minOperations(string A, string B){

    if(A.length() != B.length())
        return -1;

    unordered_map<char, int> freq;
    
    for(char c : A) freq[c]++;
    for(char c : B) freq[c]--;

    for(auto &it : freq)
        if( it.second != 0)
           return -1;

    int i = A.length() - 1;
    int j = B.length() - 1;
    int res = 0;

    while(i >= 0){

        if(A[i] == B[j]){

            j--;

        }else{

            res++;

        }

        i--;
    }
    return res;

}

int main(){

    string A = "EACBD";
    string B = "EABCD";
    cout << minOperations(A, B) << endl;
    return 0;
}