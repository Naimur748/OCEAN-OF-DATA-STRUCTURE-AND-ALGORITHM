#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3){

    map<int, int> mp;

    for(int ele : arr1){
        mp[ele] = 1;
    }

    for(int ele : arr2){
        if(mp.find(ele) != mp.end() && mp[ele] == 1)
        mp[ele] = 2;
    }

    for(int ele : arr3){
        if(mp.find(ele) != mp.end() && mp[ele] == 2)
        mp[ele] = 3;
    }

    vector<int> commonElements;
    for(auto ele : mp){

        if(ele.second == 3)
         commonElements.push_back(ele.first);
    
    }

    return commonElements;

}

int main(){

    vector<int> arr1 = {1, 5, 10, 20, 30};
    vector<int> arr2 = {5, 13, 15, 20};
    vector<int> arr3 = {5, 20};

    vector<int> common = commonElements(arr1, arr2, arr3);

    if(common.size() == 0)
    cout << -1;

    for(int i = 0; i < common.size(); i++){
        cout << common[i] << " ";
    }

    return 0;



}