#include <iostream>
using namespace std;


// https://chatgpt.com/c/6763fb72-2880-800e-9bab-a9a74dfecd51
class car{
    public:
    string car_name;
    int prize;

    void showCar(){
        cout<<"carName is  "<<car_name<<" prize is "<<prize;
        cout<<endl;
    }


};


class Student{
    public:
    string name;
    int age;

//constructor
    Student(string n, int a){
        name = n;
        age = a;
    }


     void display(){
        cout<<"Name: "<<name<<", Age: "<<age<<endl;
    }

};



int main(){

car naimur;
naimur.car_name = "Pazaro";
naimur.prize = 4;

car faysal;
faysal.car_name = "Thanos";
faysal.prize = 10;

naimur.showCar();

faysal.showCar();



    Student s1("Naimur",20);
     s1.display();

     return 0;
   
}