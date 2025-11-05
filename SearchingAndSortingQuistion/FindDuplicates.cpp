#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*


vector<int> findDuplicates(vector<int>& arr){

    int n = arr.size();

    unordered_map<int, int> freqMap;
    vector<int> result;

    for(int i = 0; i < n; i++){
        freqMap[arr[i]]++;
    }

    for(auto &entry : freqMap){
        if(entry.second > 1){
            result.push_back(entry.first);
        }
    }

    if(result.empty()){
        result.push_back(-1);
    }

    return result;

}

*/

vector<int> findDuplicates(vector<int>& arr){

    int n = arr.size();

    vector<int> freqMap(n);
    vector<int> result;

    for(int i = 0; i < n; i++){
        freqMap[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(freqMap[i] > 1){
            result.push_back(i);
        }
    }

    if(result.empty()){
        result.push_back(-1);
    }

    return result;
}



int main() {
    vector<int> arr = {1, 6, 5, 2, 3, 3, 2};

    vector<int> duplicates = findDuplicates(arr);

    for (int element : duplicates) {
        cout << element << " ";
    }

    return 0;
}