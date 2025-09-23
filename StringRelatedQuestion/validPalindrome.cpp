#include <iostream>
#include <string>
#include <vector>
using namespace std;




bool isPalindrome(const string &s){

    int i=0, j=(int)s.size() - 1;

    while(i < j){

        while(i < j && !isalnum((unsigned char)s[i])){
            i++;
        }

        while(i < j && !isalnum((unsigned char)s[j])){
            j--;
        }


        if(tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])){
            return false;
        }

        i++;
        j--;



    }

    return true;

}



int main() {
    vector<string> tests = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " "
    };

    for (auto &s : tests) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: " << (isPalindrome(s) ? "true" : "false") << "\n\n";
    }

    return 0;
}