#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool isOverlap(Interval a, Interval b){

    return (a.start <= b.end && b.start <= a.end);
}

int main(){

    vector<Interval> arr = {
        {1, 5},
        {3, 7},
        {2, 6},
        {10, 15},
        {5, 6},
        {4, 100}
    };


    int n = arr.size();

    for(int i = 0; i < n; i++){

        for(int j = 0; j < i; j++){

            if(isOverlap(arr[i], arr[j])){

                cout << "[" << arr[i].start << "," << arr[i].end << "]";

                cout << "Conflicts With";

                cout << "[" << arr[j].start << "," << arr[j].end << "]";
                cout << endl;


            }
        }
    }

    return 0;


}