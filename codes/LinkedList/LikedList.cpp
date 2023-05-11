#include <iostream>
using namespace std;

template <class ItemType>
class LinkedList
{
private:
    struct Node {
        ItemType data;
        Node* next;
    };
    int length;
    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = tail = NULL;
        length = 0;
    }

    Node* getHead()
    {
        return head;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insertAtFirst(ItemType element)
    {
        Node* newNode = new Node;
        newNode->data = element;
        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void insertAtLast(ItemType element)
    {
        Node* newNode = new Node;
        newNode->data = element;
        if (isEmpty())
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        length++;
    }

    void insertAtPos(int pos, ItemType element)
    {
        Node* newNode = new Node;
        newNode->data = element;
        if (pos < 0 || pos > length)
        {
            cout << "Out of Range\n";
            return;
        }
        if (pos == 0)
        {
            insertAtFirst(element);
            return;
        }
        if (pos == length)
        {
            insertAtLast(element);
            return;
        }

        Node* cur = head;
        for (int i = 1; i < pos; i++)
            cur = cur->next;

        newNode->next = cur->next;
        cur->next = newNode;
        length++;
    }

    void removeFirst()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Remove.....!\n";
            return;
        }
        if (length == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* cur = head;
            head = head->next;
            delete cur;
        }
        length--;
    }

    void removeLast()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Remove.....!\n";
            return;
        }
        if (length == 1)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Node* cur = head;
            while (cur->next != tail)
                cur = cur->next;

            tail = cur;
            cur = cur->next;
            delete cur;
            tail->next = NULL;
        }
        length--;
    }

    void remove(ItemType element)
    {
        Node* cur = head;
        if (isEmpty())
        {
            cout << "Empty List Can't Remove.....!\n";
            return;
        }
        if (cur->data == element)
        {
            removeFirst();
            return;
        }

        while (cur->next != NULL && cur->next->data != element)
            cur = cur->next;

        if (cur->next == tail)
        {
            cur = cur->next;
            if (cur->data == element)
                removeLast();
            else
                cout << "Not found......!\n";
        }
        else
        {
            Node* temp = cur->next;
            cur->next = temp->
                    next;
            delete temp;
            length--;
        }
    }

    void removeAtPos(int pos)
    {
        if (pos < 0 || pos >= length)
        {
            cout << "Out Of Range......!\n";
            return;
        }
        if (isEmpty())
        {
            cout << "Empty List Can't Remove.....!\n";
            return;
        }
        if (pos == 0)
        {
            removeFirst();
            return;
        }
        if (pos == length - 1)
        {
            removeLast();
            return;
        }

        Node* cur = head;
        for (int i = 1; i < pos; i++)
            cur = cur->next;

        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;

        length--;
    }

    void reverse()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Reverse.....!\n";
            return;
        }
        if (length == 1)
        {
            print();
            return;
        }

        Node* prev = NULL;
        Node* cur = head;
        Node* nxt = cur->next;
        while (nxt != NULL)
        {
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        head = cur;
    }

    int search(ItemType element)
    {
        Node* cur = head;
        int pos = 0;
        while (cur != NULL)
        {
            if (cur->data == element)
                return pos;

            cur = cur->next;
            pos++;
        }
        cout << "Not found.......!\n";
        return -1;
    }

    void rotate()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "No rotation possible!\n";
            return;
        }

        Node* currNode = head;
        head = head->next;
        currNode->next = NULL;
        tail->next = currNode;
        tail = currNode;

        cout << "List rotated successfully!\n";
    }

    void print()
    {
        Node* cur = head;
        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    Node* InsertNode(int index, ItemType item)
    {
        Node* Newnode = new Node;
        Newnode->data = item;
        if (index < 0 ||index > length)
        {
            cout << index << " out of Range\n";
            return NULL;
        }
        Node* cur = head;
        int curIndex = 1;
        if (isEmpty() || index == 0)
        {
            Newnode->next = head;
            head = Newnode;
        }
        else
        {
            while (index > curIndex)
            {
                cur = cur->next;
                curIndex++;
            }
            Newnode->next = cur->next;
            cur->next = Newnode;
        }
        length++;

        return Newnode;
    }

    int FindNode(ItemType item)
    {
        Node* cur = head;
        int curIndex = 0;  ///  curIndex = 1;
        while (cur->data != item)
        {
            cur = cur->next;
            curIndex++;
        }
        if (cur)
            return curIndex;
        return 0;
    }

    int DeleteNode(ItemType item)
    {
        Node* pre = NULL;
        Node* cur = head;
        int curIndex = 0;
        while (cur->data!=item)
        {
            pre = cur;
            cur = cur->next;
            curIndex++;
        }
        if (cur)
        {
            if (pre)
            {
                pre->next = cur->next;
                delete cur;
            }
            else
            {
                head = cur->next;
                delete cur;
            }
            return curIndex;
        }
        return 0;
    }

    ~LinkedList()
    {
        Node* cur = head, * Next = NULL;
        while (cur)
        {
            Next = cur->next;
            delete cur;
            cur = Next;
        }
    }

    int lengthRec(Node* Head)
    {
        if (Head == NULL)
            return 0;
        return lengthRec(Head->next) + 1;
    }

    void rearrange()
    {
        Node* list = head;
        Node* p, * q;
        int temp;
        if (!list || !list->next)
            return;
        p = list;
        q = list->next;
        while (q)
        {
            temp = p->data;
            p->data = q->data;
            q->data = temp;
            p = q->next;
            q = p->next;
        }
    }

    bool Palindrome()
    {
        LinkedList<ItemType> list2;
        Node* cur = head;
        while (cur)
        {
            list2.InsertNode(0, cur->data);
            cur = cur->next;
        }
        Node* cur2 = list2.head;
        cur = head;
        while (cur)
        {
            if (cur->data != cur2->data)
                return false;
            cur = cur->next;
            cur2 = cur2->next;
        }
        return true;
    }

};


int main()
{
    LinkedList<int> list;
    list.insertAtLast(1);
    list.insertAtLast(2);
    list.insertAtLast(3);
    list.insertAtLast(4);
    list.insertAtLast(5);

    cout << "Original list: ";
    list.print();

    // Testing the additional functions
    cout << "Inserting node at index 2 with value 10\n";
    list.InsertNode(2, 10);
    cout << "List after insertion: ";
    list.print();

    cout << "Finding node with value 4: ";
    int index = list.FindNode(4);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found\n";

    cout << "Deleting node with value 3\n";
    list.DeleteNode(3);
    cout << "List after deletion: ";
    list.print();

    cout << "Length of the list (recursive): " << list.lengthRec(list.getHead()) << endl;

    cout << "Rearranging the list\n";
    list.rearrange();
    cout << "List after rearranging: ";
    list.print();

    cout << "Checking if the list is a palindrome: ";
    if (list.Palindrome())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

