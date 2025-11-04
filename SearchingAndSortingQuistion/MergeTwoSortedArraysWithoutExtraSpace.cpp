#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b){

    for(int i = b.size() - 1; i >= 0; i--){

        if(a.back() > b[i]){

            int last = a.back();
            int j = a.size() - 2;

            while(j >= 0 && a[j] > b[i]){
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = b[i];
            b[i] = last;
            
        }

    }
}




int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele: a)
        cout << ele << " ";
    cout << "\n";
    for (int ele: b)
        cout << ele << " ";
    return 0;
}