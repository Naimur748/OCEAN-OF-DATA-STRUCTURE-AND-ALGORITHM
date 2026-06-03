#include <bits/stdc++.h>
using namespace std;

struct ListNode{

    int val;
    ListNode* next;

    ListNode(int x){

        val = x;
        next = NULL;
    }
};


struct compare{

    bool operator()(ListNode* a, ListNode* b){

        return a->val > b->val;
    }
};




ListNode* mergeKLists(vector<ListNode*>& lists){

    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    for(ListNode* head : lists){

        if(head != NULL){

            pq.push(head);
        }
    }



    ListNode* dummy = new ListNode(-1);

    ListNode* tail = dummy;

    while(!pq.empty()){

        ListNode* smallest = pq.top();

        pq.pop();

        tail->next = smallest;

        tail = tail->next;

        if(smallest->next != NULL){

                pq.push(smallest->next);
        }
    }

    return dummy->next;
}


void printList(ListNode* head){

    while(head != NULL){

        cout << head->val;

    if(head->next != NULL){

        cout << " -> ";
    }

    head = head->next;

    }

    cout << endl;

    
}




int main(){

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Second List 
    ListNode* l2 =  new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    //Third list
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    //Keep all list in vector
    vector<ListNode*> lists;

    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    //Merge function cll
    ListNode* result = mergeKLists(lists);

    cout << "Merged sorted List: ";

    printList(result);

    return 0;


    
}
