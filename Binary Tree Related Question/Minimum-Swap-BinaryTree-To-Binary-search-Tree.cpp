#include <bits/stdc++.h>
using namespace std;

//functional for inorder traversal
void inorder(int i, vector<int>& arr, vector<int>& in){

   
    if(i >= arr.size()) return;

    //Left subtree
    inorder(2*i + 1, arr, in);

    //Adding the root node
    in.push_back(arr[i]);

    //Right subtree
    inorder(2*i + 2, arr, in); 

}

//function for minimum swap
int minSwaps(vector<int>& nums){
    int n = nums.size();

    //making pair value + orginal index
    vector<pair<int, int>> temp(n);

    for(int i = 0; i < n; i++){
        temp[i] = {nums[i], i};
    }

    //soritng according to value
    sort(temp.begin(), temp.end());

    //visited array
    vector<bool> visited(n, false);

    int swaps = 0;

    for(int i = 0; i < n; i++){

        if(visited[i] == true || temp[i].second == i)
            continue;
        
        int cycle_size = 0;
        int j = i;

        while(!visited[j]){
            visited[j] = true;

            j = temp[j].second;
            cycle_size++;
            
        }

        if(cycle_size > 1){
            swaps += (cycle_size - 1);
        }
    }
    return swaps;
}



int main(){

    //Hardcoded input
    vector<int> arr = {5, 6, 7, 8, 9, 10, 11};

    //vector for inorder traversal
    vector<int> inorderArr;

    //finding inorder
    inorder(0, arr, inorderArr);

    //calculating the minimum swap
    int result = minSwaps(inorderArr);

    //output print
    cout << "Minimum swaps required: " << result << endl;

    return 0;
}