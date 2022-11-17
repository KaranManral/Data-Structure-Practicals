// WAP to implement linear search
#include <iostream>
using namespace std;
int linSearch(int *a, int n, int s)
{
    n--;
    if (n >= 0)
    {
        if (s == a[n])
            return n;
        else
            return linSearch(a, n, s);
    }
    else
        return -1;
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
    int ls = linSearch(arr, n, s);
    if (ls == -1)
        cout << "Element not found in array" << endl;
    else
        cout << "Element found at " << ls << " position" << endl;
    return 1;
}
