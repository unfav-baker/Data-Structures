
///////////////////////////////////////////  Without Template ///////////////////////////////////////////////////


#include <iostream>
#include <stdexcept>
using namespace std;

// ===== NODE CLASS =====
class Node {
private:
    int element;
    Node* nextptr;
public:
    Node(int e = 0, Node* next = nullptr) {
        element = e;
        nextptr = next;
    }

    int retrive() const { return element; }
    Node* node() const { return nextptr; }

    friend class List;
};

// ===== LIST CLASS (for queue) =====
class List {
private:
    Node* head_list = nullptr;
    Node* tail_list = nullptr;

public:
    bool empty() const { return head_list == nullptr; }

    // Add element at the rear
    void push_end(int n) {
        Node* newNode = new Node(n);
        if (empty()) {
            head_list = tail_list = newNode;
            return;
        }
        tail_list->nextptr = newNode;
        tail_list = newNode;
    }

    // Remove element from front
    int pop_front() {
        if (empty()) throw runtime_error("Queue Underflow!");
        Node* temp = head_list;
        int val = temp->retrive();
        head_list = head_list->nextptr;
        if (head_list == nullptr) tail_list = nullptr; // queue became empty
        delete temp;
        return val;
    }

    int front() const {
        if (empty()) throw runtime_error("Queue is empty!");
        return head_list->retrive();
    }

    int rear() const {
        if (empty()) throw runtime_error("Queue is empty!");
        return tail_list->retrive();
    }

    void display() const {
        cout << "\nQueue elements (front to rear): ";
        for (Node* ptr = head_list; ptr != nullptr; ptr = ptr->nextptr)
            cout << ptr->retrive() << "  ";
        cout << endl;
    }

    int size() const {
        int count = 0;
        for (Node* ptr = head_list; ptr != nullptr; ptr = ptr->nextptr) count++;
        return count;
    }

    void clear() {
        while (!empty()) pop_front();
    }

    // Swap first two elements
    void swap_front() {
        if (size() < 2) throw runtime_error("Not enough elements to swap!");
        Node* first = head_list;
        Node* second = head_list->nextptr;
        first->nextptr = second->nextptr;
        second->nextptr = first;
        head_list = second;
        if (first->nextptr == nullptr) tail_list = first;
    }



    // Reverse the queue
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head_list;
        Node* next = nullptr;
        tail_list = head_list; // old head becomes new tail
        while (curr != nullptr) {
            next = curr->nextptr;
            curr->nextptr = prev;
            prev = curr;
            curr = next;
        }
        head_list = prev;
    }
};

// ===== QUEUE CLASS =====
class Queue {
private:
    List l;
public:
    bool empty() const { return l.empty(); }
    void enqueue(int x) { l.push_end(x); }
    int dequeue() { return l.pop_front(); }
    int front() const { return l.front(); }
    int rear() const { return l.rear(); }
    void display() const { l.display(); }
    int size() const { return l.size(); }
    void clear() { l.clear(); }
    void swap_front() { l.swap_front(); }
    void reverse() { l.reverse(); }
};

// ===== MAIN =====
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // 10 20 30

    cout << "\nFront: " << q.front() << ", Rear: " << q.rear() << endl;

    q.dequeue();
    q.display(); // 20 30



    q.swap_front();
    q.display();

    q.reverse();
    q.display();

    cout << "\nQueue size: " << q.size() << endl;

    q.clear();
    cout << "\nQueue cleared. Empty? " << (q.empty() ? "Yes" : "No") << endl;
}






//////////////////////////////////////////////////// Template Version ////////////////////////////////////////////



#include <iostream>
using namespace std;

// ===== NODE CLASS =====
template <typename T>
class Node {
private:
    T element;
    Node<T>* nextptr;
public:
    Node(T e, Node<T>* next = nullptr) {
        element = e;
        nextptr = next;
    }

    T retrive() const { return element; }
    Node<T>* next() const { return nextptr; }
    void setNext(Node<T>* n) { nextptr = n; }

    template <typename U> friend class Queue;
};

// ===== QUEUE CLASS USING SINGLY LINKED LIST =====
template <typename T>
class Queue {
private:
    Node<T>* front_ptr;
    Node<T>* rear_ptr;

public:
    Queue() : front_ptr(nullptr), rear_ptr(nullptr) {}

    ~Queue() {
        while (!empty()) {
            dequeue();
        }
    }

    bool empty() const {
        return front_ptr == nullptr;
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (empty()) {
            front_ptr = rear_ptr = newNode;
        }
        else {
            rear_ptr->setNext(newNode);
            rear_ptr = newNode;
        }
    }

    T dequeue() {
        if (empty()) {
            throw runtime_error("Queue Underflow!");
        }
        Node<T>* temp = front_ptr;
        T val = temp->retrive();
        front_ptr = front_ptr->next();
        if (front_ptr == nullptr) rear_ptr = nullptr; // queue is now empty
        delete temp;
        return val;
    }

    T front() const {
        if (empty()) {
            throw runtime_error("Queue is empty!");
        }
        return front_ptr->retrive();
    }

    void display() const {
        cout << "\nQueue elements (front to rear): ";
        for (Node<T>* p = front_ptr; p != nullptr; p = p->next()) {
            cout << p->retrive() << "  ";
        }
        cout << endl;
    }

    int size() const {
        int count = 0;
        for (Node<T>* p = front_ptr; p != nullptr; p = p->next())
            count++;
        return count;
    }

    void clear() {
        while (!empty()) {
            dequeue();
        }
    }
};

// ===== MAIN =====
int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // 10 20 30

    cout << "\nFront element: " << q.front() << endl;

    q.dequeue();
    q.display(); // 20 30

    cout << "\nQueue size: " << q.size() << endl;

    q.clear();
    cout << "\nQueue cleared. Empty? " << (q.empty() ? "Yes" : "No") << endl;
}

