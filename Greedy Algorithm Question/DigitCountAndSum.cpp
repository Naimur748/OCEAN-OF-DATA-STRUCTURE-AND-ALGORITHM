#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d){

    //its not possible if sum = 0 and digit > 1
    if(s == 0){
        if(d == 1)
            return "0";
        else
            return "-1";
    }

    //it is possible if sum > max
    if(s > 9 * d )
        return "-1";
    
    vector<int> digits(d, 0); //initialize the vector of size d with all zeros

    //start filling from the right side
    for(int i = d-1; i >= 0; i--){

        //here we will take whichever is smaller nine or s
        if(s > 9){
            digits[i] = 9;
            s -= 9;
        }else{
            digits[i] = s;
            s = 0;
        }
    }

    //if the first digit is zero, it need to be fixed
    if(digits[0] == 0){
        for(int i = d-1; i >= 0; i--){

            if(digits[i] > 0){
                digits[i]--;
                digits[0] = 1;
                break;
            }
        }
    }

    //make it string
    string result = "";
    for(int i = 0; i < d; i++){
        result += (digits[i] + '0'); //convert int to char
    }

    return result;

    
}

int main(){

    int s = 20;
    int d =  3;

    //function call
    string ans = smallestNumber(s, d);

    //output print
    cout << "Smallest Number: " << ans << endl;

    return 0;
}