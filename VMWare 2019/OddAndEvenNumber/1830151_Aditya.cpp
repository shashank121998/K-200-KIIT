#include <bits/stdc++.h>
using namespace std;

// Quick Sort
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high, int asc)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (asc)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        else
        {
            if (arr[j] > pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}
void quicksort(int arr[], int low, int high, int asc)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high, asc);
        quicksort(arr, low, pivot - 1, asc);
        quicksort(arr, pivot + 1, high, asc);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// main soultion

void solution(int arr[], int n)
{
    int a = n / 2;
    int b;
    if (a & 1)
    {
        b = a + 1;
    }
    else
    {
        b = a;
    }

    int newArr[n];
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & 1)
        {
            newArr[l] = arr[i];
            l++;
        }
        else
        {
            newArr[r] = arr[i];
            r--;
        }
    }
    quicksort(newArr, 0, r, 0);
    quicksort(newArr, l, n - 1, 1);
    printArray(newArr, n);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    solution(arr, n);
    // printArray(arr, n);

    return 0;
}