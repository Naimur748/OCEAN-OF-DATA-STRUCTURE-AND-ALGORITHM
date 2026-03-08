#include <bits/stdc++.h>
using namespace std;

int maxEqualSum(int s1[], int s2[], int s3[], int n1, int n2, int n3){

    //Variable to hold the total sum of the three stack
    int sum1 = 0, sum2 = 0, sum3 = 0;

    //Find the sum of stack1
    for(int i = 0; i < n1; i++)
        sum1 += s1[i];
    
    for(int i = 0; i < n2; i++)
        sum2 += s2[i];
    
    for(int i = 0; i < n3; i++)
        sum3 += s3[i];
    
    //The pointer for tracking the top index
    int top1 = 0 ,top2 = 0, top3 = 0;

    //we will run infinite loop untill we get an equal sum
    while(true){

        //if any stack become empty
        if(top1 == n1 || top2 == n2 || top3 == n3)
            return 0;
        
        //if the three sum are equal
        if(sum1 == sum2 && sum2 == sum3)
            return sum1;

        //if the sum1 is the largest
        if(sum1 >= sum2 && sum1 >= sum3){
            sum1 -= s1[top1];
            top1++;
        }
        else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 -= s2[top2];
            top2++;
        }
        else{
            sum3 -= s3[top3];
            top3++;
        }
    }

    
}

int main(){

    int s1[] = {3, 2, 1, 1, 1};
    int s2[] = {4, 3, 2};
    int s3[] = {2, 5, 4, 1};

    int n1 = sizeof(s1) / sizeof(s1[0]);
    int n2 = sizeof(s2) / sizeof(s2[0]);
    int n3 = sizeof(s3) / sizeof(s3[0]);

    // function call and keep result
    int result = maxEqualSum(s1, s2, s3, n1, n2, n3);

    // output print
    cout << "Maximum Equal Sum: " << result << endl;

    return 0;


}