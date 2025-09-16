#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// bool compareForLargestNumber(const string &plateA, const string &plateB){

//     return plateA + plateB > plateB + plateA;
// }


// string createLargestDisplayNumber(vector<int>& carNumber){

//     vector<string> numberPlates;
//     numberPlates.reserve(carNumber.size());

//     for(int number : carNumber){
//         numberPlates.push_back(to_string(number));
//     }

//     sort(numberPlates.begin(), numberPlates.end(), compareForLargestNumber);

//     if(numberPlates[0] == "0") return "0";

//     string largestDisplayNumber;
//     for(const string &plate : numberPlates){
//         largestDisplayNumber += plate;
//     }

//     return largestDisplayNumber; 

// }




// bool compareForLargestNumber(const string &plateA, const string &plateB){

//     return plateA + plateB > plateB + plateA;
// }




// string createLargestDisplayNumber(vector<int>& carNumber){

//     vector<string> numberPlate;
//     numberPlate.reserve(carNumber.size());

//     for(int number : carNumber){
//         numberPlate.push_back(to_string(number));
//     }

//     sort(numberPlate.begin(), numberPlate.end(), compareForLargestNumber);
//      if (numberPlate[0] == "0") return "0";

//     string largestNumber;
//     for(const string &plate : numberPlate){

//         largestNumber += plate;

//     }

//     return largestNumber;


// }







string createLargestDisplayNumber(vector<int>& carNumber){

    vector<string> nums;

    for(int n : carNumber){
        nums.push_back(to_string(n));

    }

    sort(nums.begin(), nums.end(), [](string &a, string &b){
        return a + b > b + a;

    });

    if(nums[0] == "0") return "0";

    string result;
    for(string &s :nums){
        result += s;
    }

    return result;
}






int main(){

    vector<int> carNumbers = {54, 546, 548, 60};

    string vipDisplay = createLargestDisplayNumber(carNumbers);

    cout << "VIP Display Number: " << vipDisplay << endl;
    // Output হবে: 6054854654

    return 0;

}