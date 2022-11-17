#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
};

class CQueue
{
    Node *front;
    Node *rear;

public:
    CQueue()
    {
        front = rear = NULL;
    }
    void enQueue(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        if (front == NULL)
            front = temp;
        else
            rear->link = temp;

        rear = temp;
        rear->link = front;
    }

    int deQueue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value;
        if (front == rear)
        {
            value = front->data;
            delete front;
            front = NULL;
            rear = NULL;
        }
        else
        {
            Node *temp = front;
            value = temp->data;
            front = front->link;
            rear->link = front;
            delete temp;
        }

        return value;
    }

    void display()
    {
        Node *temp = front;
        cout << "Elements in Circular Queue are: ";
        while (temp->link != front)
        {
            cout << (temp->data) << " ";
            temp = temp->link;
        }
        cout << (temp->data) << endl;
    }
};

int main()
{
    CQueue ob;
    int ch = 0;
    while (1)
    {
        cout << "\nEnter the choice\n1 to insert in CQueue\n2 to delete from CQueue\n3 display CQueue\n4 to Exit Program " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter number to be inserted" << endl;
            int v;
            cin >> v;
            ob.enQueue(v);
            break;
        }
        case 2:
        {
            int temp = ob.deQueue();
            cout << "Element deleted from CQueue is " << temp << endl;
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
