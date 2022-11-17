// WAP to program to implement a stack using array

#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr;
    int n;
    int t;

public:
    Stack()
    {
        n = 0;
        t = -1;
        arr = new int[n];
    }
    Stack(int size)
    {
        n = size;
        t = -1;
        arr = new int[n];
    }
    void push(int data);
    int pop();
    void display();
};
void Stack::push(int data)
{
    if (t == n - 1)
        cout << "OVERFLOW" << endl;
    else
    {
        arr[++t] = data;
    }
}
int Stack::pop()
{
    int temp = -999;
    if (t < 0)
        cout << "UNDERFLOW" << endl;
    else
    {
        temp = arr[t];
        arr[t--] = 0;
    }
    return temp;
}
void Stack::display()
{
    int k;
    if (t < 0)
        cout << "UNDERFLOW" << endl;
    else
    {
        cout << "STACK:";
        for (k = t; k >= 0; k--)
            cout << arr[k] << " ";
        cout << endl;
    }
}
int main()
{
    int size;
    cout << "Enter the size of stack" << endl;
    cin >> size;
    Stack ob(size);
    int ch = 0;
    while (1 > 0)
    {
        cout << "\nEnter the choice\n1 to push in stack\n2 to pop from stack\n3 to print stack\n4 to Exit Program " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter number to be pushed in stack" << endl;
            int v;
            cin >> v;
            ob.push(v);
            break;
        }
        case 2:
        {
            ob.pop();
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
