#include <iostream>
using namespace std;
class CQueue
{
private:
    int *q;
    int f, r, n;

public:
    CQueue()
    {
        n = 5;
        f = r = -1;
        q = new int[n];
    }
    CQueue(int a)
    {
        n = a;
        f = r = -1;
        q = new int[n];
    }
    void insert(int v)
    {
        if ((f == 0 && r == n - 1) || (f == r + 1))
            cout << "OverFlow" << endl;
        else if (r < 0)
        {
            f = r = 0;
            q[r] = v;
        }
        else if (r == n - 1)
        {
            r = 0;
            q[r] = v;
        }
        else
            q[++r] = v;
    }
    int remove()
    {
        int w = -999;
        if (f < 0)
            cout << "UnderFlow" << endl;
        else if (f == r)
        {
            w = q[f];
            f = r = -1;
        }
        else if (f == n - 1)
        {
            w = q[f];
            f = 0;
        }
        else
            w = q[f++];
        return w;
    }
    void display()
    {
        int k;
        if (f < 0)
            cout << "UnderFlow" << endl;
        else
        {
            if (f <= r)
            {
                for (k = f; k <= r; k++)
                    cout << q[k] << " ";
                cout << endl;
            }

            else
            {
                for (k = f; k < n; k++)
                    cout << q[k] << " ";
                for (k = 0; k <= r; k++)
                    cout << q[k] << " ";
                cout << endl;
            }
        }
    }
};
int main()
{
    int size;
    cout << "Enter the size of CQueue" << endl;
    cin >> size;
    CQueue ob(size);
    int ch = 0;
    while (1 > 0)
    {
        cout << "\nEnter the choice\n1 to insert in CQueue\n2 to delete from CQueue\n3 to print CQueue\n4 to Exit Program " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter number to be inserted" << endl;
            int v;
            cin >> v;
            ob.insert(v);
            break;
        }
        case 2:
        {
            int temp = ob.remove();
            cout << "Remove Element is " << temp << endl;
            break;
        }
        case 3:
        {
            ob.display();
            break;
        }
        case 4:
            exit(0);
            break;
        default:
            cout << "Wrong,choice enterred" << endl;
        }
    }
    return 1;
}
