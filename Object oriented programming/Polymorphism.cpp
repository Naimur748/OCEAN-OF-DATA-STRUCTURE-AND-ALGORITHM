#include <iostream>
using namespace std;


/* 

//How compile time polymorphism work

class Calculator {
    public:

    int add(int a, int b){
        return a + b;
    }

    int add(int a, int b, int c){
        return a + b + c;
    }

    int add(double a, double b){
        return a + b;
    }
};


int main(){
    Calculator calc;

    cout<<"Sum of 2 integer: "<<calc.add(10, 20)<<endl;
    cout<<"Sum of 3 integer: "<<calc.add(10, 20, 30)<<endl;
    cout<<"Sum of 2 double: "<<calc.add(10.5, 20.7)<<endl;
    
    return 0;
}


*/


// Runtime polymorphism

class Animal {
    public:

        virtual void sound(){
            cout<<"this is a generic animal sound."<<endl;
        }
};

class Dog : public Animal{
    public:
        void sound() override{
            cout<<"Dog bark: woof! woof!"<<endl;
        }

};


class Cat : public Animal{
    public:
        void sound()override{
            cout<<"Cat meows: Meow! Meow!"<<endl;
        }
};


int main(){

    Animal* animal;

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound(); //Dog sound call

    animal = &cat;
    animal->sound(); //Cat sound call

    return 0;
}


