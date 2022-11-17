// WAP to implement Double Ended Queue using Linked List
#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    friend Node *createNewNode(int data);
};
Node *createNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
class Deque
{
    Node *front;
    Node *rear;
    int Size;

public:
    Deque()
    {
        front = rear = NULL;
    }

    void insertFront(int data);
    void insertRear(int data);
    int deleteFront();
    int deleteRear();
    void display();
};
void Deque::insertFront(int data)
{
    Node *newNode = createNewNode(data);

    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        if (front == NULL)
            rear = front = newNode;

        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
}

void Deque::insertRear(int data)
{
    Node *newNode = createNewNode(data);
    if (newNode == NULL)
        cout << "OverFlow\n";
    else
    {
        if (rear == NULL)
            front = rear = newNode;

        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int Deque::deleteFront()
{
    if (front == NULL)
    {
        cout << "UnderFlow\n";
        return -1;
    }
    else
    {
        Node *temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        int t = temp->data;
        delete temp;
        return t;
    }
}

int Deque::deleteRear()
{
    if (front == NULL)
    {
        cout << "UnderFlow\n";
        return -1;
    }

    else
    {
        Node *temp = rear;
        rear = rear->prev;

        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        int t = temp->data;
        delete temp;
        return t;
    }
}
void Deque::display()
{
    if (front == NULL)
        cout << "UnderFlow" << endl;
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Deque ob;
    int ch = 0;
    while (1)
    {
        cout << "\nEnter the choice\n1 to insert at front of DEQueue\n2 to insert at rear of DEQueue\n3 to delete at front of DEQueue\n4 to delete at rear of DEQueue\n5 to display elements of DEQueue\n6 to Exit Program " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter number to be inserted" << endl;
            int v;
            cin >> v;
            ob.insertFront(v);
            break;
        }
        case 2:
        {
            cout << "Enter number to be inserted" << endl;
            int v;
            cin >> v;
            ob.insertRear(v);
            break;
        }
        case 3:
        {
            int temp = ob.deleteFront();
            cout << "Element deleted from front is " << temp << endl;
            break;
        }
        case 4:
        {
            int temp = ob.deleteRear();
            cout << "Element deleted from rear is " << temp << endl;
            break;
        }
        case 5:
        {
            cout << "Current DEQueue is: ";
            ob.display();
            break;
        }
        case 6:
            exit(0);
            break;
        default:
            cout << "Wrong,choice enterred" << endl;
        }
    }
    return 1;
}
