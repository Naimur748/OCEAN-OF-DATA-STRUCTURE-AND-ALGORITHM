#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){

    int totalGas = 0;
    int totalCost = 0;
    int tank = 0;
    int start = 0;

    for(int i = 0; i < gas.size(); i++){

        totalGas += gas[i];
        totalCost += cost[i];

        tank += gas[i] - cost[i];

        if(tank < 0){
            start = i + 1;
            tank = 0;
        }
    }

    if(totalGas < totalCost) return -1;

    return start;
}


int main(){

    vector<int> gas = {4, 5, 7, 4};
    vector<int> cost = {6, 6, 3, 5};

    int result = canCompleteCircuit(gas, cost);

    cout << "Starting Station Index: " << result << endl;

    return 0;
}