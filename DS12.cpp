#include <iostream>
using namespace std;
template <class T>
class Sort
{
public:
    void swap(T *xp, T *yp)
    {
        T temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    void input(int n)
    {
        int ch;
        T *arr = new T[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the element: ";
            cin >> arr[i];
        }
        cout << "Enter the choice \n1 for Selection Sort \n2 for Bubble Sort \n3 for Insertion Sort" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            selectionSort(arr, n);
            display(arr, n);
            break;
        }
        case 2:
        {
            bubbleSort(arr, n);
            display(arr, n);
            break;
        }
        case 3:
        {
            insertionSort(arr, n);
            display(arr, n);
            break;
        }
        }
    }
    void insertionSort(T arr[], int n)
    {
        int i, j;
        T key;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    void bubbleSort(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }
    void selectionSort(T arr[], int n)
    {
        int i, j, min_idx;

        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            swap(&arr[min_idx], &arr[i]);
        }
    }
    void display(T arr[], int n)
    {
        cout << "--------Sorted Array in Ascending Order--------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    int n;
    Sort<int> ob;

    cout << "Enter the number of elements" << endl;
    cin >> n;
    ob.input(n);

    return 1;
}