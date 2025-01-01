/*

143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3] 

*/


//https://chatgpt.com/c/6774d667-caf4-800e-8dc3-b657b9714cf7

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr){}

};



void reorderList(ListNode* head){

    if(!head || !head->next || !head->next->next) return;


    //Find the middle using 2 pointer
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //Reverse the second part
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;

    //second part remove from fast part
    slow->next = nullptr;

    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;

    }

    //Mix First part and second part 
    ListNode* first = head;
    ListNode* second = prev;

    while(second){
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;

    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Main link list: ";
    printList(head);

    reorderList(head);

    cout << "Reordere Link list: ";
    printList(head);

    return 0;
}
