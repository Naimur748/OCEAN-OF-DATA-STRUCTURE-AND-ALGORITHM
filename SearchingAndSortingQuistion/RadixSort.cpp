#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// Function Get Max Value.
int getMaxValue(const vector<int>& numbers){

    int maxValue = numbers[0];

    for(int num : numbers){

        if(num > maxValue){
             maxValue = num;
        }        
    }
    return maxValue;
};


// Function Counting sort by digit.
void countingSortByDigit(vector<int>& numbers, int digitPlace){

    int size = numbers.size();
    vector<int> sortedNumbers(size);
    vector<int> count(10, 0);

    for(int num : numbers){
        int digit = (num / digitPlace) % 10;
        count[digit]++;
    }


    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }


    for(int i = size - 1; i >= 0; i--){
        int digit = (numbers[i] / digitPlace) % 10;
        sortedNumbers[count[digit] - 1] = numbers[i];
        count[digit]--;
    }

    //Sorted array copy in main array.
    for(int i = 0; i < size; i++){
        numbers[i] = sortedNumbers[i];
    }


};


// Function: rsdixSort().
// Counting sort according to digit.

void radixSort(vector<int>& numbers){
    int maxValue = getMaxValue(numbers);

    for(int digitPlace = 1; maxValue / digitPlace > 0; digitPlace *= 10){
        countingSortByDigit(numbers, digitPlace);
    }
}


int main() {
    vector<int> numbers = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Main array ";
    for (int num : numbers)
        cout << num << " ";
    cout << endl;

    radixSort(numbers);

    cout << "Sorted array(Ascending Order): ";
    for (int num : numbers)
        cout << num << " ";
    cout << endl;

    return 0;
}