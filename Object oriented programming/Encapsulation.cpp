#include <iostream>
using namespace std;


// https://chatgpt.com/c/673e9e07-05f8-800e-a0fe-7663bc8da860

class Employee{
    private:
    int salary; //private attribute,


    public:
    //Setter method:
    void setSalary(int s){
        if(s > 0){
            salary = s;
        }else{
            cout<<"Invalid salary amount"<<endl;
        }
    }
//Getter method:
int getSalary(){
    return salary;
}

};

int main(){

Employee emp;

emp.setSalary(5000);
cout<<"Salary: "<<emp.getSalary()<<" BDT"<<endl;


emp.setSalary(-5000);
cout<<"Salary: "<<emp.getSalary()<<" BDT"<<endl;

}