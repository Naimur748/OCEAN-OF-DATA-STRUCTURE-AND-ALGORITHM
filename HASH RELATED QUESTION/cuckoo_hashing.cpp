#include <bits/stdc++.h>
using namespace std;

#define SIZE 11

#define EMPTY -1

int hash1(int key){
    return key % SIZE;
}

int hash2(int key){
    return (key / SIZE) % SIZE;
}

int table1[SIZE];
int table2[SIZE];

void initializeTable(){

    for(int i = 0; i < SIZE; i++){
        
    table1[i] = EMPTY;
    table2[i] = EMPTY;

    }

}


void printTable(){

    cout << "\n Table 1: \n";

    for(int i = 0; i < SIZE; i++){

        cout << i << " ->";

        if(table1[i] == EMPTY)
            cout << "EMPTY";
        else
            cout << table1[i];

        cout << endl;

    }

    cout << "\nTable 2:\n";

    for(int i = 0; i < SIZE; i++){

        cout << i << " ->";

        if(table2[i] == EMPTY)
            cout << "EMPTY";
        else
            cout << table2[i];

        cout << endl;
    }
}


void insert(int key){

    int currentKey = key;

    int tableNumber = 1;

    for(int count = 0; count < SIZE; count++){

        if(tableNumber == 1){

            int index = hash1(currentKey);

            if(table1[index] == EMPTY){

                table1[index] = currentKey;

                cout << currentKey << "inserted in Table at index " << index << endl;

                return;

            }else{

                cout << currentKey << "displaced " << table1[index] 
                << "from Table index "
                << index << endl;

                int displaced = table1[index];

                table1[index] = currentKey;

                currentKey = displaced;

                tableNumber = 2;

            }

        }else{

            int index = hash2(currentKey);

                if(table2[index] == EMPTY){

                    table2[index] = currentKey;

                    cout << currentKey << "inserted in Table2 at index " << index << endl;

                    return;
                    
                }else{

                    cout << currentKey 
                    << "displaced " 
                    << "from Table2 index "
                    << index << endl;

                    int displaced = table2[index];

                    table2[index] = currentKey;

                    currentKey = displaced;

                    tableNumber = 1;
                }
        }
    }

    cout << "Cycle detected! Reshshing needed.\n";
}




int main(){

    int keys[] = {20, 50, 53, 75, 100, 67, 105, 67, 105, 3, 36, 39};

    int n = sizeof(keys) / sizeof(keys[0]);

    initializeTable();

    for(int i = 0; i < n; i++){

        cout << "\n Inserting " << keys[i] << endl;

        insert(keys[i]);
    }

    printTable();

    return 0;
}