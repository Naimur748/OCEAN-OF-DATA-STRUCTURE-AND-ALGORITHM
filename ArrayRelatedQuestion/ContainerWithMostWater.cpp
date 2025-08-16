#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int>& height){

    int left = 0;
    int right = height.size() - 1;
    int maxWater = 0;

    while(left < right){

        int h = min(height[left], height[right]);
        int width = right - left;
        int area = h * width;

        maxWater = max(maxWater, area);

        if(height[left] < height[right]){

            left++;
        }else{
            right--;
        }
    }

    return maxWater;
}


int main(){

    int n;
    cout << "How many plar need in vector: ";
    cin>> n;

    vector<int> height(n);
    cout << "Enter the height of plar: ";

    for(int i=0; i<n; i++){
        cin>> height[i];
    }

    cout << "Total amount of water: " << maxArea(height) << endl;

    return 0;


}