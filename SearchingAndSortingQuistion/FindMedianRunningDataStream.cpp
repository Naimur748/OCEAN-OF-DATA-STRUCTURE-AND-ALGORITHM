#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> findMedians(vector<int>& arr){
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right; 

    vector<double> medians;

    for(int num : arr){

        if(left.empty() || num <= left.top()){
            left.push(num);
        }else{
            right.push(num);

        }

        // step 2 : Heap balance
        if((int)left.size() > (int)right.size() + 1){
            right.push(left.top());
            left.pop();

        }else if((int)right.size() > left.size() + 1){

            left.push(right.top());
            right.pop();

        }

        // step 3: Find median
        double median;
        if(left.size() == right.size()){
            median = (left.top() + right.top()) / 2.0;

        }else if(left.size() > right.size()){
            median = left.top();
        }else{
            
            median = right.top();
        }

        medians.push_back(median);

    }

    return medians;
}



int main(){

    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> result = findMedians(arr);

    cout << fixed << setprecision(2);
    cout << "Medians after each insertion: ";

    for(double m : result){
        cout << m << " ";
    }

    cout << endl;

    return 0;
}