#include <bits/stdc++.h>
using namespace std;

class MaxHeap{

    public:
        vector<int> heap;

        void insert(int value){

            heap.push_back(value);

            int index = heap.size() - 1;

            while(index > 0){
                
                int parent = (index - 1) / 2;

                if(heap[index] > heap[parent]){

                    swap(heap[index], heap[parent]);

                    index = parent;
                }else{
                    break;
                }
            }
        }

        void printHeap(){

            cout << "Final Max Heap: ";

            for(int i = 0; i < heap.size(); i++){
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};


int main(){

    int arr[] = {10, 20, 5, 6, 1, 8, 9};

    int n = 7;

    MaxHeap h;

    for(int i= 0; i < n; i++){

        h.insert(arr[i]);
    }

    h.printHeap();

    return 0;
}