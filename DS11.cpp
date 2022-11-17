#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int item)
    {
        data = item;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root, int item)
{
    if (root == NULL)
    {
        return new Node(item);
    }
    if (item < root->data)
    {
        root->left = insert(root->left, item);
    }
    else
    {
        root->right = insert(root->right, item);
    }
    return root;
}
Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteBST(Node *root, int item)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (item < root->data)
    {
        root->left = deleteBST(root->left, item);
    }
    else if (item > root->data)
    {
        root->right = deleteBST(root->right, item);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
        return root;
    }
    return root;
}
Node *search(Node *root, int item)
{
    if (root == NULL)
        return NULL;
    if (root->data == item)
        return root;
    if (root->data > item)
        return search(root->left, item);
    if (root->data < item)
        return search(root->right, item);
    return root;
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "\t";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\t";
}
void lvlOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << "\t";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int Lheight = height(root->left);
    int Rheight = height(root->right);
    return (Lheight, Rheight) + 1;
}
int main()
{
    Node *root = NULL;
    int item, n, y, h;
    char ch = 'y';
    cout << "\n\n\n\t\t==================================================================================\n ";
    cout << "\t\t____BINARY SEARCH TREE___\n";
    cout << "\t\t==================================================================================\n\n\n ";
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nPress 1: Insert an Element x.";
        cout << "\nPress 2: Delete an Element x.";
        cout << "\nPress 3: Search an Element x in the BST and change its value to y and then place the node with value y at its appropriate position in the BST.";
        cout << "\nPress 4: Display the Elements of the BST in Preorder, Inorder and Postorder traversal.";
        cout << "\nPress 5: Display the Elements of the BST in Level-by-Level traversal.";
        cout << "\nPress 6: Display the Height of the BST.";
        cout << "\nPress 7:To Exit.";
        cout << "\n\nEnter Your Choice: ";
        cin >> n;
        if (n == 1)
        {
            cout << "\nEnter a element you want to insert --> ";
            cin >> item;
            root = insert(root, item);
            cout << "\n\n-----------> Element has successfully inserted.........\n\n ";
        }
        else if (n == 2)
        {
            cout << "\nEnter a element you want to delete --> ";
            cin >> item;
            inorder(root);
            root = deleteBST(root, item);
            cout << "\n\n----------->Element has successfully deleted.........\n\n ";
            inorder(root);
        }
        else if (n == 3)
        {
            cout << "\nEnter a element you want to Search --> ";
            cin >> item;
            if (search(root, item) == NULL)
            {
                cout << "\n\n\tElement does not exist in the Binary Search Tree.........\n\n ";
            }
            else
            {
                cout << "\n\n\tElement--> " << item << " exist in the Binary Search Tree.........\n\n ";
                cout << "\nEnter a element you want to insert in place of existing element-- >";
                cin >> y;
                root = deleteBST(root, item);
                root = insert(root, y);
            }
        }
        else if (n == 4)
        {
            cout << "\n\n\t>>>>>>>>>>>>>>>>PREORDER TRAVERSAL..........\n\n\t\t\t ";
            preorder(root);
            cout << "\n\n\n\t\t>>>>>>>>>>>>>>>>INORDER TRAVERSAL..........\n\n\t\t\t\t ";
            inorder(root);
            cout << "\n\n\n\t\t\t>>>>>>>>>>>>>>>>POSTORDER TRAVERSAL..........\n\n\t\t\t\t\t ";
            postorder(root);
            cout << "\n\n";
        }
        else if (n == 5)
        {
            cout << "\n\n\t>>>>>>>>>>>>>>>>LEVEL BY LEVEL ORDER TRAVERSAL..........\n\n\t\t\t ";
            lvlOrder(root);
            cout << "\n\n";
        }
        else if (n == 6)
        {
            h = height(root);
            cout << "\n\n---------> Height of BINARY SEARCH TREE --> " << h;
        }
        else if (n == 7)
        {
            exit(100);
        }
        else
        {
            cout << "\n\nWrong CHOICE ENTERED BY USER!...........";
        }
        cout << "\n\n\tEnter y/Y for continue the Program --> ";
        cin >> ch;
    }
    return 0;
}