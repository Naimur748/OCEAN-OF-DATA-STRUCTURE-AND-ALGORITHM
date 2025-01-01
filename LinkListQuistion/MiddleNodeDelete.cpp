#include <iostream>
using namespace std;


//https://chatgpt.com/c/6774cd5f-4a68-800e-8c8d-0926f21a8d16

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* deleteMiddle(ListNode* head){
    if(!head || !head->next){
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while(fast && fast->next){
        prev = slow;
        slow  = slow->next;
        fast = fast->next->next;

    }

    if(prev){
        prev->next = slow->next;
    }

    delete slow;
    return head;


}

void printList(ListNode* head){
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL";

}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    cout<<"Orginal List:"<<endl;
    printList(head);

    cout<<"Delete Middle Node Function: "<<endl;
    head = deleteMiddle(head);

    cout<<"List with Middlw node delete "<<endl;
    printList(head);

    return 0;

}