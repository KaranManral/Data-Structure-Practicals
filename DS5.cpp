// WAP to implement insertion,deletion,searching and concatination in a circular linked list

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void insertStart(Node **head, int data)
{
    if (*head != NULL)
    {
        Node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = *head;
        *head = new_node;
        temp->next = *head;
    }
    else
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = new_node;
        *head = new_node;
    }
}
void insert(Node *prev_node, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void insertLast(Node **head, int data)
{
    if (*head == NULL)
    {
        insertStart(head, data);
        return;
    }
    Node *temp = *head;
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = temp;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
int removeStart(Node **head)
{
    if ((*head)->next == *head)
    {
        int t = (*head)->data;
        *head = NULL;
        return t;
    }
    Node *last = *head;
    while (last->next != *head)
        last = last->next;
    Node *temp = *head;
    *head = temp->next;
    last->next = *head;
    int t = temp->data;
    delete temp;
    return t;
}
Node *search(Node **head, int data)
{
    if (*head == NULL)
        return NULL;
    Node *temp = *head;
    do
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    } while (temp != *head);
    return NULL;
}
void remove(Node **head, int data)
{
    if (search(head, data) == NULL)
    {
        cout << "Given element not in the list." << endl;
        return;
    }
    if ((*head)->next == *head && (*head)->data == data)
        *head = NULL;
    else
    {
        if ((*head)->data == data)
        {
            removeStart(head);
            return;
        }
        Node *temp = *head;
        Node *prev_node = NULL;
        do
        {
            prev_node = temp;
            temp = temp->next;
        } while (temp != *head && temp->data != data);
        prev_node->next = temp->next;
        delete temp;
    }
}
int removeLast(Node **head)
{
    if ((*head)->next == *head)
    {
        int t = (*head)->data;
        *head = NULL;
        return t;
    }
    else
    {
        Node *temp = (*head)->next;
        Node *prev_node = *head;
        while (temp->next != *head)
        {
            prev_node = temp;
            temp = temp->next;
        }
        prev_node->next = *head;
        int t = temp->data;
        delete temp;
        return t;
    }
}
Node *concat(Node **head1, Node **head2)
{
    if (*head1 == NULL)
        return *head2;
    else if (*head2 == NULL)
        return *head1;
    else
    {
        Node *temp = (*head1)->next;
        Node *temp1 = (*head2)->next;
        while (temp->next != *head1)
        {
            temp = temp->next;
        }
        while (temp1->next != *head2)
        {
            temp1 = temp1->next;
        }
        temp->next = *head2;
        temp1->next = *head1;
        return *head1;
    }
}
void display(Node *n)
{
    if (n == NULL)
    {
        cout << "List Empty" << endl;
        return;
    }
    Node *temp = n;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != n);
}
int main()
{
    int ch, runAgain = 1;
    Node *head = NULL;
    while (runAgain == 1)
    {
        cout << "Enter the choice\n1 to insert data at start of Circular Linked List\n2 to insert data in a position in Circular Linked List\n3 to insert data at end of Circular Linked List\n4 to delete data from start of Circular Linked List\n5 to delete data from a position in Circular Linked List\n6 to remove element from the end of Circular Linked List\n7 to search data in Circular Linked List\n8 to concat two Circular Linked Lists" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter data to be enterred at start" << endl;
            int data;
            cin >> data;
            insertStart(&head, data);
            cout << "\nLinked-List Now:" << endl;
            display(head);
            break;
        }
        case 2:
        {
            cout << "Enter the element y after which data has to be enterred" << endl;
            int i, count = 1, data;
            cin >> i;
            Node *prev_node = search(&head, i);
            if (prev_node == NULL)
            {
                cout << "\n Given element do not exist in list" << endl;
                break;
            }
            cout << "Enter the data to be enterred" << endl;
            cin >> data;
            insert(prev_node, data);
            cout << "\nLinked-List Now:" << endl;
            display(head);
            break;
        }
        case 3:
        {
            cout << "Enter data to be enterred at end" << endl;
            int data;
            cin >> data;
            insertLast(&head, data);
            cout << "\nLinked-List Now:" << endl;
            display(head);
            break;
        }
        case 4:
        {
            if (head == NULL)
            {
                cout << "List already empty" << endl;
                break;
            }
            int removedData = removeStart(&head);
            cout << "\nData Removed from start of Circular LinkedList:" << removedData << endl;
            cout << "\nLinked-List Now:" << endl;
            display(head);
            break;
        }
        case 5:
        {
            if (head == NULL)
            {
                cout << "List Empty" << endl;
                break;
            }
            cout << "Enter the data to be deleted" << endl;
            int data;
            cin >> data;
            remove(&head, data);
            cout << "\nLinked-List Now:" << endl;
            display(head);
            break;
        }
        case 6:
        {
            if (head == NULL)
            {
                cout << "List Already Empty" << endl;
                break;
            }
            int removedData = removeLast(&head);
            cout << "\nData Removed from end of Circular LinkedList:" << removedData << endl;
            cout << "\nLinked-List Now:" << endl;
            display(head);
            break;
        }
        case 7:
        {
            cout << "Enter the data to be searched" << endl;
            int data;
            cin >> data;
            Node *temp = search(&head, data);
            if (temp == NULL)
                cout << "Data not found" << endl;
            else
                cout << "Data Found at pointer:" << temp << endl;
            break;
        }
        case 8:
        {
            Node *head1 = NULL;
            int data, temporary = 1;
            while (temporary == 1)
            {
                cout << "Enter data to be enterred in second Linked List" << endl;
                cin >> data;
                insertStart(&head1, data);
                cout << "To continue enterring data press 1, else press 0" << endl;
                cin >> temporary;
            }
            Node *merged = concat(&head, &head1);
            cout << "\nMerged Linked-List:" << endl;
            display(merged);
            break;
        }
        }
        cout << "\nEnter 1 to continue,0 to exit" << endl;
        cin >> runAgain;
    }
    return 1;
}