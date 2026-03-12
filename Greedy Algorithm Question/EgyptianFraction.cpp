#include <bits/stdc++.h>
using namespace std;

//function to the find Egyptian fraction
void egyptianFraction(int numerator, int denominator){

    //if the numerator or denominator is zero, then there is nothing to do
    if(numerator == 0 || denominator == 0)
        return;

    //if the denominator is divided by the numerator
    if(denominator % numerator == 0){

        cout << "1/" << denominator / numerator;
        return;
    }

    // greedy step: find the ceiling value
    int n = ceil((float)denominator / numerator);

    //print the present unit fraction
    cout << "1/" << n << " + ";

    //calculate the new numerator
    int new_numerator = numerator * n - denominator;

    //calculat the new denominator
    int new_denominator = denominator * n;

    //perform the same task using recursion
    egyptianFraction(new_numerator, new_denominator);
    
}

int main(){

    int numerator = 6;
    int denominator = 14;

    cout << "Egyptian Fraction Representation of"
        << numerator << "/" << denominator << " is: \n";

        //function call
    egyptianFraction(numerator, denominator);

    return 0;
}