#include "bits/stdc++.h"
using namespace std;

// video 8.4

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

int lengthOfLongestArithmeticSubarray(int arr[], int n)
{
    int longest = 0;
    int prev_difference = arr[1] - arr[0];
    int j = 2;
    int curr = 2;

    while (j < n)
    {
        if (arr[j] - arr[j - 1] == prev_difference)
        {
            curr++;
        }
        else
        {
            prev_difference = arr[j] - arr[j - 1];
            curr = 2;
        }
        longest = max(longest, curr);
        j++;
    }

    return longest;
}

int recordBreakingDays(int arr[], int n)
/**
 * returns number of days where visitors were more than any previous day and more than its following day.
 * First and last day could be record breaking days
 */
{
    int days = 0;
    int record = 0;
    for (int i = 0; i < n; i++)
    {
        // first day more than 2nd day
        if (i == 0 && arr[1] < arr[0])
        {
            record = arr[0];
            days++;
        }
        // last day is highest
        else if (i == n - 1 && arr[i] > record)
        {
            days++;
            record = arr[i];
        }
        // if highest to date and more than next day
        else if (arr[i] > record && arr[i + 1] < arr[i])
        {
            record = arr[i];
            days++;
        }
    }
    return days;
}

int main()
{
    int arr[20] = {
        76,
        13,
        325,
        0,
        45,
        23,
        456,
        32,
        34,
        765,
        35,
        1,
        876,
        56,
        3,
        4,
        5,
        56,
        58,
        72};

    // int result = sumOfSubArray(arr, 20);
    // int result = lengthOfLongestArithmeticSubarray(arr, 20);
    int result = recordBreakingDays(arr, 20);
    cout << result << endl;
    // printArr(arr, 20);

    return 0;
}
