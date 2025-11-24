#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


bool canAllocate(const vector<int>& books, int totalStudent, int maxAllowedPages){
    int studentCount = 1;
    int currentPages = 0;

    for(int pages : books){
        if(pages > maxAllowedPages) return false;
        if(currentPages + pages > maxAllowedPages){
            studentCount++;
            currentPages = pages;

            if(studentCount > totalStudent) return false;

        }else{

            currentPages += pages;
        }
    }

    return true;
}



int findMinimumMaximumPages(const vector<int>& books, int totalStudents){

    int n = books.size();
    if(totalStudents > n) return false;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    int minMaxPages = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(canAllocate(books, totalStudents, mid)){

            minMaxPages = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return minMaxPages;
}

int main(){

    vector<int> books = {10, 5, 20};
    int students = 2;

    int minimumMaximumPages = findMinimumMaximumPages(books, students);
    cout << "Minimum of maximum pages = " << minimumMaximumPages << endl;
}