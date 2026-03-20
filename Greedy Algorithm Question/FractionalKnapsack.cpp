#include <bits/stdc++.h>
using namespace std;

// একটি structure তৈরি করা হচ্ছে item এর জন্য
struct Item
{
    int value;   // item এর value
    int weight;  // item এর weight
};

// comparator function ratio অনুযায়ী sort করার জন্য
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight; // item a এর value/weight
    double r2 = (double)b.value / b.weight; // item b এর value/weight

    return r1 > r2; // বড় ratio আগে থাকবে
}

// Fractional Knapsack function
double fractionalKnapsack(int capacity, Item arr[], int n)
{
    // ratio অনুযায়ী item sort করা হচ্ছে
    sort(arr, arr + n, compare);

    double totalValue = 0.0; // মোট value রাখার variable

    // প্রতিটি item নিয়ে loop চালানো হচ্ছে
    for (int i = 0; i < n; i++)
    {
        // যদি পুরো item ব্যাগে ঢুকে যায়
        if (arr[i].weight <= capacity)
        {
            capacity -= arr[i].weight;   // capacity কমিয়ে দেওয়া হচ্ছে
            totalValue += arr[i].value;  // পুরো value যোগ করা হচ্ছে
        }
        else
        {
            // যদি পুরো item না ঢুকে

            double fraction = (double)capacity / arr[i].weight; // কত fraction নেওয়া যাবে

            totalValue += arr[i].value * fraction; // fraction অনুযায়ী value যোগ করা

            capacity = 0; // capacity শেষ

            break; // loop বন্ধ
        }
    }

    return totalValue; // সর্বোচ্চ value return
}

int main()
{
    // হার্ডকোড ইনপুট

    int val[] = {60, 100, 120};   // value array
    int wt[] = {10, 20, 30};      // weight array
    int capacity = 50;            // ব্যাগের capacity

    int n = 3; // item সংখ্যা

    Item arr[n]; // Item structure array

    // value এবং weight structure এ assign করা হচ্ছে
    for (int i = 0; i < n; i++)
    {
        arr[i].value = val[i];
        arr[i].weight = wt[i];
    }

    // function call
    double result = fractionalKnapsack(capacity, arr, n);

    // output print
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}