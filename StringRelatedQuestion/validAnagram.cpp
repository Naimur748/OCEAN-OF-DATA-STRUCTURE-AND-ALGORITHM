#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;


bool isAnagram(string &s, string &t){

    if(s.size() != t.size()) return false;


    array<int, 26> count{};

    for(size_t i=0; i<s.size(); i++){
        
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for(int c : count){
        if(c != 0) return false;
    }

    return true;

}




    int main() {
    
        vector<pair<string, string>> tests = {
            {"anagram", "nagaram"},
            {"rat", "car"},
            {"aaaa", "aaaa"},
            {"abc", "ab"}
        };

        for(auto &p : tests){
            cout<<'"' << p.first << "\", \""  <<  p.second << "\"  -> "
            << (isAnagram(p.first, p.second) ? "true" : "false") << '\n';
        }



        return 0;
}