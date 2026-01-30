#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Count nodes
int getCount(Node* head) {
    int cnt = 0;
    while(head){
        cnt++;
        head = head->next;
    }
    return cnt;
   
}

// Find intersection
Node* getIntersection(Node* head1, Node* head2) {
   int c1 = getCount(head1);
   int c2 = getCount(head2);

   Node* p1 = head1;
   Node* p2 = head2;

   int d = abs(c1 - c2);

   //Move bigger list ahead
   if(c1 > c2){
    while(d--) p1 = p1->next;
   }else{
    while(d--) p2 = p2->next;
   }

   //Move both together
   while(p1 && p2){
    if(p1 == p2)
        return p1;
    p1 = p1->next;
    p2 = p2->next;
   }

   return nullptr;


}

// Main function with hardcoded linked list
int main() {
    // Common part
    Node* common = new Node(40);
    common->next = new Node(50);

    // First list: 10->20->30->40->50
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = common;

    // Second list: 15->40->50
    Node* head2 = new Node(15);
    head2->next = common;

    Node* intersect = getIntersection(head1, head2);

    if (intersect)
        cout << "Intersection Node: " << intersect->data << endl;
    else
        cout << "No Intersection Found" << endl;

    return 0;
}
