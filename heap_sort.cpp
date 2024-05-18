#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int heapify(int *arr, int size, int index, int &count)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        count++;
        heapify(arr, size, largest, count);
    }
    return count;
}

int heapsort(int *arr, int size)
{
    int count = 0;

    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        count += heapify(arr, size, i, count);
    }

    // Extract elements from heap one by one
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        count += heapify(arr, i, 0, count);
    }

    return count;
}

int main()
{
    int count;
    int arr[5] = {70, 60, 55, 45, 50};
    count = heapsort(arr, 5);
    print(arr, 5);
    cout << endl;
    cout << "The number of comparisons are: " << count << endl;
    return 0;
}
