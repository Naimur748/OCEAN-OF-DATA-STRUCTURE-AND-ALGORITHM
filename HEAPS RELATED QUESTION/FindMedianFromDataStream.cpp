#include <bits/stdc++.h>

using namespace std;


class MedianFinder{

    private:

        priority_queue<int> leftHeap;

        priority_queue<int, vector<int>, greater<int>> rightHeap;


    public:

        //constructor
        MedianFinder(){

        }

        void addNum(int num){

            if(leftHeap.empty() || num <= leftHeap.top()){

                leftHeap.push(num);

            }else{

                rightHeap.push(num);

            }

            if(leftHeap.size() > rightHeap.size() + 1){

                int topValue = leftHeap.top();

                leftHeap.pop();

                rightHeap.push(topValue);
            }


            if(rightHeap.size() > leftHeap.size()){

                int topValue = rightHeap.top();

                rightHeap.pop();

                leftHeap.push(topValue);
            }
        }


        double findMedian(){

            if(leftHeap.size() ==  rightHeap.size()){

                return (leftHeap.top() + rightHeap.top()) / 2.0;

            }

            return leftHeap.top();
        }
};

int main(){

    //Making object
    MedianFinder mf;

    //hardcoded input
    vector<int> nums = {1, 2, 3};

    //adding every number
    for(int num : nums){

        mf.addNum(num);

        cout <<"Inserted:" << num << endl;

        cout << "Current Median: "
            << mf.findMedian()
            << endl;

        cout << "-------------------------" << endl;


    }

    return 0;


}