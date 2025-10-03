#include <iostream>
using namespace std;

class Solution{
    public:

    string longestPalindrome(string s){

        if(s.empty()) return "";

        int start = 0, maxLen = 1;

        for(int i=0; i<s.size(); i++){

            int l = i, r = i;

            // Odd length palindrome

            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }

            // Even length palindrom
            
            l=i; r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;

                }
                l--; r++;
            }

        }

        return s.substr(start, maxLen);
    }


};

int main(){
    
    Solution sol;
    string s;
    cout << "Enter string: ";
    getline(cin, s);  // পুরো লাইনের ইনপুট নেওয়া হচ্ছে
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;

}