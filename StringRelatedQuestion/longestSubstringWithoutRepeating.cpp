#include <iostream>
#include <unordered_set>
using namespace std;


int lengthOfLongestSubstring(string &s){

    unordered_set<char> charSet;
    int left = 0, maxLength = 0;

    for(int right=0; right<s.size(); right++){

        while(charSet.find(s[right]) != charSet.end()){
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);

    }

    return maxLength;
}

int main(){
      string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}