/*

🔹 What does the problem actually say?
1. You are given an integer array.
2. You need to divide this array into two subsets in such a way that—
3. The sum of both subsets is exactly equal.
4. If n is even, then each subset must contain exactly n/2 elements.
5. If n is odd, then one subset must contain n/2 elements and the other subset must contain (n/2 + 1) elements.
6. It is guaranteed in the problem statement that such a division is always possible.

🔹 Algorithm / Approach
1. Calculate the total sum
a. First, calculate the sum of all elements in the given array.
b. Since the problem guarantees that an equal partition is possible, the total sum will always be an even number.

2. Determine the target sum
a. Set the target sum for each subset as totalSum / 2.

3. Determine the required subset size
a. Let n be the total number of elements in the array.
b. If n is even, each subset must contain exactly n / 2 elements.
c. If n is odd:
    • one subset must contain n / 2 elements, and
    • the other subset must contain (n / 2 + 1) elements.

4. Reduce the problem
a. The problem is now reduced to finding one subset of the required size.
b. This subset must have a sum equal to the target sum.

5. Choose the solution technique
a. Use recursion and backtracking to search for the required subset.

6. Make recursive decisions
a. At each recursive step, make two choices for the current element:
    • include the element in the current subset, or
    • exclude the element from the current subset.

7. Track necessary information
a. Keep track of the current index in the array.
b. Maintain the current sum of the selected elements.
c. Maintain the count of selected elements.

8. Apply backtracking conditions
a. If the current sum exceeds the target sum, stop exploring that path.
b. If the number of selected elements exceeds the required subset size, stop exploring that path.

9. Check for a valid solution
a. If the current sum becomes equal to the target sum, and
b. the number of selected elements matches the required subset size,
c. then a valid subset has been found.

10. Store the result
a. Store the found subset as the final result.
b. Stop further recursive exploration.

11. Form the second subset
a. The elements that are not included in the first subset
b. automatically form the second subset.


🔹 সমস্যাটা আসলে কী বলছে?
১।তোমাকে একটি integer array দেওয়া আছে।
২।তোমাকে এটাকে দুইটা subset-এ ভাগ করতে হবে এমনভাবে যে—
৩।দুই subset-এর sum একদম সমান হবে
৪।যদি n even → দুই subset-এই থাকবে n/2 টি করে element
৫।যদি n odd → একটাতে n/2, অন্যটাতে (n/2 + 1) টি element
৬।প্রশ্নে গ্যারান্টি দেওয়া আছে যে সমাধান অবশ্যই আছে



🔹 অ্যালগরিদম / পদ্ধতি (Algorithm / Approach)
১. মোট যোগফল নির্ণয়
ক. প্রথমে অ্যারের সব উপাদানের যোগফল (total sum) বের করতে হবে।
খ. প্রশ্নে যেহেতু নিশ্চিত করা আছে যে সমানভাবে ভাগ করা সম্ভব, তাই এই যোগফলটি অবশ্যই জোড় (even) সংখ্যা হবে।

২. লক্ষ্য যোগফল নির্ধারণ
ক. প্রতিটি subset-এর জন্য লক্ষ্য যোগফল (target sum) হবে totalSum / 2।

৩. উপাদানের সংখ্যা নির্ধারণ
ক. n দ্বারা অ্যারের মোট উপাদানের সংখ্যা বোঝানো হবে।
খ. যদি n জোড় (even) হয়, তাহলে প্রতিটি subset-এ ঠিক n / 2 টি উপাদান থাকতে হবে।
গ. যদি n বিজোড় (odd) হয়, তাহলে
    • একটি subset-এ n / 2 টি উপাদান থাকবে এবং
    • অন্য subset-এ (n / 2 + 1) টি উপাদান থাকবে।

৪. সমস্যার সরলীকরণ
ক. এখন সমস্যাটি রূপান্তরিত হয় একটি ছোট সমস্যায়—
খ. নির্দিষ্ট সংখ্যক উপাদান নিয়ে এমন একটি subset খুঁজতে হবে যার যোগফল হবে target sum-এর সমান।

৫. সমাধান পদ্ধতি নির্বাচন
ক. এই subset খুঁজতে Recursion এবং Backtracking পদ্ধতি ব্যবহার করা হবে।

৬. Recursive সিদ্ধান্ত গ্রহণ
ক. প্রতিটি recursive ধাপে বর্তমান উপাদানের জন্য দুটি সিদ্ধান্ত নেওয়া হবে—
    • উপাদানটিকে subset-এ অন্তর্ভুক্ত করা (Include)
    • উপাদানটিকে subset থেকে বাদ দেওয়া (Exclude)

৭. প্রয়োজনীয় তথ্য ট্র্যাক করা
ক. অ্যারের বর্তমান ইনডেক্স কোন অবস্থায় আছে তা ট্র্যাক করা হবে।
খ. এখন পর্যন্ত নেওয়া উপাদানগুলোর মোট যোগফল সংরক্ষণ করা হবে।
গ. এখন পর্যন্ত নেওয়া উপাদানগুলোর সংখ্যা গণনা করা হবে।

৮. Backtracking প্রয়োগ
ক. যদি কোনো পর্যায়ে যোগফল target sum-এর চেয়ে বেশি হয়ে যায়, তাহলে সেই পথ বাতিল করা হবে।
খ. যদি নেওয়া উপাদানের সংখ্যা নির্ধারিত সীমা অতিক্রম করে, তাহলেও সেই পথ বাতিল করা হবে।

৯. সমাধান পাওয়ার শর্ত
ক. যখন নেওয়া উপাদানগুলোর যোগফল target sum-এর সমান হবে এবং
খ. নেওয়া উপাদানগুলোর সংখ্যা প্রয়োজনীয় সংখ্যার সমান হবে,
গ. তখন একটি বৈধ subset পাওয়া যাবে।

১০. ফলাফল সংরক্ষণ
ক. পাওয়া subset-টিকে সংরক্ষণ করা হবে।
খ. এরপর আর নতুন কোনো recursive অনুসন্ধান করা হবে না।

১১. দ্বিতীয় subset গঠন
ক. যেসব উপাদান প্রথম subset-এ অন্তর্ভুক্ত নয়,
খ. সেগুলো স্বয়ংক্রিয়ভাবে দ্বিতীয় subset তৈরি করবে।



*/




#include <bits/stdc++.h>
using namespace std;

bool found = false;

/*
 idx         → current index
 arr         → input array
 n           → array size
 targetSum  → totalSum / 2
 reqSize    → required subset size
 currSum    → current subset sum
 currSize   → current subset size
 subset     → current subset elements
 result     → final subset
*/

void solve(int idx,
           vector<int>& arr,
            int n,
            int targetSum,
            int reqSize,
            int currSum,
            int currSize,
            vector<int>& subset,
            vector<int>& result)
{
    if(currSum == targetSum && currSize == reqSize){
        result = subset;
        found = true;
        return;
    }

    // Invalid case
    if(idx == n || currSum > targetSum || currSize > reqSize)
        return;

        subset.push_back(arr[idx]);
        solve(idx + 1, arr, n, targetSum, reqSize,
            currSum + arr[idx], currSize + 1, subset, result);
        
        subset.pop_back();

        //Exclude current element
        solve(idx + 1, arr, n, targetSum, reqSize,
            currSum, currSize, subset, result);
            
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    //vector<int> arr = {5, 10, 15};

    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int targetSum = totalSum / 2;

    int reqSize;
    if(n % 2 == 0) 
        reqSize = n / 2;
    else 
        reqSize = n / 2 + 1;

    vector<int> subset, result;
    solve(0, arr, n, targetSum, reqSize, 0, 0, subset, result);

    cout << "Subset 1: ";
    unordered_set<int> used;
    for(int x : result){
        cout << x << " ";
        used.insert(x);
    }

    cout << "\nSubset 2: ";
    for(int x : arr){
        if(used.find(x) == used.end())
            cout << x << " ";
    }

    return 0;


}

