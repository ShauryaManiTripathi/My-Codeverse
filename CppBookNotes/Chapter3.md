# Linked Lists...............
## Special points
- linked lists-(singly,doubly,circular and variations)
- stack and queue
- Questions
  1. implement stack and queue using linked list
  2. find k'th element from last in linked list AND find middle element in linked list AND check if list has a loop or not. 
     - SOLUTION
     three approaches->>>
       1. using hash table
       2. using two start-->end traversals(not for loop ques)
       3. using two pointers
             ```cpp
            //finding middle using two pointers
            void findMiddle(Node* head){
                Node* slow=head;
                Node* fast=head;
                //while(fast && fast->next)
                while(fast!=nullptr && fast->n ext!=nullptr){
                slow=slow->next;
                fast=fast->next->next;
                }
                cout<<slow->data;
            }
            ```
            ```cpp
            //finding k'th element from last using two pointers
            void findKthFromLast(Node* head,int k){
                Node* slow=head;
                Node* fast=head;
                int i=0;
                while(i<k){
                    fast=fast->next;
                    i++;
                }
                while(fast!=nullptr){
                    slow=slow->next;
                    fast=fast->next;
                }
                cout<<slow->data;
            }
            ```
            ```cpp
            //finding if list has a loop or not using two pointers
            //floyd method
            void findLoop(Node* head){
                Node* slow=head;
                Node* fast=head;
                while(fast!=nullptr && fast->next!=nullptr){
                    slow=slow->next;
                    fast=fast->next->next;
                    if(slow==fast){
                        cout<<"loop found";
                        return;
                    }
                }
                cout<<"loop not found";
            }
            //what if the fast pointer skips 2 nodes or more
            ```
  3. find if the list has a loop or not?If yes, then find the head of the loop
     - SOLUTION
       1. the same solution as in finding loop just we need to do lil extra
           ```cpp
           void findLoopHead(Node* head){
            Node* slow=head,fast=head;
            int Loopexists=0;
            while(fast!=nullptr && fast->next!=nullptr){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    Loopexists=1;
                    break;
                }
            }
            //reset slow pointer to head, and start moving fast,slow together until they meet IFF Loopexists=1
            if(Loopexists){
                slow=head;
                while(slow!=fast){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow
            }
            return NULL;
           }
           //how does moving slow pointer at head,then starting the slow and fast to move together makes them meet at loop's head  
           ```
  4. find the length of loop in the looped 
- circular linked lists are used in OS for data handling
- A memory efficient doubly linked list using single exOR(prev^next)pointer
- unrolled linked list with sqrt(n) in each (list node)
  1. advantage of  unrolled linked list is that it can store more than one element in each node
  2. it is used in database,file systems.
  3. if we store sqrt(n) in each list node, it helps in searching any node in O(sqrt(n))
  4. inserting is little tedious, as we might need to shift all contents to next blocks
  5. still its a fast method ,with better space and time management(with uniform data unit distribution in each block)
  6. code to impliment unrolled linked list is in the book
- skip list
  1. skip list is a probabilistic data structure that allows fast search within an ordered sequence of elements
  2. skip list allows O(log n) search complexity as well as O(log n) insertion complexity within an ordered sequence of n elements
  3. skip list is a data structure that allows fast search within an ordered sequence of elements.
  4. a weirdly simple data structure that allows O(log n) search complexity as well as O(log n) insertion complexity within an ordered sequence of n elements.
  5. with i'th node having 2i-1 pointers to next node in the list.

  

## Codes covered
- [Singly Linked List](#singly-linked-list)
- [Doubly Linked List](#doubly-linked-list)
- [Circular Linked List](#circular-linked-list)
- [Stack](#stack)
- [Queue](#queue)
## Singly Linked List
### Singly Linked List Node
```cpp
struct Node {
    int data;
    Node* next;
};
```
### Singly Linked List Class
```cpp
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() { head = nullptr; }
        ~LinkedList();
        void addNode(int val);
        void deleteNode(int val);
        void display();
};
```
### Singly Linked List Destructor
```cpp
LinkedList::~LinkedList() {
    Node* currNode = head;
    Node* nextNode = nullptr;
    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}
```
### Singly Linked List Add Node
```cpp
void LinkedList::addNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
}
```
### Singly Linked List Delete Node
```cpp
void LinkedList::deleteNode(int val) {
    Node* currNode = head;
    Node* prevNode = nullptr;
    while (currNode != nullptr && currNode->data != val) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == nullptr) {
        cout << "Value not found" << endl;
    } else if (currNode == head) {
        head = currNode->next;
        delete currNode;
    } else {
        prevNode->next = currNode->next;
        delete currNode;
    }
}
```
### Singly Linked List Display
```cpp
void LinkedList::display() {
    Node* currNode = head;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}
```
## Doubly Linked List
### Doubly Linked List Node
```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;
};
```

### Doubly Linked List Class
```cpp
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() { head = nullptr; }
        ~LinkedList();
        void addNode(int val);
        void deleteNode(int val);
        void display();
};
```
### Doubly Linked List Destructor
```cpp
LinkedList::~LinkedList() {
    Node* currNode = head;
    Node* nextNode = nullptr;
    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}
```
### Doubly Linked List Add Node
```cpp
void LinkedList::addNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->prev = currNode;
    }
}
```

### Doubly Linked List Delete Node
```cpp
void LinkedList::deleteNode(int val) {
    Node* currNode = head;
    Node* prevNode = nullptr;
    while (currNode != nullptr && currNode->data != val) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == nullptr) {
        cout << "Value not found" << endl;
    } else if (currNode == head) {
        head = currNode->next;
        head->prev = nullptr;
        delete currNode;
    } else {
        prevNode->next = currNode->next;
        if (currNode->next != nullptr) {
            currNode->next->prev = prevNode;
        }
        delete currNode;
    }
}
```
### Doubly Linked List Display
```cpp
void LinkedList::display() {
    Node* currNode = head;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}
```
## Circular Linked List
### Circular Linked List Node
```cpp
struct Node {
    int data;
    Node* next;
};
```
### Circular Linked List Class
```cpp
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() { head = nullptr; }
        ~LinkedList();
        void addNode(int val);
        void deleteNode(int val);
        void display();
};
```
### Circular Linked List Destructor
```cpp
LinkedList::~LinkedList() {
    Node* currNode = head;
    Node* nextNode = nullptr;
    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}
```
### Circular Linked List Add Node
```cpp
void LinkedList::addNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* currNode = head;
        while (currNode->next != head) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->next = head;
    }
}
```
### Circular Linked List Delete Node
```cpp
void LinkedList::deleteNode(int val) {
    Node* currNode = head;
    Node* prevNode = nullptr;
    while (currNode != nullptr && currNode->data != val) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == nullptr) {
        cout << "Value not found" << endl;
    } else if (currNode == head) {
        head = currNode->next;
        Node* temp = head;
        while (temp->next != currNode) {
            temp = temp->next;
        }
        temp->next = head;
        delete currNode;
    } else {
        prevNode->next = currNode->next;
        delete currNode;
    }
}
```
### Circular Linked List Display
```cpp
void LinkedList::display() {
    Node* currNode = head;
    do {
        cout << currNode->data << " ";
        currNode = currNode->next;
    } while (currNode != head);
    cout << endl;
}
```
## Stack
### Stack Node
```cpp
struct Node {
    int data;
    Node* next;
};
```
### Stack Class
```cpp
class Stack {
    private:
        Node* top;
    public:
        Stack() { top = nullptr; }
        ~Stack();
        void push(int val);
        void pop();
        void display();
};
```
### Stack Destructor
```cpp
Stack::~Stack() {
    Node* currNode = top;
    Node* nextNode = nullptr;
    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}
```
### Stack Push
```cpp
void Stack::push(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
```
### Stack Pop
```cpp
void Stack::pop() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
    } else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
```
### Stack Display
```cpp
void Stack::display() {
    Node* currNode = top;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}
```
## Queue
### Queue Node
```cpp
struct Node {
    int data;
    Node* next;
};
```
### Queue Class
```cpp
class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue() { front = nullptr; rear = nullptr; }
        ~Queue();
        void enqueue(int val);
        void dequeue();
        void display();
};
```
### Queue Destructor
```cpp
Queue::~Queue() {
    Node* currNode = front;
    Node* nextNode = nullptr;
    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}
```
### Queue Enqueue
```cpp
void Queue::enqueue(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
```
### Queue Dequeue
```cpp
void Queue::dequeue() {
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}
```
### Queue Display
```cpp
void Queue::display() {
    Node* currNode = front;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}
```
