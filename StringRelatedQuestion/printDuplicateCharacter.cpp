#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void printDuplicates(string s){

    unordered_map<char, int> freq;

    for(char c : s){
        freq[c]++;
    }

    unordered_map<char, bool> printed;

    for(char c : s){

        if(freq[c] > 1 && !printed[c]){

            cout << "['" << c << "', " << freq[c] << "] ";

            printed[c] = true;

        }

    }
    cout << endl;
}

int main(){
     string s1 = "geeksforgeeks";
    string s2 = "programming";
    string s3 = "mississippi";

    cout << "Input: " << s1 << "\nOutput: ";
    printDuplicates(s1);

    cout << "Input: " << s2 << "\nOutput: ";
    printDuplicates(s2);

    cout << "Input: " << s3 << "\nOutput: ";
    printDuplicates(s3);

    return 0;
}