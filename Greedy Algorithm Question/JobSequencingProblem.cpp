#include <bits/stdc++.h>
using namespace std;

//make job structure
struct job{
    int id;
    int deadline;
    int profit;
};

//cpmparator for sorting in descending order based on profit
bool compare(job a, job b){
    return a.profit > b.profit;
}

int main(){

    int deadline[] = {4, 1, 1, 1};
    int profit[] = {20, 10, 40, 30};
    int n = 4;

    //make job vector 
    vector<job> jobs;

    //creating job object from deadline and profit
    for(int i = 0; i < n; i++){
        job j;
        j.id = i+1;
        j.deadline = deadline[i];
        j.profit = profit[i];
        jobs.push_back(j);
    }

    //job sorting based of profit
    sort(jobs.begin(), jobs.end(), compare);

    //find the maximum deadline
    int maxDeadline = 0;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    //make a slat array
    vector<int> slot(maxDeadline, -1);

    int jobCount = 0;
    int totalProfit = 0;

    //checking each job
    for(int i = 0; i < n; i++){

        for(int j = jobs[i].deadline-1; j >= 0; j--){

            //if the slot is empty
            if(slot[j] == -1){
                slot[j] = jobs[i].id;
                jobCount++;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

      // Output print
    cout<<"Total Jobs Done = "<<jobCount<<endl;
    cout<<"Maximum Profit = "<<totalProfit<<endl;


}