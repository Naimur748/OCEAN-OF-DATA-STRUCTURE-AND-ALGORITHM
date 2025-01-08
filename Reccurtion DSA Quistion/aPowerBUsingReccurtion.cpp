// https://chatgpt.com/c/677d0462-bbb8-800e-98e7-eaeec93abc46

#include <iostream>
using namespace std;

double calculateLoan(double principal, double rate, int year){
        if(year == 0){
            return principal;
        }

        return (1 + rate) * calculateLoan(principal, rate, year - 1);
}

int main(){

    double principal = 1000;
    double rate = 0.05;
    int year = 3;

    double finalAmount = calculateLoan(principal, rate, year);

    cout<<"After" <<year<<"years, the total loan amount is: "<<finalAmount<<endl;

    return 0;
}