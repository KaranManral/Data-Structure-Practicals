// Write a Program to implement a priority queue using heap data structure.

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void swapp(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
class MinHeap
{
public:
    int *arr;
    int capacity;  // max size
    int heap_size; // no of element in heap
    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        arr = new int[c];
    }
    ~MinHeap()
    {
        delete[] arr;
    }
    int Search(int value)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (arr[i] == value)
            {
                cout << "\n------VALUE FOUND IN HEAP AT INDEX :--->";
                return i;
            }
        }
        cout << "\n------VALUE NOT FOUND------ " << endl;
        return -1;
    }
    void display()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int getMin()
    {
        return arr[0];
    }
    int size()
    {
        return heap_size;
    }
    void insert(int value)
    {
        if (heap_size == capacity)
        {
            cout << "\n------HEAP OVERFLOW-----" << endl;
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        arr[i] = value;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swapp(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    int extractMin()
    {
        if (heap_size == 0)
            return INT_MAX; // predefined smallest value //heap empty
        if (heap_size == 1)
        {
            heap_size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heap_size - 1]; // last element insert at root
        heap_size--;                 // reduce the size
        MinHeapify(0);
        return root;
    }
    void MinHeapify(int i)
    {
        int l = left(i); // left function
        int r = right(r);
        int small_index = i;
        if (l < heap_size && arr[l] < arr[i]) // first check left side then right node
            small_index = l;
        if (r < heap_size && arr[r] < arr[small_index])
            small_index = l;
        if (small_index != i) // if root node larger the swapping
        {
            swapp(arr[i], arr[small_index]);
            MinHeapify(small_index);
        }
    }
    void decreseKey(int i, int new_val)
    {
        arr[i] = new_val; //-1 store in heap
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swapp(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void deleteKey(int i)
    {
        decreseKey(i, INT_MIN);
        extractMin();
    }
};
int main()
{
    int s;
    cout << "\n-----ENTER THE SIZE OF THE HEAP:--->" << endl;
    cin >> s;
    MinHeap m(s);
    int option, val;
    do
    {
        cout << " ----------------ENTER THE CHOICE ---------------------" << endl;
        cout << " 1).INSERT THE ELEMENT " << endl;
        cout << " 2).SEARCH THE ELEMENT " << endl;
        cout << " 3).DELETE THE ELEMENT " << endl;
        cout << " 4).HEIGHT OF THE HEAP " << endl;
        cout << " 5).MINIMUM /ROOT ELEMENT OF THE HEAP" << endl;
        cout << " 6).EXTRACT the MIN ELEMENT " << endl;
        cout << " 7).DISPLAY THE HEAP VALUES " << endl;
        cout << " 8). SIZE OF THE HEAP " << endl;
        cout << " 0).TO EXIT THE PROGRAM " << endl;
        cin >> option;
        if (option == 1)
        {
            cout << " INSERT ELEMENT " << endl;
            cout << " ENTER THE ELEMENT IN HEAP " << endl;
            cin >> val;
            m.insert(val);
        }
        else if (option == 2)
        {
            cout << " SEARCH THE ELEMENT " << endl;
            cout << " ENTER THE VALUE " << endl;
            cin >> val;
            cout << m.Search(val);
        }
        else if (option == 3)
        {
            cout << " DELETE THE ELEMENT FROM THE HEAP " << endl;
            cout << " ENTER THE ELEMENT AT INDEX " << endl;
            cin >> val;
            m.deleteKey(val);
        }
        else if (option == 4)
        {
            cout << " HEIGHT OF THE HEAP IS " << m.height() << endl;
        }
        else if (option == 5)
        {
            cout << " MINIMUM ELEMENT OF THE HEAP " << endl;
            cout << m.getMin();
        }
        else if (option == 6)
        {
            cout << " EXTRACT MIN VALUE " << endl;
            cout << m.extractMin() << endl;
        }
        else if (option == 7)
        {
            cout << " DISPLAY THE HEAP VALUE " << endl;
            m.display();
        }
        else if (option == 8)
        {
            cout << " NO OF ELEMENT IN THE HEAP IS " << m.size() << endl;
        }
    } while (option != 0);
    return 1;
}