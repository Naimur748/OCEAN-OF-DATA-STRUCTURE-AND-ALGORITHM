#include <iostream>
#include <vector>
using namespace std;

// vector<int> findRepeatAndMissing(const vector<int>& nums){

//     long long n = nums.size();

//     long long expectedSum = n * (n + 1) / 2;
//     long long expectedSquareSum = n * (n+1) * (2 * n+1) / 6;

//     long long actualSum = 0, actualSquareSum = 0;

//     for(int num : nums){
//         actualSum += (long long)num;
//         actualSquareSum += (long long)num * (long long)num;
//     }

//     long long diff1 = actualSum - expectedSum;
//     long long diff2 = actualSquareSum - expectedSquareSum;

//     long long sumAB = diff2 / diff1;

//     long long A = (diff1 + sumAB) / 2;
//     long long B =  A - diff1;

//     return {(int)A , (int)B};

// }






// vector<int> findRepeatAndMissing(const vector<int>& nums){

//     long long n = nums.size();

//     long long expectedSum = n * (n+1) / 2;
//     long long expectedSquareSum = n * (n+1) * (2 * n+1) / 6;

//     long long actualSum = 0, actualSquareSum = 0;
//     for(int num : nums){

//         actualSum += (long long) num;
//         actualSquareSum += (long long )num * (long long) num;

//     }

//     long long diff1 = actualSum - expectedSum;
//     long long diff2 = actualSquareSum - expectedSquareSum;

//     long long sumAB = diff2 / diff1;

//     long long A = (diff1 + sumAB) / 2 ;

//     long long B = A - diff1;

//     return {(int)A, (int)B};

// }





vector<int> findRepeatAndMissing(vector<int>& nums){

    long long n = nums.size();

    long long expectedSum = n * (n+1) / 2;
    long long expectedSquareSum = n * (n+1) * (2*n+2) / 6;

    long long actualSum = 0, actualSquareSum = 0;

    for(int num : nums){
        actualSum += (long long) num;
        actualSquareSum += (long long) num  * (long long)num;
    }

    long long diff1 = actualSum - expectedSum;
    long long diff2 = actualSquareSum - expectedSquareSum;

    long long sumAB = diff2 / diff1;

    long long A = (diff1 + sumAB) / 2;
    long long B = A - diff1;

    return {(int)A, (int)B};
}


int main(){
    vector<int> nums = {3, 1, 2, 5, 3};
    vector<int> result = findRepeatAndMissing(nums);

    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}


