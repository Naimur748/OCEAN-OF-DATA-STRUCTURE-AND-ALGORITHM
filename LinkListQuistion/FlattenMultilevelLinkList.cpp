

//https://chatgpt.com/c/67761189-e01c-800e-95fe-604834d04024

/*
প্রশ্নটি একটি মাল্টিলেভেল লিঙ্কড লিস্ট নিয়ে কাজ করার উপর ভিত্তি করে।
এটি একটি লিঙ্কড লিস্ট যেখানে প্রতিটি নোডে next এবং prev পয়েন্টারের 
পাশাপাশি একটি অতিরিক্ত child পয়েন্টার থাকে। এই child পয়েন্টার একটি
নতুন লিস্টের দিকে নির্দেশ করতে পারে।

লিঙ্কড লিস্টটি একাধিক স্তরে বিভক্ত হতে পারে, যেখানে কিছু নোডের child 
পয়েন্টার একটি সম্পূর্ণ নতুন স্তরের লিস্ট নির্দেশ করে। এর ফলে, আমরা একটি 
মাল্টিলেভেল ডেটা স্ট্রাকচার পাই।
*/

#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;
        Node* child;

        Node(int _val){
            val = _val;
            next = nullptr;
            prev = nullptr;
            child = nullptr;

        }
};

Node* flatten(Node* head){
    if(!head) return nullptr;


    queue<Node*> q;
    q.push(head);

    Node* dummy = new Node(0);
    Node* prev = dummy;

    while(!q.empty()){

        Node* curr = q.front();
        q.pop();

        prev->next = curr;
        curr->prev = prev;

        if(curr->next){
            q.push(curr->next);
        }

        if(curr->child){
            q.push(curr->child);
            curr->child = nullptr;
        }

        prev = curr;
    }

    prev->next = nullptr;
    return dummy->next;
}

void printList(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;


    node2->child = node5;
    node3->child = node6;
    node5->next = node7;
    node7->prev = node5;
    node7->next = node8;
    node8->prev = node7;


    cout<<"Orginal Multilevel Link List: "<<endl;
    printList(head);

    Node* flattenedList = flatten(head);


    cout<<"Flattened Linked List:"<<endl;
    printList(flattenedList);


    return 0;  

}