#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL){}

};

//Function to rearrange the linked list tn zig zag fashion
void zigZag(Node* head){

    if(!head) return;

    bool flag = true;

    Node* current = head;
    while(current->next){

        if(flag){

            //If we are expecting current node to be smaller than next
            if(current->data > current->next->data){

                //Swap data if its not in ' < ' order
                swap(current->data, current->next->data);
            }

        }else{
            if(current->data < current->next->data){

                //Swap data if its not in ' > ' order
                swap(current->data, current->next->data);
            }
        }
        //Move to the next node
        current = current->next;

        //Flip the flag for next pair
        flag = !flag;
    }
}

//function to print the linked list
void printList(Node* head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}


//Helper function to insert nodes at the end
void insert(Node*& head, int data){
    if(!head){
        head = new Node(data);
        return;
    }

    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = new Node(data);
}


int main(){

    Node* head = NULL;

    //Insert some values into the linked list
    insert(head, 11);
    insert(head, 15);
    insert(head, 20);
    insert(head, 5);
    insert(head, 10);


    cout<<"Orginal Link List: ";
    printList(head);

    zigZag(head);

    cout<<"Zig zag Link List: ";
    printList(head);

    return 0;


}