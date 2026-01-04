#include <iostream>
using namespace std;

// ===== NODE CLASS =====
class Node {
private:
    int element;
    Node* nextptr;
public:
    Node(int i = 0, Node* pt = nullptr) {
        element = i;
        nextptr = pt;
    }

    int retrive() const { return element; }
    Node* node() const { return nextptr; }

    friend class List;
};

// ===== LIST CLASS (for stack) =====
class List {
private:
    Node* head_list = nullptr;

public:
    bool empty() const { return head_list == nullptr; }

    void push_front(int n) {
        head_list = new Node(n, head_list);
    }

    int pop_front() {
        if (empty()) {
            throw runtime_error("Stack Underflow!");
        }
        Node* temp = head_list;
        int val = temp->retrive();
        head_list = temp->nextptr;
        delete temp;
        return val;
    }

    int front() const {
        if (empty()) {
            throw runtime_error("Stack is empty!");
        }
        return head_list->retrive();
    }

    void display() const {
        cout << "\nStack elements (top to bottom): ";
        for (Node* ptr = head_list; ptr != nullptr; ptr = ptr->nextptr) {
            cout << ptr->retrive() << "  ";
        }
        cout << endl;
    }

    int size() const {
        int count = 0;
        for (Node* ptr = head_list; ptr != nullptr; ptr = ptr->nextptr)
            count++;
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Swap top two elements
    void swap_top() {
        if (size() < 2) throw runtime_error("Not enough elements to swap!");
        Node* first = head_list;
        Node* second = head_list->nextptr;
        first->nextptr = second->nextptr;
        second->nextptr = first;
        head_list = second;
    }

    // Duplicate the top element
    void duplicate_top() {
        if (empty()) throw runtime_error("Stack is empty!");
        push_front(front());
    }

    // Reverse the stack
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head_list;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->nextptr;
            curr->nextptr = prev;
            prev = curr;
            curr = next;
        }
        head_list = prev;
    }
};

// ===== STACK CLASS =====
class Stack {
private:
    List l;
public:
    bool empty() const { return l.empty(); }
    void push(int x) { l.push_front(x); }
    int pop() { return l.pop_front(); }
    int top() const { return l.front(); }
    void display() const { l.display(); }
    int size() const { return l.size(); }
    void clear() { l.clear(); }
    void swap_top() { l.swap_top(); }
    void duplicate_top() { l.duplicate_top(); }
    void reverse() { l.reverse(); }
};

// ===== MAIN =====
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // 30 20 10

    cout << "\nTop element: " << s.top() << endl;

    s.pop();
    s.display();  // 20 10

    s.duplicate_top();
    s.display();  // 20 20 10

    s.swap_top();
    s.display();  // 20 20 10 (swap top two 20s)

    s.reverse();
    s.display();  // 10 20 20

    cout << "\nStack size: " << s.size() << endl;

    s.clear();
    cout << "\nStack cleared. Empty? " << (s.empty() ? "Yes" : "No") << endl;
}














////////////////////////////////////////////////////// Templated Version ///////////////////////////////////











#include <iostream>
using namespace std;

// ===== NODE CLASS =====
template <typename T>
class Node {
private:
    T element;
    Node<T>* nextptr;
public:
    Node(T i = T(), Node<T>* pt = nullptr) {
        element = i;
        nextptr = pt;
    }

    T retrive() const { return element; }
    Node<T>* node() const { return nextptr; }

    template <typename U> friend class List;
};

// ===== LIST CLASS (for stack) =====
template <typename T>
class List {
private:
    Node<T>* head_list = nullptr;

public:
    bool empty() const { return head_list == nullptr; }

    void push_front(T n) {
        head_list = new Node<T>(n, head_list);
    }

    T pop_front() {
        if (empty()) {
            throw runtime_error("Stack Underflow!");
        }
        Node<T>* temp = head_list;
        T val = temp->retrive();
        head_list = temp->nextptr;
        delete temp;
        return val;
    }

    T front() const {
        if (empty()) {
            throw runtime_error("Stack is empty!");
        }
        return head_list->retrive();
    }

    void display() const {
        cout << "\nStack elements (top to bottom): ";
        for (Node<T>* ptr = head_list; ptr != nullptr; ptr = ptr->nextptr) {
            cout << ptr->retrive() << "  ";
        }
        cout << endl;
    }

    int size() const {
        int count = 0;
        for (Node<T>* ptr = head_list; ptr != nullptr; ptr = ptr->nextptr)
            count++;
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Swap top two elements
    void swap_top() {
        if (size() < 2) throw runtime_error("Not enough elements to swap!");
        Node<T>* first = head_list;
        Node<T>* second = head_list->nextptr;
        first->nextptr = second->nextptr;
        second->nextptr = first;
        head_list = second;
    }

    // Duplicate the top element
    void duplicate_top() {
        if (empty()) throw runtime_error("Stack is empty!");
        push_front(front());
    }

    // Reverse the stack
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head_list;
        Node<T>* next = nullptr;
        while (curr != nullptr) {
            next = curr->nextptr;
            curr->nextptr = prev;
            prev = curr;
            curr = next;
        }
        head_list = prev;
    }
};

// ===== STACK CLASS =====
template <typename T>
class Stack {
private:
    List<T> l;
public:
    bool empty() const { return l.empty(); }
    void push(T x) { l.push_front(x); }
    T pop() { return l.pop_front(); }
    T top() const { return l.front(); }
    void display() const { l.display(); }
    int size() const { return l.size(); }
    void clear() { l.clear(); }
    void swap_top() { l.swap_top(); }
    void duplicate_top() { l.duplicate_top(); }
    void reverse() { l.reverse(); }
};

// ===== MAIN =====
int main() {
    Stack<int> s;  // now we can change <int> to <float> or <string> too

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // 30 20 10

    cout << "\nTop element: " << s.top() << endl;

    s.pop();
    s.display();  // 20 10

    s.duplicate_top();
    s.display();  // 20 20 10

    s.swap_top();
    s.display();  // 20 20 10 (swap top two 20s)

    s.reverse();
    s.display();  // 10 20 20

    cout << "\nStack size: " << s.size() << endl;

    s.clear();
    cout << "\nStack cleared. Empty? " << (s.empty() ? "Yes" : "No") << endl;
}










///////////////////////////////////////////////// Stack with Array ///////////////////////////////////////



















#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int stack_size;      // number of elements currently in stack
    int array_capacity;  // maximum capacity of stack
    int* array;          // dynamic array to store elements

public:
    // Constructor with default capacity = 10
    Stack(int capacity = 10) {
        stack_size = 0;
        array_capacity = capacity;
        array = new int[array_capacity];
    }

    // Destructor to free memory
    ~Stack() {
        delete[] array;
    }

    // Check if stack is empty
    bool empty() const {
        return stack_size == 0;
    }

    // Return top element without removing it
    int top() const {
        if (empty()) throw runtime_error("Stack is empty!");
        return array[stack_size - 1];
    }

    // Push element onto stack
    void push(int x) {
        if (stack_size == array_capacity) {
            throw runtime_error("Stack Overflow!");
        }
        array[stack_size++] = x;
    }

    // Pop element from stack
    int pop() {
        if (empty()) throw runtime_error("Stack Underflow!");
        return array[--stack_size];
    }

    // Optional: Display all elements (top to bottom)
    void display() const {
        cout << "\nStack elements (top to bottom): ";
        for (int i = stack_size - 1; i >= 0; i--)
            cout << array[i] << "  ";
        cout << endl;
    }

    // Optional: Get current size of stack
    int size() const {
        return stack_size;
    }

    // Optional: Clear stack
    void clear() {
        stack_size = 0;
    }

    // Swap top two elements
    void swap_top() {
        if (stack_size < 2) throw runtime_error("Not enough elements to swap!");
        int temp = array[stack_size - 1];
        array[stack_size - 1] = array[stack_size - 2];
        array[stack_size - 2] = temp;
    }

    // Duplicate the top element
    void duplicate_top() {
        if (empty()) throw runtime_error("Stack is empty!");
        push(array[stack_size - 1]);
    }

    // Reverse the stack
    void reverse() {
        int i = 0, j = stack_size - 1;
        while (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
};

// ===== MAIN =====
int main() {
    Stack s(5);  // capacity 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // 30 20 10

    cout << "\nTop element: " << s.top() << endl;

    s.pop();
    s.display();  // 20 10

    s.duplicate_top();
    s.display();  // 20 20 10

    s.swap_top();
    s.display();  // 20 20 10

    s.reverse();
    s.display();  // 10 20 20

    cout << "\nStack size: " << s.size() << endl;

    s.clear();
    cout << "\nStack cleared. Empty? " << (s.empty() ? "Yes" : "No") << endl;
}


  