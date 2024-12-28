#include <iostream>
using namespace std;


/*


struct Node{
    int data;
    Node* next;
};

class CircularLinkList{
    private:
        Node* head;


    public:
        CircularLinkList(){
            head = nullptr;
        }

    void insert(int val){
        Node* newNode = new Node();
        newNode->data = val;

        if(head == nullptr){
            head = newNode;
            newNode->next = head;
        }else{
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

  //Print List

void display()  {
    if(head == nullptr){
        cout<<"List is Blank"<<endl;
        return;
    }

    Node* temp = head;
    
    do{
        cout<<temp->data<<" ";
        temp = temp->next;

    }while(temp != head);

    cout<<endl;
  }

~CircularLinkList(){
    if(head != nullptr){
        Node* temp = head;

        while(temp->next != head){
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        delete temp;
    }
}

};


int main(){

    CircularLinkList call;

    call.insert(10);
    call.insert(20);
    call.insert(30);

    call.display();

    return 0;

}


*/

struct Node{
    int data;
    Node* next;
};

class CircularLinkList{
    private:
        Node* head;
    
    public:

        CircularLinkList(){
            head = nullptr;
        }

        void insert(int val){
            Node* newNode = new Node();
            newNode->data = val;

            if(head == nullptr){
                head = newNode;
                newNode->next = head;
            }else{
                Node* temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
            }

        }


        //Print the singly circular link list
        void display(){

            if(head == nullptr){
                cout<<"Link list is Blank";
                return;
            }

            Node* temp = head;
            do{
                cout<<temp->data<<"<->";
                temp = temp->next;
            }while(temp != head);
            cout<<"Point first value";

        }

        //Destructure the heap memory
        ~CircularLinkList(){
            if(head != nullptr){

                Node* temp = head;

                while(temp->next != head){

                    Node* del = temp;
                    temp = temp->next;

                    delete del;
                }

                delete temp;
            }
        };

};

 int main(){
    
    CircularLinkList cal;

    cal.insert(10);
    cal.insert(20);
    cal.insert(30);

    cal.display();

    return 0;

        }