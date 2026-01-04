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

public:
    Node(T val = T(), Node<T>* next = nullptr) {
        data = val;
        next_node = next;
    }

    T retrieve() const {
        return data;
    }

    Node<T>* next() const {
        return next_node;
    }

    void set_data(T val) {
        data = val;
    }

    void set_next(Node<T>* next) {
        next_node = next;
    }

    template <typename U>
    friend class List;
};


/* =======================
   Circular Singly List
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
        if (empty()) return 0;

        int count = 0;
        Node<T>* temp = head;
        do {
            count++;
            temp = temp->next();
        } while (temp != head);

        return count;
    }

    /* =======================
            Mutators
       ======================= */

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (empty()) {
            newNode->next_node = newNode;
            head = newNode;
            return;
        }

        Node<T>* temp = head;
        while (temp->next() != head) {
            temp = temp->next();
        }

        temp->next_node = newNode;
        newNode->next_node = head;
        head = newNode;
    }

    void push_end(T value) {
        if (empty()) {
            push_front(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;

        while (temp->next() != head) {
            temp = temp->next();
        }

        temp->next_node = newNode;
        newNode->next_node = head;
    }

    void insert_at_position(T value, int position) {
        if (position == 1) {
            push_front(value);
            return;
        }

        Node<T>* temp = head;
        int count = 1;

        while (count < position - 1) {
            temp = temp->next();
            count++;
        }

        Node<T>* newNode = new Node<T>(value, temp->next());
        temp->next_node = newNode;
    }

    T pop_front() {
        if (empty()) return T();

        if (head->next() == head) {
            T val = head->retrieve();
            delete head;
            head = nullptr;
            return val;
        }

        Node<T>* temp = head;
        while (temp->next() != head) {
            temp = temp->next();
        }

        Node<T>* del = head;
        T val = del->retrieve();
        temp->next_node = head->next();
        head = head->next();
        delete del;
        return val;
    }

    T pop_end() {
        if (empty()) return T();

        if (head->next() == head)
            return pop_front();

        Node<T>* temp = head;
        while (temp->next()->next() != head) {
            temp = temp->next();
        }

        Node<T>* del = temp->next();
        T val = del->retrieve();
        temp->next_node = head;
        delete del;
        return val;
    }

    void delete_at_position(int position) {
        if (position == 1) {
            pop_front();
            return;
        }

        Node<T>* temp = head;
        int count = 1;

        while (count < position - 1) {
            temp = temp->next();
            count++;
        }

        Node<T>* del = temp->next();
        temp->next_node = del->next();
        delete del;
    }

    void update(int k, T newValue) {
        if (empty()) return;

        Node<T>* temp = head;
        int count = 1;

        while (count < k) {
            temp = temp->next();
            count++;
        }

        temp->set_data(newValue);
    }

    void swap_first_two() {
        if (head == nullptr || head->next() == head) return;
        swap(head->data, head->next()->data);
    }

    void sortAscending() {
        if (empty() || head->next() == head) return;

        Node<T>* current = head;
        do {
            Node<T>* nextNode = current->next();
            while (nextNode != head) {
                if (current->data > nextNode->data) {
                    swap(current->data, nextNode->data);
                }
                nextNode = nextNode->next();
            }
            current = current->next();
        } while (current != head);
    }

    void sortDescending() {
        if (empty() || head->next() == head) return;

        Node<T>* current = head;
        do {
            Node<T>* nextNode = current->next();
            while (nextNode != head) {
                if (current->data < nextNode->data) {
                    swap(current->data, nextNode->data);
                }
                nextNode = nextNode->next();
            }
            current = current->next();
        } while (current != head);
    }

    void traverse() const {
        if (empty()) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp = head;
        do {
            cout << temp->retrieve() << " -> ";
            temp = temp->next();
        } while (temp != head);
        cout << "(head)\n";
    }
};


/* =======================
            MAIN
   ======================= */
int main() {
    List<int> cl;   // 👈 Template usage

    cl.push_front(10);
    cl.push_front(5);
    cl.push_end(20);
    cl.insert_at_position(7, 2);

    cl.traverse();

    cl.sortAscending();
    cl.traverse();

    cl.sortDescending();
    cl.traverse();

    cl.pop_front();
    cl.traverse();

    cl.pop_end();
    cl.traverse();

    cl.delete_at_position(2);
    cl.traverse();

    cl.update(1, 99);
    cl.traverse();

    cout << "Size: " << cl.size() << endl;

    cl.swap_first_two();
    cl.traverse();

    return 0;
}










//////////////////////////////////////////// Without Template //////////////////////////////////////













#include <iostream>
using namespace std;

/* =======================
        Node Class
   ======================= */
class Node {
private:
    int data;
    Node* next_node;

public:
    Node(int val = 0, Node* next = nullptr) {
        data = val;
        next_node = next;
    }

    int retrieve() const {
        return data;
    }

    Node* next() const {
        return next_node;
    }

    void set_data(int val) {
        data = val;
    }

    void set_next(Node* next) {
        next_node = next;
    }

    friend class List;
};


/* =======================
   Circular Singly List
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
        if (empty()) return 0;

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next();
        } while (temp != head);

        return count;
    }

    /* =======================
            Mutators
       ======================= */

    void push_front(int value) {
        Node* newNode = new Node(value);

        if (empty()) {
            newNode->next_node = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next() != head) {
            temp = temp->next();
        }

        temp->next_node = newNode;
        newNode->next_node = head;
        head = newNode;
    }

    void push_end(int value) {
        if (empty()) {
            push_front(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        while (temp->next() != head) {
            temp = temp->next();
        }

        temp->next_node = newNode;
        newNode->next_node = head;
    }

    void insert_at_position(int value, int position) {
        if (position == 1) {
            push_front(value);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1) {
            temp = temp->next();
            count++;
        }

        Node* newNode = new Node(value, temp->next());
        temp->next_node = newNode;
    }

    int pop_front() {
        if (empty()) return 0;

        if (head->next() == head) {
            int val = head->retrieve();
            delete head;
            head = nullptr;
            return val;
        }

        Node* temp = head;
        while (temp->next() != head) {
            temp = temp->next();
        }

        Node* del = head;
        int val = del->retrieve();
        temp->next_node = head->next();
        head = head->next();
        delete del;
        return val;
    }

    int pop_end() {
        if (empty()) return 0;

        if (head->next() == head)
            return pop_front();

        Node* temp = head;
        while (temp->next()->next() != head) {
            temp = temp->next();
        }

        Node* del = temp->next();
        int val = del->retrieve();
        temp->next_node = head;
        delete del;
        return val;
    }

    void delete_at_position(int position) {
        if (position == 1) {
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1) {
            temp = temp->next();
            count++;
        }

        Node* del = temp->next();
        temp->next_node = del->next();
        delete del;
    }

    void update(int k, int newValue) {
        if (empty()) return;

        Node* temp = head;
        int count = 1;

        while (count < k) {
            temp = temp->next();
            count++;
        }

        temp->set_data(newValue);
    }

    void swap_first_two() {
        if (head == nullptr || head->next() == head) return;
        swap(head->data, head->next()->data);
    }

    void sortAscending() {
        if (empty() || head->next() == head) return;

        Node* current = head;
        do {
            Node* nextNode = current->next();
            while (nextNode != head) {
                if (current->data > nextNode->data) {
                    swap(current->data, nextNode->data);
                }
                nextNode = nextNode->next();
            }
            current = current->next();
        } while (current != head);
    }

    void sortDescending() {
        if (empty() || head->next() == head) return;

        Node* current = head;
        do {
            Node* nextNode = current->next();
            while (nextNode != head) {
                if (current->data < nextNode->data) {
                    swap(current->data, nextNode->data);
                }
                nextNode = nextNode->next();
            }
            current = current->next();
        } while (current != head);
    }

    void traverse() const {
        if (empty()) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->retrieve() << " -> ";
            temp = temp->next();
        } while (temp != head);
        cout << "(head)\n";
    }
};


/* =======================
            MAIN
   ======================= */
int main() {
    List cl;

    cl.push_front(10);
    cl.push_front(5);
    cl.push_end(20);
    cl.insert_at_position(7, 2);

    cl.traverse();

    cl.sortAscending();
    cl.traverse();

    cl.sortDescending();
    cl.traverse();

    cl.pop_front();
    cl.traverse();

    cl.pop_end();
    cl.traverse();

    cl.delete_at_position(2);
    cl.traverse();

    cl.update(1, 99);
    cl.traverse();

    cout << "Size: " << cl.size() << endl;

    cl.swap_first_two();
    cl.traverse();

    return 0;
}

