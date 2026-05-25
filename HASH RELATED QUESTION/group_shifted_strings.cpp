#include <bits/stdc++.h>
using namespace std;


string getPattern(string str){

    string pattern = "";

    for(int i = 1; i < str.length(); i++){

        int diff = str[i] - str[i - 1];

        if(diff < 0){
            diff += 26;
        }

        pattern += to_string(diff) + "#";
    }

    return pattern;
}


int main(){

    vector<string> arr = {
        "acd",
        "dfg",
        "wyz",
        "yab",
        "mop",
        "bdfh",
        "a",
        "x",
        "moqs"
    };

    unordered_map<string, vector<string>> groups;

    for(string str : arr){

        string pattern = getPattern(str);

        groups[pattern].push_back(str);



    }

    cout << "Group Shifted String : \n\n";

    for(auto group : groups){

        cout << "[" ;

        for(string str :group.second){

            cout << str << " ";
        }

        cout << "]\n";
    }

    return 0;
}