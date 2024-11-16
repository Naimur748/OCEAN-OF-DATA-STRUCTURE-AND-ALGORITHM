#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeatingElement(const vector<int>& arr){

    unordered_map<int, int> freq;

    for(int num : arr){
        freq[num]++;
    }

    for(int num : arr){
        if(freq[num] == 1){
            return num;
        }
    }
    return -1;
}


int main(){

    vector <int> arr = {5, 3, 4, 3, 5, 6, 4};\

    int result = firstNonRepeatingElement(arr);

    if(result != -1){
        cout<<"First non-repeating Element: "<<result <<endl;
    }else{
        cout<<"Not found Non repeating Element: "<<endl;
    }


}