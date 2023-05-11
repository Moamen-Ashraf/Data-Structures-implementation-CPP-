# Data-Structures-implementation-CPP-

Data Structures Implementation in C++

This repository contains implementations of various data structures in C++. Each data structure is implemented using different techniques and approaches. Below is an overview of the implemented data structures:

Stack (Array-based)
The stack implementation is based on an array and supports the following operations:

push(item): Insert an element at the top of the stack.
pop(): Remove and return the element at the top of the stack.
top(): Return the element at the top of the stack without removing it.
isEmpty(): Check if the stack is empty.
size(): Return the number of elements in the stack.

// Example usage of Stack (Array-based)
Stack<int> stack;
stack.push(10);
stack.push(20);
stack.push(30);
int topElement = stack.top(); // Returns 30
stack.pop();
bool isEmpty = stack.isEmpty(); // Returns false
int stackSize = stack.size(); // Returns 2

Queue (Array-based)
The queue implementation is based on an array and supports the following operations:

enqueue(item): Insert an element at the rear of the queue.
dequeue(): Remove and return the element from the front of the queue.
front(): Return the element at the front of the queue without removing it.
isEmpty(): Check if the queue is empty.
size(): Return the number of elements in the queue.

// Example usage of Queue (Array-based)
Queue<int> queue;
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
int frontElement = queue.front(); // Returns 10
queue.dequeue();
bool isEmpty = queue.isEmpty(); // Returns false
int queueSize = queue.size(); // Returns 2
  
Linked List
The linked list implementation consists of a singly linked list with the following operations:

insertFront(item): Insert an element at the beginning of the list.
insertEnd(item): Insert an element at the end of the list.
deleteFront(): Remove and return the element from the beginning of the list.
deleteEnd(): Remove and return the element from the end of the list.
search(item): Search for an element in the list and return its position.
isEmpty(): Check if the list is empty.
size(): Return the number of elements in the list.

// Example usage of Linked List
LinkedList<int> linkedList;
linkedList.insertFront(10);
linkedList.insertFront(20);
linkedList.insertEnd(30);
linkedList.deleteFront();
int position = linkedList.search(20); // Returns 1
bool isEmpty = linkedList.isEmpty(); // Returns false
int listSize = linkedList.size(); // Returns 2
  
  
Doubly Linked List
The doubly linked list implementation consists of a doubly linked list with a dummy head node. It supports the same operations as the singly linked list.

// Example usage of Doubly Linked List
DoublyLinkedList<int> doublyLinkedList;
doublyLinkedList.insertNode(10);
doublyLinkedList.insertNode(20);
doublyLinkedList.insertNode(30);
doublyLinkedList.deleteNode(20);
doublyLinkedList.print();
doublyLinkedList.printReversed();
  
Feel free to explore the code for each data structure implementation and use them as a reference or starting point for your own projects.

Note: These implementations are provided as educational examples and may not cover all edge cases or optimizations.






