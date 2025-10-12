
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string smallestWindow(const string &s, const string &p){

    int n = s.size(), m = p.size();
    if(m > n) return "";

    vector<int> need(128, 0), window(128, 0);

    for(char c : p) need[(unsigned char)c]++;

    int required = m;
    int left = 0;
    int minLen = INT_MAX;
    int minStart = 0;

    for(int right=0; right<n; right++){
        char ch = s[right];

        window[(unsigned char)ch]++;

        if(window[(unsigned char)ch] <= need[(unsigned char)ch]){
            required--;
        }

        while(required == 0){
            int winLen = right - left + 1;
            if(winLen < minLen){
                minLen = winLen;
                minStart = left;
            }

            char leftChar = s[left];
            window[(unsigned char)leftChar]--;
            if(window[(unsigned char)leftChar] < need[(unsigned char)leftChar]){
                required++;

            }

            left++;

        }

    }

    if(minLen == INT_MAX) return "";
    return s.substr(minStart, minLen);



}





int main() {
    string s = "timetopractice", p = "toc";
    cout << smallestWindow(s, p) << endl; // আশা: "toprac"
    return 0;
}