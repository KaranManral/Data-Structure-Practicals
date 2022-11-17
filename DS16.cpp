// WAP to implement postfix/prefix

#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    unsigned capacity;
    int *array;
};

Stack *createStack(unsigned capacity)
{
    Stack *stack = new Stack();

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];

    if (!stack->array)
        return NULL;

    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int peek(Stack *stack)
{
    return stack->array[stack->top];
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(Stack *stack, int op)
{
    stack->array[++stack->top] = op;
}

int evaluatePostfix(string exp)
{
    Stack *stack = createStack(exp.length());
    int i;
    if (!stack)
        return -1;

    for (i = 0; exp[i]; ++i)
    {
        if (exp[i] == ' ')
            continue;

        else if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            push(stack, num);
        }

        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}

double evaluatePrefix(string exp)
{
    Stack *stack = createStack(exp.length());

    if (!stack)
        return -1;

    for (int j = stack->capacity - 1; j >= 0; j--)
    {
        if (exp[j] == ' ')
            continue;
        if (isdigit(exp[j]))
        {
            double num = 0, i = j;
            while (j < stack->capacity && isdigit(exp[j]))
                j--;
            j++;

            for (int k = j; k <= i; k++)
                num = num * 10 + double(exp[k] - '0');

            push(stack, num);
        }
        else
        {
            int o1 = pop(stack);
            int o2 = pop(stack);

            switch (exp[j])
            {
            case '+':
                push(stack, o1 + o2);
                break;
            case '-':
                push(stack, o1 - o2);
                break;
            case '*':
                push(stack, o1 * o2);
                break;
            case '/':
                push(stack, o1 / o2);
                break;
            }
        }
    }

    return pop(stack);
}
int main()
{
    int ch;
    cout << "Enter the choice \n1 for Postfix Evaluation\n2 for Prefix Evaluation\n3 to Exit Program " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        cout << "Enter the expression, each operator/operand separated by spaces " << endl;
        string exp;
        while (exp.length() == 0)
            getline(cin, exp);
        cout << "Evaluated Answer is " << evaluatePostfix(exp) << endl;
        break;
    }
    case 2:
    {
        cout << "Enter the expression, each operator/operand separated by spaces " << endl;
        string exp;
        while (exp.length() == 0)
            getline(cin, exp);
        cout << "Evaluated Answer is " << evaluatePrefix(exp) << endl;
        break;
    }
    case 3:
    {
        exit(0);
        break;
    }
    default:
        cout << "Wrong Choice Enterred" << endl;
    }
    return 0;
}