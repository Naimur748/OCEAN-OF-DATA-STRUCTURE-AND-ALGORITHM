#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query{
    int L, R, idx;

};

int BLOCK;

bool compare(Query a, Query b){

    if(a.L / BLOCK != b.L / BLOCK)
        return a.L / BLOCK < b.L / BLOCK;
    return a.R < b.R;


}

int main(){

    int n = 9;

    int arr[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};

    int q = 3;

    Query queries[q] = {{0, 4, 0}, {1, 3, 1}, {2, 4, 2}};

    BLOCK = (int) sqrt(n);

    sort(queries, queries + q, compare);

    int currL = 0, currR = 0;
    int currSum = 0; 

    vector<int> ans(q);

    for(int i=0; i<q; i++){

        int L = queries[i].L;
        int R = queries[i].R;

        while(currR <= R){
            currSum += arr[currR];
            currR++;
        }

        while(currR > R+1){
            currR--;
            currSum -= arr[currR];
        }

        while(currL > L){
            currL--;
            currSum += arr[currL];
        }

        while(currL < L){
            currSum -= arr[currL];
            currL++;
        }

        ans[queries[i].idx] = currSum;
    }

     for (int i = 0; i < q; i++) {
        cout << "Sum of arr[" << queries[i].L 
             << ".." << queries[i].R << "] = " 
             << ans[i] << endl;
    }
    
    return 0;


    
}