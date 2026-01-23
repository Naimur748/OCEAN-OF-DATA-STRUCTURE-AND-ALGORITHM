#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

/*
তাহলে এখানে আমরা বলতে পারি প্রথমে যখন একটা নোট এর মধ্যে ভ্যালুয়েন্সিয়ালাইজ
করা হচ্ছে তখন সেটা হিপ মেমোরিতে যায় হিট মেমোরিতে কনস্ট্রাক্টর ভেলুগুলো স্ট্রাকচারের 
ডাটার মধ্যে বসায় তাহলে মূল বিষয় কি দাঁড়ালো স্ট্রাকচার হচ্ছে কয়েক টা ডাটার সংমিশ্রণ 
আর স্ট্রাকচারের মধ্যে কনস্ট্রাক্টর হচ্ছে এই ডাটার মধ্যে যা কিছু বুঝবে তা নির্ধারণ করে দেয়
অর্থাৎ হিপ মেমোরির মধ্যে যেটা পাই সেটা স্ট্রাকচারের ডেটা ওগুলোর মধ্যে বসিয়ে দেয় এরপরে
ওইটার ভ্যালু অনুসারে প্রতিটা নোট সৃষ্টি হয়
*/

int main(){
    // Create node
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    //Make it link
    head->next = second;
    second->next = third;

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}