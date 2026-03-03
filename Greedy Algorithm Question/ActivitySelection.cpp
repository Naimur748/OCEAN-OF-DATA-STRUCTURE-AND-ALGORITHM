#include <bits/stdc++.h>
using namespace std;

int main(){

    // --------- Hardcoded Input Section ------------
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    int n = start.size();

    // pair vector তৈরি (finish time আগে রাখছি sorting সহজ করার জন্য)
    vector<pair<int, int>> activities;

    for(int i = 0; i<n; i++){
        activities.push_back({finish[i], start[i]});
        // {finish, start} হিসেবে রাখলাম যাতে finish অনুযায়ী sort হয়
    }

    sort(activities.begin(), activities.end());
     // finish time ascending order এ sort

    int count = 1;
    int lastFinish = activities[0].first;

    for(int i = 1; i < n; i++){
        
        int currentStart = activities[i].second;
        int currentFinish = activities[i].first;

        if(currentStart > lastFinish){
            count++;
            lastFinish = currentFinish;
        }
    }

    cout << "Maximum activities = " << count << endl;

    return 0;
}