#include <iostream>
#include <list>
using namespace std;

class HashTable{
    int size;
    list<int>* table;

    public:
        HashTable(int s){
            size = s;
            table = new list<int>[size];
        }

        int hashFunction(int key){
            return key % size;
        }

        void insert(int key){
            int index = hashFunction(key);
            table[index].push_back(key);
            cout << key << "Inserted at index " << index << endl;
        }

        bool search(int key){
            int index = hashFunction(key);
            for(auto x : table[index]){
                if(x == key){
                    cout << key  << " Found at index " << index << endl;
                    return true;
                }
            }
            cout << key << " Not Found " << endl;
            return false;
        }

        void display(){
            for(int i = 0; i < size; i++){
                cout << i << " --> ";
                for(auto x : table[i])
                cout << x << " ";
                cout << endl;
            }
        }

};

int main(){

    HashTable h(10);
    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(20);
    h.insert(30);

    cout << "\nHash Table: \n";
    h.display();

    cout << "\nSearching Element:\n";
    h.search(25); // Found
    h.search(99); // Not found

    return 0;
}