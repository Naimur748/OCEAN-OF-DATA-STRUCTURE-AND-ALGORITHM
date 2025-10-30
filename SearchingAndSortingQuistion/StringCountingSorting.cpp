#include <iostream>
#include <vector>
using namespace std;

string countSort(string s){

    vector<int> count(26, 0);

    for(char c : s)
        count[c - 'a']++;

    string result = "";
    for(int i = 0; i < 26; i++){
        while(count[i] > 0){
            result += (char)(i + 'a');
            count[i]--;
        }

    }

    return result;

}

int main(){

    string s = "geeksforgeeks";
    cout << countSort(s) << endl;

    return 0;
}