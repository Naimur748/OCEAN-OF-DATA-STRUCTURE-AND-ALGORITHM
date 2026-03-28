
#include <bits/stdc++.h>
using namespace std;

//this function checks whether the task is possible within the given mid time
bool isPossible(vector<int>& job, int k, int mid){

    int worker = 1;
    int curr_sum = 0;

    for(int i = 0; i < job.size(); i++){

        //if adding a job exceed the mid limit
        if(curr_sum + job[i] > mid){
            worker++;
            curr_sum = job[i];

            //if worker count exceed k its not possible
            if(worker > k) return false;
        }else{

            curr_sum += job[i];

        }

    }

    return true;
}

int main(){

    vector<int> job = {10, 7, 8, 12, 6, 8};

    int k = 4;
    int t = 5;

    //low = max element
    int low = *max_element(job.begin(), job.end());

    //high = sum of all jobs
    int high = accumulate(job.begin(), job.end(), 0);

    int ans = high; // initial answer

    // Binary search
    while(low <= high){

        int mid = (low + high) / 2;
        // if possible
        if(isPossible(job, k, mid)){
            ans = mid;
            high = mid - 1;

        }else{
            low = mid + 1;

        }

    }

    //final result (time * t)
    cout << "Minimum Time: " << ans * t << endl;
    
}