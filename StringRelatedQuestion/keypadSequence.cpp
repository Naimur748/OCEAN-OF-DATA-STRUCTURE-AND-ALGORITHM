#include <iostream>
using namespace std;

string printSequence(string s) {
    string arr[] = { "2","22","222","3","33","333","4","44","444",
                     "5","55","555","6","66","666","7","77","777",
                     "7777","8","88","888","9","99","999","9999" };
    string output = "";
    for(char c : s){
        if(c == ' '){
            output += "0";
        } else {
            int index = c - 'A';
            output += arr[index];
        }
    }
    return output;
}

int main(){
    cout << printSequence("GEEKSFORGEEKS") << endl;
    cout << printSequence("HELLO WORLD") << endl;
    return 0;
}
