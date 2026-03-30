#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "aaabc";

    //the array for count frequency
    vector<int> freq(26, 0);

    //frequency count for all character
    for(char c : s){
        freq[c - 'a']++;
    }

    //Max Heap (pair: frequency, character)
    priority_queue<pair<int, char>> pq;

    //inserting a character int heap
    for(int i = 0; i < 26; i++){
        if(freq[i] > 0){
            pq.push({freq[i], char(i + 'a')}); // frequency + character

        }

    }

    string result = "";

    //As long as there are two or more elements in the heap
    while(pq.size() >= 2){

        //finding the character with the highest frequency
        auto first = pq.top(); pq.pop();
        auto second = pq.top(); pq.pop();

        //add the result
        result += first.second;
        result += second.second;

        //reduce the frequency
        first.first--;
        second.first--;

        //if there are still remaining insert back into the heap
        if(first.first > 0){
            pq.push(first);
        }

        if(second.first > 0){
            pq.push(second);
        }

    }

    //if one character remaining at the end
    if(!pq.empty()){
        auto last = pq.top(); pq.pop();

        //if the frequency is greater than one, then impossible
        if(last.first > 1){
            cout << "" << endl;
            return 0;
        }

        //Otherwise, add it to the result
        result += last.second;
    }

    cout << result << endl;


}