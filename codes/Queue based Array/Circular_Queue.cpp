#include <iostream>
using namespace std;

template <class ItemType>
class CircularQueue
{
private:
    int front, rear, MaxSize, counter;
    ItemType* items;

public:
    CircularQueue(int size)
    {
        MaxSize = size;
        front = 0;
        rear = MaxSize - 1;
        items = new ItemType[MaxSize];
        counter = 0;
    }
    bool isEmpty()
    {
        return (counter == 0);
    }
    bool isFull()
    {
        return (counter == MaxSize);
    }
    void enqueue(ItemType newitem)
    {
        if (!isFull())
        {
            rear = (rear + 1) % MaxSize;
            items[rear] = newitem;
            counter++;
        }
        else
            cout << "Queue OverFlow....!" << endl;
    }
    void dequeue()
    {
        if (!isEmpty())
        {
            front = (front + 1) % MaxSize;
            counter--;
        }
        else
            cout << "Queue UnderFlow....!" << endl;
    }
    ItemType FrontQueue()
    {
        return (items[front]);
    }
    ItemType RearQueue()
    {
        return (items[rear]);
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = front; i != rear; i = (i + 1) % MaxSize)
            {
                cout << items[i] << " ";
            }
            cout << items[rear] << "\n";
        }
        else
            cout << "Queue is Empty......!";
    }
    void print()
    {
        if (!isEmpty())
        {
            for (int i = 1; i <= counter; i++)
                cout << items[(front + i) % MaxSize] << " ";
        }
    }
    int search(ItemType element)
    {
        if (!isEmpty())
        {
            int pos = -1;
            for (int i = front; i != rear; i = (i + 1) % MaxSize)
            {
                if (element == items[i])
                {
                    pos = i;
                    return pos;
                }
            }
            if (pos == -1)
            {
                if (element == items[rear])
                {
                    int pos = rear;
                    return pos;
                }
            }
            else
                cout << "Element is not found.....!" << endl;
        }
        else
            cout << "Queue is Empty......!" << endl;
    }
    ~CircularQueue()
    {
        delete[] items;
    }
};

int main()
{
    CircularQueue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    cout << "Front element: " << q.FrontQueue() << endl;
    cout << "Rear element: " << q.RearQueue() << endl;
    cout << "Is the queue full? " << q.isFull() << endl;
    cout << "Queue elements: ";
    q.display();

    return 0;
}
