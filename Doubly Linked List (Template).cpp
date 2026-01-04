#include <iostream>
using namespace std;

/* =======================
        Node Class (Template)
   ======================= */
template <typename T>
class Node {
private:
    T data;
    Node<T>* next_node;
    Node<T>* prev_node;

public:
    Node(T val = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) {
        data = val;
        next_node = next;
        prev_node = prev;
    }

    // Accessors
    T retrieve() const {
        return data;
    }

    Node<T>* next() const {
        return next_node;
    }

    Node<T>* prev() const {
        return prev_node;
    }

    // Mutators
    void set_data(T val) {
        data = val;
    }

    void set_next(Node<T>* next) {
        next_node = next;
    }

    void set_prev(Node<T>* prev) {
        prev_node = prev;
    }

    template <typename U>
    friend class List;
};


/* =======================
        Doubly List Class
   ======================= */
template <typename T>
class List {
private:
    Node<T>* head;

public:
    /* Constructor */
    List() {
        head = nullptr;
    }

    /* Destructor */
    ~List() {
        while (!empty()) {
            pop_front();
        }
    }

    /* =======================
            Accessors
       ======================= */
    bool empty() const {
        return head == nullptr;
    }

    int size() const {
        int count = 0;
        for (Node<T>* ptr = head; ptr != nullptr; ptr = ptr->next()) {
            count++;
        }
        return count;
    }

    T front() const {
        if (empty()) return T();
        return head->retrieve();
    }

    T end() const {
        if (empty()) return T();
        Node<T>* ptr = head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }
        return ptr->retrieve();
    }

    /* =======================
            Mutators
       ======================= */

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value, head, nullptr);

        if (head != nullptr)
            head->prev_node = newNode;

        head = newNode;
    }

    void push_end(T value) {
        if (empty()) {
            push_front(value);
            return;
        }

        Node<T>* ptr = head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }

        Node<T>* newNode = new Node<T>(value, nullptr, ptr);
        ptr->next_node = newNode;
    }

    void insert_at_position(T value, int position) {
        if (position == 1) {
            push_front(value);
            return;
        }

        Node<T>* ptr = head;
        int count = 1;

        while (ptr != nullptr && count < position - 1) {
            ptr = ptr->next();
            count++;
        }

        if (ptr == nullptr) return;

        Node<T>* newNode = new Node<T>(
            value,
            ptr->next(),
            ptr
        );

        if (ptr->next() != nullptr)
            ptr->next()->prev_node = newNode;

        ptr->next_node = newNode;
    }

    T pop_front() {
        if (empty()) return T();

        Node<T>* temp = head;
        T val = temp->retrieve();
        head = head->next();

        if (head != nullptr)
            head->prev_node = nullptr;

        delete temp;
        return val;
    }

    T pop_end() {
        if (empty()) return T();

        if (head->next() == nullptr)
            return pop_front();

        Node<T>* ptr = head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }

        T val = ptr->retrieve();
        ptr->prev()->next_node = nullptr;
        delete ptr;
        return val;
    }

    void delete_at_position(int position) {
        if (position == 1) {
            pop_front();
            return;
        }

        Node<T>* ptr = head;
        int count = 1;

        while (ptr != nullptr && count < position) {
            ptr = ptr->next();
            count++;
        }

        if (ptr == nullptr) return;

        if (ptr->prev() != nullptr)
            ptr->prev()->next_node = ptr->next();

        if (ptr->next() != nullptr)
            ptr->next()->prev_node = ptr->prev();

        delete ptr;
    }

    void update(int k, T newValue) {
        Node<T>* ptr = head;
        int count = 1;

        while (ptr != nullptr && count < k) {
            ptr = ptr->next();
            count++;  //jjsnjs
        }

        if (ptr != nullptr)
            ptr->set_data(newValue);
    }

    void swap_first_two() {
        if (head == nullptr || head->next() == nullptr) return;
        swap(head->data, head->next()->data);
    }

    void sortAscending() {
        for (Node<T>* i = head; i != nullptr; i = i->next()) {
            for (Node<T>* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void sortDescending() {
        for (Node<T>* i = head; i != nullptr; i = i->next()) {
            for (Node<T>* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data < j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void traverse() const {
        Node<T>* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->retrieve() << " <-> ";
            ptr = ptr->next();
        }
        cout << "NULL\n";
    }
};


/* =======================
            MAIN
   ======================= */
int main() {
    List<int> dl;   // 👈 Template usage

    dl.push_front(10);
    dl.push_front(5);
    dl.push_end(20);
    dl.insert_at_position(7, 2);

    dl.traverse();

    dl.sortAscending();
    dl.traverse();

    dl.sortDescending();
    dl.traverse();

    dl.pop_front();
    dl.traverse();

    dl.pop_end();
    dl.traverse();

    dl.delete_at_position(2);
    dl.traverse();

    dl.update(1, 99);
    dl.traverse();

    cout << "Size: " << dl.size() << endl;

    dl.swap_first_two();
    dl.traverse();

    return 0;
}









/////////////////////////////////////////////////  Without Templates //////////////////////////////////////////////////////////








#include <iostream>
using namespace std;

/* =======================
        Node Class
   ======================= */
class Node {
private:
    int data;
    Node* next_node;
    Node* prev_node;

public:
    Node(int val = 0, Node* next = nullptr, Node* prev = nullptr) {
        data = val;
        next_node = next;
        prev_node = prev;
    }

    // Accessors
    int retrieve() const {
        return data;
    }

    Node* next() const {
        return next_node;
    }

    Node* prev() const {
        return prev_node;
    }

    // Mutators
    void set_data(int val) {
        data = val;
    }

    void set_next(Node* next) {
        next_node = next;
    }

    void set_prev(Node* prev) {
        prev_node = prev;
    }

    friend class List;
};


/* =======================
        Doubly List Class
   ======================= */
class List {
private:
    Node* head;

public:
    /* Constructor */
    List() {
        head = nullptr;
    }

    /* Destructor */
    ~List() {
        while (!empty()) {
            pop_front();
        }
    }

    /* =======================
            Accessors
       ======================= */
    bool empty() const {
        return head == nullptr;
    }

    int size() const {
        int count = 0;
        for (Node* ptr = head; ptr != nullptr; ptr = ptr->next()) {
            count++;
        }
        return count;
    }

    int front() const {
        if (empty()) return 0;
        return head->retrieve();
    }

    int end() const {
        if (empty()) return 0;
        Node* ptr = head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }
        return ptr->retrieve();
    }

    /* =======================
            Mutators
       ======================= */

    void push_front(int value) {
        Node* newNode = new Node(value, head, nullptr);

        if (head != nullptr)
            head->prev_node = newNode;

        head = newNode;
    }

    void push_end(int value) {
        if (empty()) {
            push_front(value);
            return;
        }

        Node* ptr = head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }

        Node* newNode = new Node(value, nullptr, ptr);
        ptr->next_node = newNode;
    }

    void insert_at_position(int value, int position) {
        if (position == 1) {
            push_front(value);
            return;
        }

        Node* ptr = head;
        int count = 1;

        while (ptr != nullptr && count < position - 1) {
            ptr = ptr->next();
            count++;
        }

        if (ptr == nullptr) return;

        Node* newNode = new Node(value, ptr->next(), ptr);

        if (ptr->next() != nullptr)
            ptr->next()->prev_node = newNode;

        ptr->next_node = newNode;
    }

    int pop_front() {
        if (empty()) return 0;

        Node* temp = head;
        int val = temp->retrieve();
        head = head->next();

        if (head != nullptr)
            head->prev_node = nullptr;

        delete temp;
        return val;
    }

    int pop_end() {
        if (empty()) return 0;

        if (head->next() == nullptr)
            return pop_front();

        Node* ptr = head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }

        int val = ptr->retrieve();
        ptr->prev()->next_node = nullptr;
        delete ptr;
        return val;
    }

    void delete_at_position(int position) {
        if (position == 1) {
            pop_front();
            return;
        }

        Node* ptr = head;
        int count = 1;

        while (ptr != nullptr && count < position) {
            ptr = ptr->next();
            count++;
        }

        if (ptr == nullptr) return;

        if (ptr->prev() != nullptr)
            ptr->prev()->next_node = ptr->next();

        if (ptr->next() != nullptr)
            ptr->next()->prev_node = ptr->prev();

        delete ptr;
    }

    void update(int k, int newValue) {
        Node* ptr = head;
        int count = 1;

        while (ptr != nullptr && count < k) {
            ptr = ptr->next();
            count++;
        }

        if (ptr != nullptr)
            ptr->set_data(newValue);
    }

    void swap_first_two() {
        if (head == nullptr || head->next() == nullptr) return;
        swap(head->data, head->next()->data);
    }

    void sortAscending() {
        for (Node* i = head; i != nullptr; i = i->next()) {
            for (Node* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void sortDescending() {
        for (Node* i = head; i != nullptr; i = i->next()) {
            for (Node* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data < j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void traverse() const {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->retrieve() << " <-> ";
            ptr = ptr->next();
        }
        cout << "NULL\n";
    }
};


/* =======================
            MAIN
   ======================= */
int main() {
    List dl;

    dl.push_front(10);
    dl.push_front(5);
    dl.push_end(20);
    dl.insert_at_position(7, 2);

    dl.traverse();

    dl.sortAscending();
    dl.traverse();

    dl.sortDescending();
    dl.traverse();

    dl.pop_front();
    dl.traverse();

    dl.pop_end();
    dl.traverse();

    dl.delete_at_position(2);
    dl.traverse();

    dl.update(1, 99);
    dl.traverse();

    cout << "Size: " << dl.size() << endl;

    dl.swap_first_two();
    dl.traverse();

    return 0;
}

