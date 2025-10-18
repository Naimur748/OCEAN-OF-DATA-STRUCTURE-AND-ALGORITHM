#include <iostream>
#include <unordered_map>
using namespace std;

int minOperations(string A, string B) {
    // যদি দুই string-এর দৈর্ঘ্য আলাদা হয়, তাহলে সম্ভব নয়
    if (A.length() != B.length())
        return -1;

    // Step 1: Check if both strings have same set of characters
    unordered_map<char, int> freq;
    for (char c : A) freq[c]++;
    for (char c : B) freq[c]--;
    for (auto it : freq)
        if (it.second != 0)
            return -1; // character mismatch হলে impossible

    int i = A.length() - 1;
    int j = B.length() - 1;
    int res = 0;

    // Step 2: Traverse from the end
    while (i >= 0) {
        if (A[i] == B[j]) {
            // যদি মিল পায় তাহলে দুই pointer move করবে
            j--;
        } else {
            // যদি না মিলে তাহলে এই character টাকে move করতে হবে
            res++;
        }
        i--;
    }

    return res;
}

int main() {
    string A = "EACBD";
    string B = "EABCD";
    cout << minOperations(A, B) << endl; // Output: 3
    return 0;
}