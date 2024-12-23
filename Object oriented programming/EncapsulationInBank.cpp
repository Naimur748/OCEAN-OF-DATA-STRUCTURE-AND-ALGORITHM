#include <iostream>
using namespace std;

class BankAccount{
    private:
    double balance;


    public:
    //Constructor to initialize balance
    BankAccount(double initialBalance){
        
        if(initialBalance >= 0){

            balance = initialBalance;

        }else{

            balance = 0;
            cout<<"Initial balance invalid, set to 0."<<endl;
        }
    }

//Deposit method
void deposit(double amount){

    if(amount > 0){
        balance += amount;
        cout<<"Deposit:"<<amount<<" BDT"<<endl;

    }else{
        cout<<"Invalid deposit amount"<<endl;
    }
  }

  //withrow method
  void withdraw(double amount){

    if(amount > 0 && amount <= balance){
        balance -= amount;
        cout<<"withdraw: "<<amount<<" BDT";
    }else{
        cout<<"Invalid withdraw amount"<<endl;
    }
  }

  //Getter for balance
  double getBalance(){
    return balance;
  }

};

int main(){

    BankAccount account(1000.0); //Initial balance

    account.deposit(500.0); //Deposit money
    account.withdraw(300.0); // Withdraw money
    account.withdraw(1500.0); //Invalid Withdraw

    cout<<"Current Balance: "<<account.getBalance()<<" BDT"<<endl;

    return 0;



}