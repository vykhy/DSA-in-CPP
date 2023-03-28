#include <iostream>
#include <climits>
using namespace std;

/**
 * Time complexity - O(n)
 */
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

/*
 * Time complexity - O(logn)
 */
int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = 20;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int arr[20] = {
        0,
        1,
        3,
        4,
        5,
        13,
        23,
        32,
        34,
        35,
        56,
        56,
        58,
        72,
        123,
        325,
        456,
        876,
        765,
        7645,
    };
    cout << linearSearch(arr, 20, 702) << endl;
    cout << binarySearch(arr, 20, 702);

    return 0;
}