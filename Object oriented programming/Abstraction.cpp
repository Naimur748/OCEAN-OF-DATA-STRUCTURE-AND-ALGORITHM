#include <iostream>
using namespace std;

// Abstract Class
class Shape{
    public:
        virtual void draw()=0;

        void display(){
            cout<<"This is a shape"<<endl;
        }
        
};

//Derived Class 1
class Circle : public Shape{
    public:

    void draw(){
        cout<<"Draw a Circle. "<<endl;
    }
};

//Derived Class 2
class Rectangle : public Shape{
    public:

    void draw(){
        cout<<"Draw aRectangle. "<<endl;

    }
};

int main(){
    Shape* shape;
    

    Circle circle;
    Rectangle rectangle;
    

    shape = &circle;
    shape->draw();

}