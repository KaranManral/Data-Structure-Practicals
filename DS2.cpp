// WAP to implement Binary Search

#include <iostream>

using namespace std;

int binSearch(int *a, int l, int u, int s)
{
    if (l > u)
        return -1;
    else
    {
        int p = (l + (u - 1)) / 2;
        if (a[p] == s)
            return p;
        else if (s < a[p])
            return binSearch(a, l, p - 1, s);
        else
            return binSearch(a, p + 1, u, s);
    }
}
int main()
{
    int n, *arr, s;
    cout << "Enter the size of Array" << endl;
    cin >> n;
    arr = new int[n];
    cout << "Enter the " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the element to be searched" << endl;
    cin >> s;
    int bs = binSearch(arr, 0, n, s);
    if (bs == -1)
        cout << "Element not found in array" << endl;
    else
        cout << "Element found at " << bs << " position" << endl;
    return 1;
}
