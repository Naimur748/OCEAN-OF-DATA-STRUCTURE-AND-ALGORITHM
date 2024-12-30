#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool hasCycle(ListNode* head){

    //if list is blank
    if(!head || !head->next) return false;

    //Set slow and fast pointer
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;


}

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    //create cycle Last Node to second Node
    head->next->next->next->next = head->next;

    if(hasCycle(head)){
        cout<<"Cycle detected."<<endl;
    }else{
        cout<<"No cycle detected."<<endl;
    }

    return 0;
}