#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{

    int pivot = arr[e];
    int pivotIndex = s - 1;
    for (int j = s; j <= e - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            pivotIndex++;
            swap(arr[pivotIndex], arr[j]);
        }
    }
    swap(arr[pivotIndex + 1], arr[e]);
    return pivotIndex + 1;
}

void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partition
    int p = partition(arr, s, e);

    // left part sort
    quickSort(arr, s, p - 1);

    // right part sort
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[10] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
    int n = 10;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}