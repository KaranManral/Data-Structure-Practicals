// WAP to implement insertion,deletion,searching and concatination in a doubly linked list

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
void insertStart(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}
void insert(Node *prev_node, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
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
    new_node->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
}
int removeStart(Node **head)
{
    Node *temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        *head = temp->next;
        (temp->next)->prev = NULL;
    }
    int t = temp->data;
    delete temp;
    return t;
}
void remove(Node **head, int data)
{
    Node *temp = *head;
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Data not found" << endl;
        return;
    }
    else if (temp->prev == NULL && temp->next == NULL)
    {
        *head = NULL;
    }
    else if (temp->prev == NULL)
    {
        *head = temp->next;
        (temp->next)->prev = NULL;
    }
    else if (temp->next == NULL)
    {
        (temp->prev)->next = NULL;
    }
    else
    {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
    }
    delete temp;
}
int removeLast(Node **head)
{
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev == NULL && temp->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        (temp->prev)->next = NULL;
    }
    int t = temp->data;
    delete temp;
    return t;
}
Node *search(Node **head, int data)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
Node *concat(Node **head1, Node **head2)
{
    if (*head1 == NULL)
        return *head2;
    else if (*head2 == NULL)
        return *head1;
    else
    {
        Node *temp = *head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = *head2;
        (temp->next)->prev = temp;
        return *head1;
    }
}
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
int main()
{
    int ch, runAgain = 1;
    Node *head = NULL;
    while (runAgain == 1)
    {
        cout << "Enter the choice\n1 to insert data at start of Doubly Linked List\n2 to insert data in a position in Doubly Linked List\n3 to insert data at end of Doubly Linked List\n4 to delete data from start of Doubly Linked List\n5 to delete data from a position in Doubly Linked List\n6 to remove element from the end of Doubly Linked List\n7 to search data in Doubly Linked List\n8 to concat two Doubly Linked Lists" << endl;
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
            cout << "Enter the i'th position(starting from 1) where data has to be enterred" << endl;
            int i, count = 1, data;
            cin >> i;
            if (i <= 1)
            {
                cout << "You are trying to enter data at start. Please use prior option to insert at start" << endl;
                break;
            }
            Node *temp = head;
            Node *prev_node = NULL;
            while (temp != NULL)
            {
                count++;
                if (i == count)
                {
                    prev_node = temp;
                    cout << "Enter the data" << endl;
                    cin >> data;
                    insert(prev_node, data);
                    cout << "\nLinked-List Now:" << endl;
                    display(head);
                    break;
                }
                temp = temp->next;
            }
            if (i > count + 1)
            {
                cout << "Linked List size not enough" << endl;
                break;
            }
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
            cout << "Data Removed from start of Doubly LinkedList:" << removedData << endl;
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
            cout << "Data Removed from end of Doubly LinkedList:" << removedData << endl;
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