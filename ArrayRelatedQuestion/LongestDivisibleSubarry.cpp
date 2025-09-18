#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// int longestDivisibleSubarray(vector<int> &expenses, int friends){
//     unordered_map<int, int> firstOccurrence;
//     firstOccurrence[0] = -1;

//     long long cumulativeSum = 0;
//     int maxDays = 0;

//     for(int day=0; day<expenses.size(); day++){
//         cumulativeSum += expenses[day];

//         int remainder = (int)((cumulativeSum % friends + friends) % friends);

//         if(!firstOccurrence.count(remainder)){
//             firstOccurrence[remainder] = day;
//         }else{
//             int length = day - firstOccurrence[remainder];
//             maxDays = max(maxDays, length);
//         }
//     }

//     return maxDays;


// }




int longestSubarray(vector<int> &arr, int k){

    int maxLength = 0;
// Updated version - testing git commit

    for(int start=0; start<arr.size(); start++){

        int sum = 0;

        for(int end=start; end<arr.size(); end++){
            
            sum = (sum + arr[end]) % k;

            if(sum == 0){
                int length = end - start + 1;
                maxLength = max(maxLength, length);
            }


        }
    }

    return maxLength;
}







int main(){

    vector<int> expenses = {2, 7, 6, 1, 4, 5};
    int friends = 3;

    int result = longestSubarray(expenses, friends);
    cout << "Maximum number of days expenses can be equally divided among friends: "
         << result << endl;
    return 0;

}
