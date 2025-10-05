#include <iostream>
using namespace std;

class Solution{
    public:

    int countSubstrings(string s){

        int n = s.size();
        int count = 0;

        auto expand = [&](int left, int right){
            
            int c = 0;
            while(left >= 0 && right < n && s[left] == s[right]){
                ++c;
                --left;
                ++right;
            }

            return c;
        };
        

        for(int i=0; i<n; i++){
            count += expand(i, i);
            count += expand(i, i+1);
        }
        return count;

    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s;

    // Example usage:
    // Input: aaa
    // Output: 6
    if (getline(cin, s)) {
        cout << sol.countSubstrings(s) << '\n';
    }
    return 0;

}