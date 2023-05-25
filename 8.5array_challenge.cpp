#include "bits/stdc++.h"
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}

int firstRepeatingElement(int arr[], int n)
{
    /**
     * return the smallest index from the indexes of repeating numbers in the array
     * eg [1,2,3,5,0,5,3]
     * smallest = 2 because it is the smallest index from among all repeating elements
     */
    const int N = 1e5 + 2;
    int index[N];

    for (int i = 0; i < N; i++)
    {
        index[i] = -1;
    }

    int minindex = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (index[arr[i]] != -1)
        {
            minindex = min(minindex, index[arr[i]]);
        }
        else
        {
            index[arr[i]] = i;
        }
    }

    if (minindex == INT_MAX)
    {
        return -1;
    }
    else
    {
        return minindex + 1;
    }
}

/**
 * Given an unsorted array of size N of non-negative integers, find a
 * continuous subarray which add to a given number S
 * return starting and ending index of subarray
 */

int *subArrayOfSum(int arr[], int n, int s)
{
    int *result = new int[2];
    int currentSum = 0;

    int start = -1;
    int end = -1;
    int i = 0;
    int j = 0;

    while (j < n && currentSum + arr[j] <= s)
    {
        currentSum += arr[j];
        j++;
    }
    if (currentSum == s)
    {
        result[0] = i;
        result[1] = j;
        return result;
    }
    while (j < n)
    {
        currentSum += arr[j];
        while (currentSum > s)
        {
            currentSum -= arr[i];
            i++;
        }
        if (currentSum == s)
        {
            start = i + 1;
            end = j + 1;
            break;
        }
        j++;
    }
    result[0] = start;
    result[1] = end;

    return result;
}

/**
 * Given an array of N integers including 0, find the smallet positive number missing from the array
 */
int smallestMissingPositiveInteger(int arr[], int n)
{
    int N = 1e6 + 2;
    bool index[N];
    for (int i = 0; i < N; i++)
    {
        index[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            index[arr[i]] = true;
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (!index[i])
        {
            return i;
        }
    }
    return -1;
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
    // int result = firstRepeatingElement(arr, 20);
    int result = smallestMissingPositiveInteger(arr, 20);
    cout << result << endl;

    // int *result = subArrayOfSum(arr, 20, 400);
    // printArr(result, 2);

    return 0;
}
