#include <iostream>
using namespace std;



// (1) Single inheritance in the Bellow

/*

//Parent Class
class Person{
    public:
    string name;
    int age;

    void displayPersonDetails(){
        cout<<"Name: "<<name<< ", Age: "<<age<<endl;
    }

};


//Child Class inheriting from Person

class Student : public Person{
    public:
    string studentID;


    void displayStudentDetails(){

        displayPersonDetails();

        cout<<"Student ID: "<<studentID<<endl;
    }  

};






int main(){

    Student student1;

    student1.name = "Naimur rahman";
    student1.age = 20;
    student1.studentID = "s1354745";

    student1.displayStudentDetails();

    return 0;


}





// (2) Multiple Inheritance In the Bellow

class Father {
    public:

    void showFather(){
        cout<<"I am the father"<<endl;
    }

};

class Mother{
    public:

    void showMother(){
        cout<<"I am the mother"<<endl;
    }
};


class Child : public Father, public Mother{
    public:

    void showChild(){
        cout<<"I am the child."<<endl;
    }
};


int main(){
    Child c1;
    c1.showFather();
    c1.showMother();
    c1.showChild();

    return 0;
}






// (3) Multileve Inheritance

class Animal {
    public:

    void eat(){
        cout<<"This animal can eat."<<endl;
    }
};


class Mammal : public Animal{
    public:

    void giveBirth(){
        cout<<"This mammal gives birth to live young"<<endl;

    }
};

class Dog : public Mammal{
    public:

    void bark(){
        cout<<"This dog can bark"<<endl;

    }
};


int main(){
    Dog myDog;
    myDog.giveBirth();
    myDog.eat();
    myDog.bark();

    return 0;
}





// (4) Herarchical Inheritance

class Person{
    public:

    string name;
    int age;

    void displayPersonDetails(){
        cout<<"Name: "<<name<<"Age: "<<age<<endl;
    }
};

class Student : public Person{
    public:

    string studentID;

    void displayStudentDetails(){
        displayPersonDetails();

        cout<<"StudentID: "<<studentID<<endl;
    }
};


class Teacher : public Person{
    public:
        string subject;

        void displayTeacherDetails(){
            displayPersonDetails();

            cout<<"Subject is: "<<subject<<endl;

        }
};

int main(){

    Student s1;
    s1.name = "Naimur rahman";
    s1.age = 30;
    s1.studentID = "s125436";


    Teacher t1;
    t1.name = "Ayesha Khatun";
    t1.age = 25;
    t1.subject = "Mathmetics";

    cout<<"Student Deatils: "<<endl;
    s1.displayStudentDetails();

    cout<<"Teacher Details: "<<endl;
    t1.displayTeacherDetails();

    return 0;

}




//(5) Hybrid inheritance

class Person{
    public:
    string name;
    int age;

    void displayPersonDetails(){
        cout<<"Name: "<<name<<"Age: "<<age<<endl;
    }
};

class Student : public Person{
    public:
       string studentID;


       void displayStudentDetails(){

        displayPersonDetails();
        cout<<"Student ID: "<<studentID<<endl;

       }
};


class Employee : public Person{
    public:
        string jobTitle;

        void displayEmployeeDetails(){

            displayPersonDetails();
            cout<<"Job title: "<<jobTitle<<endl;
        }

};


class WorkingStudent : public Student, public Employee{
    public:

    void displayWorkingStudentDetails(){

        //Resolving ambiguity (explicitly calling Person from Student)
        Student::displayPersonDetails();

        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Job title: "<<jobTitle<<endl;
    }

};


int main(){
    WorkingStudent ws1;

    ws1.Student::name = "Naimur Rahman";
    ws1.Student::age = 30;
    ws1.studentID = "s456875";
    ws1.jobTitle = "Software Engineer";

    //Displaying Details
    ws1.displayWorkingStudentDetails();

    return 0;
}

*/

