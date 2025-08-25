#include <iostream>
#include <vector>

using namespace std;



void generateMenuCombinations(vector<string>& items, vector<string>& selectedItems,
                            int start, int end, int index, int r){

                                if(index == r){
                                    for(int j=0; j<r; j++){
                                        cout<< selectedItems[j] << (j+1 == r? "" : ", ");
                                    }
                                    cout<<endl;
                                    return;
                                }

                                for(int i=start; i<=end && end-i+1 >= r-index; i++){
                                    
                                }

                            }



int main(){

    vector<string> foodItem = {"Burger", "Pizza", "Pasta", "Salad", "Soup", "Sandwich"};

    int r = 3;
    int n = foodItem.size();

    vector<string> selectedItems(r);
    cout<< "All possible menu combination(" <<n << "c" <<r << " ):\n\n";

    generateMenuCombinations(foodItem, selectedItems, 0, n-1, 0, r);

    return 0;
}
