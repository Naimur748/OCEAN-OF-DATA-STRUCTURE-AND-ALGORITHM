#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {4, 2, 1, 8};

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> result;

    int left = 0;
    int right = n-1;

    // Step 2: zig-zag ভাবে array সাজানো
    while(left < right){
        result.push_back(arr[left]);
        result.push_back(arr[right]);
        left++;
        right--;
    }


    // যদি element সংখ্যা odd হয় তাহলে মাঝের element যোগ করতে হবে
    if(left == right){
        result.push_back(arr[left]);
    }

    int sum = 0;
    //sum the result vector all value consecutive difference sum
    for(int i = 0; i < n - 1; i++){
        sum += abs(result[i] - result[i + 1]);
    }

    //circular condition(last element + first element)
    sum += abs(result[n-1] - result[0]);

    //show the output result
    cout << "Maximum Sum: " << sum << endl;

    //show the rearrange array
    cout << "Rearranged Array: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;

}