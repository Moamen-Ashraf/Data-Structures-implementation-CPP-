# Data Structures Implementation in C++

_Welcome to the Data Structures Implementation repository! This repository contains C++ implementations of various data structures, providing you with ready-to-use code examples._

## Table of Contents
- Stack (Array-based)
- Queue (Array-based)
- Linked List
- Doubly Linked List

## Stack (Array-based)
_The stack implementation is based on an array and supports common stack operations such as push, pop, top, isEmpty, and size. You can easily integrate this stack implementation into your projects._

<pre>
<code>
// Example usage of Stack (Array-based)
Stack&lt;int&gt; stack;
stack.push(10);
stack.push(20);
stack.push(30);
int topElement = stack.top(); // Returns 30
stack.pop();
bool isEmpty = stack.isEmpty(); // Returns false
int stackSize = stack.size(); // Returns 2
</code>
</pre>

  
  
## Queue (Array-based)
_The queue implementation is based on an array and provides functionalities like enqueue, dequeue, front, isEmpty, and size. You can utilize this queue implementation for managing data in a First-In-First-Out (FIFO) order._
  
<pre>
<code>
// Example usage of Queue (Array-based)
Queue&lt;int&gt; queue;
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
int frontElement = queue.front(); // Returns 10
queue.dequeue();
bool isEmpty = queue.isEmpty(); // Returns false
int queueSize = queue.size(); // Returns 2
</code>
</pre>

  
  
## Linked List
_The linked list implementation offers a singly linked list and supports operations such as insertFront, insertEnd, deleteFront, deleteEnd, search, isEmpty, and size. This implementation provides flexibility for dynamic data storage._

<pre>
<code>
// Example usage of Linked List
LinkedList&lt;int&gt; linkedList;
linkedList.insertFront(10);
linkedList.insertFront(20);
linkedList.insertEnd(30);
linkedList.deleteFront();
int position = linkedList.search(20); // Returns 1
bool isEmpty = linkedList.isEmpty(); // Returns false
int listSize = linkedList.size(); // Returns 2
</code>
</pre>
  
## Doubly Linked List
 _The doubly linked list implementation includes a doubly linked list with a dummy head node. It offers functions like insertNode, deleteNode, print, and printReversed. This implementation provides efficient traversal in both forward and backward directions._

<pre>
<code>
// Example usage of Doubly Linked List
DoublyLinkedList&lt;int&gt; doublyLinkedList;
doublyLinkedList.insertNode(10);
doublyLinkedList.insertNode(20);
doublyLinkedList.insertNode(30);
doublyLinkedList.deleteNode(20);
doublyLinkedList.print();
doublyLinkedList.printReversed();
</code>
</pre>

 
 
**Feel free to explore the code for each data structure implementation, adapt them to your specific needs, and integrate them into your projects. These implementations serve as educational examples and can serve as a solid foundation for understanding and utilizing data structures in C++.**

### Contribution
_Contributions to this repository are welcome! If you have any improvements, bug fixes, or additional data structure implementations, please feel free to submit a pull request._

**Note**: _These implementations are provided as educational examples and may not cover all edge cases or optimizations._

**Happy coding!**
