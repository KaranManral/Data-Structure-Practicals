#include <iostream>
using namespace std;
bool checkSymmetric(int **m, int size) // Function to check if relation is symmetric or not
{
    int B[size][size];
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            B[r][c] = m[c][r];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (m[i][j] != B[i][j])
                return false;
    return true;
}
void displayDiagonal(int **mat1, int n)
{
    int mat[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mat[i] = mat1[i][j];
            }
        }
    }

    cout << " 1-D Diagonal array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mat[i] << " ";
    }

    cout << "\nDisplaying the Matrix" << endl;
    for (int i = 0; i < n; i++) // To Print Diagonal Matrix
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << mat[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void displayUpperTriangle(int **mat1, int n)
{
    int mat[n * (n + 1) / 2]; // To Print Upper Traingluar Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                mat[(j + 1) * j / 2 + i] = mat1[i][j];
            }
        }
    }
    cout << "1-D Upper traingle array " << endl;
    for (int j = 0; j < n * (n + 1) / 2; j++)
    {
        cout << mat[j] << " ";
    }
    cout << endl;
}
void displayLowerTriangle(int **mat1, int n)
{
    int mat[n * (n + 1) / 2]; // to Print lower Trainagular Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                mat[(i + 1) * (i) / 2 + (j)] = mat1[i][j];
            }
        }
    }
    cout << "1-D Lower traingle array " << endl;
    for (int j = 0; j < n * (n + 1) / 2; j++)
    {
        cout << mat[j] << " ";
    }
    cout << endl;
}
void displaySymmetric(int **mat1, int n)
{
    if (checkSymmetric(mat1, n))
    {
        cout << "\n\nMatrix is symmetric\n";
        int mat[n * n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[(i * n) + j] = mat1[i][j];
            }
        }

        cout << " 1-D Symmetric array " << endl;
        for (int i = 0; i < n * n; i++)
        {
            cout << mat[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "\nMatrix is not symmetric\n";
}
int main()
{
    cout << " Enter the Size of the Square Matrix ";
    int n;
    cin >> n;
    int **mat1 = new int *[n];
    for (int i = 0; i < n; ++i)
        mat1[i] = new int[n];
    cout << "Enter elements of Square Matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat1[i][j];
        }
    }

    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nEnter the choice \n1.Diagonal Matrix \n2.Upper Traingle\n3.Lower Traingle\n4.Symmetric\n ";
        int o;
        cin >> o;
        if (o == 1)
        {
            displayDiagonal(mat1, n);
        }
        else if (o == 2)
        {
            displayUpperTriangle(mat1, n);
        }
        else if (o == 3)
        {
            displayLowerTriangle(mat1, n);
        }
        else
            displaySymmetric(mat1, n);
        cout << "Enter Y or y for Continue: ";
        cin >> ch;
    }
}