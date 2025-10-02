#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    int characterReplacement(string s, int k){

        vector<int> count(26, 0);

        int result=0, maxCount=0, left=0;

        for(int right=0; right<s.size(); right++){

            count[s[right] - 'A']++;

            maxCount = max(maxCount, count[s[right] - 'A']);

            while((right - left + 1) - maxCount > k){
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);

        }

        return result;
    }



};



int main(){

       Solution sol; 
    cout << sol.characterReplacement("ABAB", 2) << endl;      // 4
    cout << sol.characterReplacement("AABABBA", 1) << endl;   // 4

}