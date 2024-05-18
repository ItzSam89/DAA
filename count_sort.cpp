#include <iostream>
#include <vector>
using namespace std;
int maximum(int *array, int len)
{
    int max = array[0];
    for (int i = 1; i < len; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void array_init(int *arr, int size)
{
    for (int x = 0; x < size; x++)
    {
        arr[x] = 0;
    }
}
void Count_sort(int *arr, int size)
{

    int m = maximum(arr, size);
    int *a2 = new int(m + 1);
    array_init(a2, m + 1);
    for (int i = 0; i < size; i++)
    {
        a2[arr[i]]++;
    }
    int k = 0;
    for (int j = 0; j < m + 1; j++)
    {
        if (a2[j] != 0)
        {
            while (a2[j] != 0 && k < size)
            {
                arr[k] = j;
                a2[j]--;
                k++;
            }
        }
    }
    return;
}
int main()
{
    int array[] = {3, 1, 9, 7, 1, 2, 4};
    cout << "Before Sorting: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    Count_sort(array, 7);
    cout << "After Sorting: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}