#include "bits/stdc++.h"
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}

int sumOfSubArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // accumulate sum of current sub array
        int current = 0;
        for (int j = i; j < n; j++)
        {
            current += arr[j];
            // adds this item plus sum of previous items in subarray
            sum += current;
        }
    }
    return sum;
}

int main()
{
    int arr2[5] = {
        1, 1, 1, 1, 1};
    int arr[20] = {
        76,
        13,
        325,
        456,
        0,
        45,
        23,
        32,
        34,
        35,
        1,
        876,
        56,
        3,
        4,
        5,
        765,
        56,
        58,
        72};

    int result = sumOfSubArray(arr2, 5);
    cout << result << endl;
    // printArr(arr, 20);

    return 0;
}
