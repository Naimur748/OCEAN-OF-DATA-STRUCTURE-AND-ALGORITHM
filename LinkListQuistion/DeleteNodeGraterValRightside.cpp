
//https://chatgpt.com/c/67782a30-25ac-800e-a68d-d137a7bab8d1

/*

Thinking process of Delete nodes which have a greater value on right side
1. First call reverse function inside deleteNode function
head = reverseList(head);

2. Make 3 variable for trackin node
 Node* current = head;
    Node* maxNode = head;
    Node* temp;

3. Make a while loop (current != nullptr && current->next != nullptr)


4. Make if condition if (current->next->data < maxNode->data) Namely 
  . কারেন্টের নেক্সটের ডাটা যদি ম্যাক্স এর ডাটা থেকে ছোট হয় তাহলে ছোট নোড টা মুছে ফেলার প্রক্রিয়া করতে হবে
  . temp = current->next;
            current->next = current->next->next;
            delete temp; 

    অন্যথায়
  . current = current->next;
    maxNode = current;
    

5. Step 3: লিস্ট আবার রিভার্স করুন
    head = reverseList(head);
    return head;

*/
#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int val){
      data = val;
      next = nullptr;
    }
};

Node* reverseList(Node* head){

  Node* prev = nullptr;
  Node* current = head;
  Node* next = nullptr;

  while(current != nullptr){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;

}

Node* deleteNodes(Node* head){

  head = reverseList(head);

  Node* current = head;
  Node* maxNode = head;
  Node* temp;

  while(current != nullptr && current->next != nullptr){

      if(current->next->data < maxNode->data){
           
           temp = current->next;
           current->next = current->next->next;
           delete temp;

      }else{

        current = current->next;
        maxNode = current;

      }
  }

  head = reverseList(head);
  return head;
}

void printList(Node* head){

       while(head != nullptr){

          cout<<head->data<<" ";
          head = head->next;
  }
  cout<<"NULL"<<endl;

}

int main() { 
    Node* head = new Node(12); 
    head->next = new Node(15); 
    head->next->next = new Node(10); 
    head->next->next->next = new Node(11); 
    head->next->next->next->next = new Node(5); 
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    cout << "Original List: "; 
    printList(head); 

    head = deleteNodes(head);


    cout << "Modified List: ";
    printList(head); 


     return 0; 


}
