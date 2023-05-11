#include <iostream>
using namespace std;

template<typename ItemType>
struct Node {
public:
	ItemType data;
	Node* next;
	Node* prev;
};

//Doubly Linked Lists with Dummy Head Node
template<typename ItemType>
class DoublyLinkedList {
private:
	Node<ItemType>* head;
	void createHead();

public:
	DoublyLinkedList(void);


	~DoublyLinkedList(void);

	bool isEmpty();

	Node<ItemType>* searchNode(ItemType item);

	void insertNode(ItemType item);

	void deleteNode(ItemType item);

	void print();

	void printReversed();

	void Union(DoublyLinkedList<ItemType> l);
};

template <typename ItemType>
void DoublyLinkedList<ItemType>::createHead()
{
	head = new Node<ItemType>;
	head->next = head;
	head->prev = head;
}

template <typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty()
{
	return (head->next == head);
}

template <typename ItemType>
Node<ItemType>* DoublyLinkedList<ItemType>::searchNode(ItemType item)
{
	Node<ItemType>* Cur = head->next;

	while (Cur != head) {

		if (Cur->data == item)
			return Cur;

		if ((Cur->data) < item)
			Cur = Cur->next;
		else
			break;
	}

	return NULL;
}

template <typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
	createHead();
}

template <typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
	Node<ItemType>* cur = head->next;
	while (cur != head) {
		Node<ItemType>* nextNode = cur->next;
		delete cur;
		cur = nextNode;
	}
	delete head;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::insertNode(ItemType item)
{
	Node<ItemType>* New = NULL;
	Node<ItemType>* Cur = NULL;
	New = new Node<ItemType>;
	New->data = item;

	Cur = head->next;
	while (Cur != head) { //position Cur for insertion
		if ((Cur->data) < item)
			Cur = Cur->next;
		else
			break;
	}

	New->next = Cur;
	New->prev = Cur->prev;
	Cur->prev = New;
	(New->prev)->next = New;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::deleteNode(ItemType item)
{
	Node<ItemType>* Cur;
	Cur = searchNode(item);

	if (Cur != NULL) {
		Cur->prev->next = Cur->next;
		Cur->next->prev = Cur->prev;
		delete Cur;
	}
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::print()
{
	Node<ItemType>* Cur = head->next;
	while (Cur != head) {
		cout << Cur->data << " ";
		Cur = Cur->next;
	}
	cout << endl;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::printReversed()
{
	Node<ItemType>* Cur = head->prev;
	while (Cur != head) {
		cout << Cur->data << " ";
		Cur = Cur->prev;
	}
	cout << endl;
}

template <typename ItemType>
void DoublyLinkedList<ItemType>::Union(DoublyLinkedList<ItemType> l)
{
	Node<ItemType>* currnode = head->next;

	while (currnode != head)
	{
		if (!l.searchNode(currnode->data))
			l.insertNode(currnode->data);

		currnode = currnode->next;
	}

	l.print();
}


int main()
{
    DoublyLinkedList<int> myList; // Create a new empty doubly linked list

    // Insert some values into the list
    myList.insertNode(1);
    myList.insertNode(2);
    myList.insertNode(3);

    // Print the list in forward order
    cout << "List: ";
    myList.print(); // Output: 1 2 3

    // Print the list in reverse order
    cout << "Reverse list: ";
    myList.printReversed(); // Output: 3 2 1

    // Search for a node with value 2 in the list
    Node<int>* foundNode = myList.searchNode(2);
    if (foundNode) {
        cout << "Found node with value 2!" << endl;
    } else {
        cout << "Could not find node with value 2." << endl;
    }

    // Delete the node with value 2 from the list
    myList.deleteNode(2);

    // Print the list again to confirm that the node was deleted
    cout << "List after deletion: ";
    myList.print(); // Output: 1 3

    return 0;
}
