#include <iostream>
using namespace std;

template <class ItemType>
class Queue
{
private:
    int front, rear, MaxSize;
    ItemType* items;

public:

    Queue(int size)
    {
        front = rear = -1;
        MaxSize = size;
        items = new ItemType[MaxSize];
    }

    bool isFull()
    {
        return (rear == MaxSize - 1);
    }
    bool isEmpty()
    {
        if (rear == -1 && front == -1)
            return(true);
        else if (front > rear)
            return(true);
        else
            return(false);

    }
    void enqueue(ItemType newitem)
    {
        if (!isFull())
        {
            rear++;
            items[rear]=newitem;
        }
        else
            cout << "Queue OverFlow" << endl;

        if (rear == 0)
            front++;
    }
    void dequeue()
    {
        if (!isEmpty())
            items[front++];
        else
            cout << "Queue UnderFlow" << endl;
    }

    ItemType peek()
    {
        if (!isEmpty())
            return(items[front]);
        else
            cout << "Queue UnderFlow"<<endl;
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i++)
            {
                cout << items[i] << "\t";
            }
        }
        else
            cout << "Queue UnderFlow" << endl;
    }
    ~Queue()
    {
        delete[]items;
    }

};

int main()
{
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << "Is the queue full? " << q.isFull() << endl;
    cout << "Queue elements: ";
    q.display();

    return 0;
}
