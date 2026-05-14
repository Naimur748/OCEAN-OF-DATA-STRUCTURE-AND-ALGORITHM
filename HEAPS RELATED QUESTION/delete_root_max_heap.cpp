#include <bits/stdc++.h>
using namespace std;



void heapifyDown(vector<int>& heap, int n, int i){

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    // Left child check
    if(left < n &&  heap[left] > heap[largest]){
        largest = left;

    }

    //Right child check
    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);

        heapifyDown(heap, n, largest);

    }
}


int main(){

    vector<int> heap = {50, 30, 40, 10, 5, 20};

    int n = heap.size();

    heap[0] = heap[n - 1];

    heap.pop_back();

    n--;

    heapifyDown(heap, n, 0);

    cout << "Final Max Hepa: ";

    for(int value : heap){
        cout << value << " ";
    }
    return 0;
    
}