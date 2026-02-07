#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(vector<string>& arr){

    stack<int> st;   // Stack to store operands

    //Traverse each element of postfix expression
    for(int i = 0; i < arr.size(); i++){

        string token = arr[i];  //Current element

        // If token is an operator
        if(token == "+" || token == "-" || token == "*" || 
         token == "/" || token == "^"){

            //pop operand2 first
            int operand2 = st.top();
            st.pop();

            //Pop operand1 next
            int operand1 = st.top();
            st.pop();

            int result = 0; // To store operation result

            //Perform operation based on operator
            if(token == "+")
                result = operand1 + operand2;
            else if(token == "-")
                result = operand1 - operand2;
            else if(token == "*")
                result = operand1 * operand2;
            else if(token == "/")
                result = operand1 / operand2;
            else if(token == "^")
                result = pow(operand1, operand2);

            //Push the result back to stack
            st.push(result);

        }else{
            //if token is a number, convert string to int
            int num = stoi(token);
            st.push(num);

        }

    }

    //Final result will be at the top of stack
    return st.top();

}

int main(){

    //Example input
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};

    //Function call
    int answer = evaluatePostfix(arr);

    //Output result
    cout << "Result = " << answer << endl;

    return 0;
}