#include <iostream>
#include <string>
using namespace std;

template <class ItemType>
class stack
{
private:
    int MaxSize, top;
    ItemType* item;

public:
    stack(int size)
    {
        MaxSize = size;
        item = new ItemType[MaxSize];
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MaxSize - 1);
    }

    void push(ItemType newitem)
    {
        if (isFull())
            cout << "Stack Overflow ";
        else
        {
            top++;
            item[top] = newitem;
        }
    }

    ItemType pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow";
            return -1; // Assuming ItemType is int
        }
        else
            return (item[top--]);
    }

    ItemType getTop()
    {
        return (item[top]);
    }

    void Display()
    {
        for (int i = top; i > -1; i--)
            cout << item[i] << "\t";
        cout << endl;
    }

    ~stack()
    {
        delete[] item;
    }
};

// Function to evaluate a given postfix expression
int postfixeval(string exp)
{
    stack<int> s(exp.length());
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            s.push(exp[i] - '0');
        }
        else
        {
            int n1 = s.pop();
            int n2 = s.pop();
            if (exp[i] == '+')
                s.push(n2 + n1);
            else if (exp[i] == '-')
                s.push(n2 - n1);
            else if (exp[i] == '*')
                s.push(n2 * n1);
            else if (exp[i] == '/')
                s.push(n2 / n1);
            else if (exp[i] == '%')
                s.push(n2 % n1);
        }
    }
    return s.getTop();
}

// Function to evaluate a given prefix expression
int prefixeval(string exp)
{
    stack<int> s(exp.length());
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            s.push(exp[i] - '0');
        }
        else
        {
            int n2 = s.pop();
            int n1 = s.pop();
            if (exp[i] == '+')
                s.push(n2 + n1);
            else if (exp[i] == '-')
                s.push(n2 - n1);
            else if (exp[i] == '*')
                s.push(n2 * n1);
            else if (exp[i] == '/')
                s.push(n2 / n1);
            else if (exp[i] == '%')
                s.push(n2 % n1);
        }
    }
    return s.getTop();
}

int main()
{
    // Example usage of the stack and expression evaluation functions

    // Create a stack of integers
    stack<int> s(15);

    // Push some elements into the stack
    s.push(5);
    s.push(10);
    s.push(15);

    // Display the stack
    cout << "Stack elements: ";
    s.Display();

    // Perform postfix evaluation
    string postfixExp = "35*2+";
    int result = postfixeval(postfixExp);
    cout << "Postfix expression evaluation: " << result << endl;

    // Perform prefix evaluation
    string prefixExp = "-+7*452";
    result = prefixeval(prefixExp);
    cout << "Prefix expression evaluation: " << result << endl;

    return 0;
}
