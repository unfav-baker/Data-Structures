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

    // Accessors
    T retrieve() const {
        return data;
    }

    Node<T>* next() const {
        return next_node;
    }

    // Mutators
    void set_data(T val) {
        data = val;
    }

    void set_next(Node<T>* next) {
        next_node = next;
    }

    // Allow List class access
    template <typename U>
    friend class List;
};

/* =======================
        List Class (Template)
   ======================= */
template <typename T>
class List {
private:
    Node<T>* list_head;

public:
    /* Constructor */
    List() {
        list_head = nullptr;
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
        return list_head == nullptr;
    }

    T front() const {
        if (empty()) {
            cout << "List is empty\n";
            return T();
        }
        return list_head->retrieve();
    }

    T end() const {
        if (empty()) {
            cout << "List is empty\n";
            return T();
        }
        Node<T>* ptr = list_head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }
        return ptr->retrieve();
    }

    int size() const {
        int count = 0;
        for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            count++;
        }
        return count;
    }

    int count_value(T value) const {
        int node_count = 0;
        for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            if (ptr->retrieve() == value) {
                node_count++;
            }
        }
        return node_count;
    }

    /* =======================
            Mutators
       ======================= */

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value, list_head);
        list_head = newNode;
    }

    void push_end(T value) {
        if (empty()) {
            push_front(value);
            return;
        }

        Node<T>* ptr = list_head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }

        ptr->next_node = new Node<T>(value, nullptr);
    }

    void insert_at_position(T value, int position) {
        if (position == 1) {
            push_front(value);
            return;
        }

        Node<T>* prev = list_head;
        int count = 1;

        while (count < position - 1 && prev != nullptr) {
            prev = prev->next();
            count++;
        }

        if (prev == nullptr) return;

        Node<T>* newNode = new Node<T>(value, prev->next());
        prev->next_node = newNode;
    }

    T pop_front() {
        if (empty()) return T();

        Node<T>* temp = list_head;
        T val = temp->retrieve();
        list_head = temp->next();
        delete temp;
        return val;
    }

    T pop_end() {
        if (empty()) return T();

        if (list_head->next() == nullptr) {
            return pop_front();
        }

        Node<T>* ptr = list_head;
        while (ptr->next()->next() != nullptr) {
            ptr = ptr->next();
        }

        T val = ptr->next()->retrieve();
        delete ptr->next();
        ptr->next_node = nullptr;
        return val;
    }

    void delete_at_position(int position) {
        if (position == 1) {
            pop_front();
            return;
        }

        Node<T>* prev = list_head;
        int count = 1;

        while (count < position - 1 && prev != nullptr) {
            prev = prev->next();
            count++;
        }

        if (prev == nullptr || prev->next() == nullptr) return;

        Node<T>* curr = prev->next();
        prev->next_node = curr->next();
        delete curr;
    }

    void update(int k, T newValue) {
        Node<T>* ptr = list_head;
        int count = 1;

        while (ptr != nullptr && count < k) {
            ptr = ptr->next();
            count++;
        }

        if (ptr != nullptr) {
            ptr->set_data(newValue);
        }
    }

    int erase(T value) {
        int removed = 0;

        while (list_head != nullptr && list_head->retrieve() == value) {
            pop_front();
            removed++;
        }

        Node<T>* ptr = list_head;
        while (ptr != nullptr && ptr->next() != nullptr) {
            if (ptr->next()->retrieve() == value) {
                Node<T>* temp = ptr->next();
                ptr->next_node = temp->next();
                delete temp;
                removed++;
            }
            else {
                ptr = ptr->next();
            }
        }
        return removed;
    }

    void sortAscending() {
        for (Node<T>* i = list_head; i != nullptr; i = i->next()) {
            for (Node<T>* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void sortDescending() {
        for (Node<T>* i = list_head; i != nullptr; i = i->next()) {
            for (Node<T>* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data < j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    void swap_first_two() {
        if (list_head == nullptr || list_head->next() == nullptr) return;
        swap(list_head->data, list_head->next()->data);
    }

    void traverse() const {
        Node<T>* ptr = list_head;
        while (ptr != nullptr) {
            cout << ptr->retrieve() << " -> ";
            ptr = ptr->next();
        }
        cout << "NULL\n";
    }
};

/* =======================
            MAIN
   ======================= */
int main() {
    List<int> ls;   // 👈 template usage

    ls.push_end(7);
    ls.push_end(11);
    ls.traverse();

    ls.push_front(17);
    ls.traverse();

    ls.push_end(4);
    ls.traverse();

    ls.insert_at_position(2, 1);
    ls.traverse();

    ls.sortAscending();
    ls.traverse();

    ls.sortDescending();
    ls.traverse();

    ls.pop_front();
    ls.traverse();

    ls.pop_end();
    ls.traverse();

    ls.delete_at_position(2);
    ls.traverse();

    ls.update(2, 8);
    ls.traverse();

    cout << "Size: " << ls.size() << endl;

    ls.swap_first_two();
    ls.traverse();

    return 0;
}





/////////////////////////////////////// Without Template ///////////////////////////////////////////////////////









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

    // Accessors
    int retrieve() const {
        return data;
    }

    Node* next() const {
        return next_node;
    }

    // Mutators
    void set_data(int val) {
        data = val;
    }

    void set_next(Node* next) {
        next_node = next;
    }

    // Friend class to allow List to modify next_node
    friend class List;
};

/* =======================
        List Class
   ======================= */
class List {
private:
    Node* list_head;

public:
    /* Constructor */
    List() {
        list_head = nullptr;
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
        return list_head == nullptr;
    }

    Node* head() const {
        return list_head;
    }

    int front() const {
        if (empty()) {
            cout << "List is empty\n";
            return -1;
        }
        return list_head->retrieve();
    }

    int end() const {
        if (empty()) {
            cout << "List is empty\n";
            return -1;
        }
        Node* ptr = list_head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }
        return ptr->retrieve();
    }

    int size() const {
        int count = 0;
        for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            count++;
        }
        return count;
    }

    int count(int value) const {
        int node_count = 0;
        for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            if (ptr->retrieve() == value) {
                node_count++;
            }
        }
        return node_count;
    }

    /* =======================
            Mutators
       ======================= */

       // Insert at head
    void push_front(int value) {
        Node* newNode = new Node(value, list_head);
        list_head = newNode;
    }

    // Insert at end
    void push_end(int value) {
        if (empty()) {
            push_front(value);
            return;
        }

        Node* ptr = list_head;
        while (ptr->next() != nullptr) {
            ptr = ptr->next();
        }

        ptr->next_node = new Node(value, nullptr);
    }

    // Insert at given position (1-based)
    void insert_at_position(int value, int position) {
        if (position == 1) {
            push_front(value);
            return;
        }

        Node* prev = list_head;
        int count = 1;

        while (count < position - 1 && prev != nullptr) {
            prev = prev->next();
            count++;
        }

        if (prev == nullptr) return;

        Node* newNode = new Node(value, prev->next());
        prev->next_node = newNode;
    }

    // Delete at start
    int pop_front() {
        if (empty()) return -1;

        Node* temp = list_head;
        int val = temp->retrieve();
        list_head = temp->next();
        delete temp;
        return val;
    }

    // Delete at end
    int pop_end() {
        if (empty()) return -1;

        if (list_head->next() == nullptr) {
            return pop_front();
        }

        Node* ptr = list_head;
        while (ptr->next()->next() != nullptr) {
            ptr = ptr->next();
        }

        int val = ptr->next()->retrieve();
        delete ptr->next();
        ptr->next_node = nullptr;
        return val;
    }

    // Delete at given position
    void delete_at_position(int position) {
        if (position == 1) {
            pop_front();
            return;
        }

        Node* prev = list_head;
        int count = 1;

        while (count < position - 1 && prev != nullptr) {
            prev = prev->next();
            count++;
        }

        if (prev == nullptr || prev->next() == nullptr) return;

        Node* curr = prev->next();
        prev->next_node = curr->next();
        delete curr;
    }

    // Update kth node value
    void update(int k, int newValue) {
        Node* ptr = list_head;
        int count = 1;

        while (ptr != nullptr && count < k) {
            ptr = ptr->next();
            count++;
        }

        if (ptr != nullptr) {
            ptr->set_data(newValue);
        }
    }

    // Remove all occurrences of value
    int erase(int value) {
        int removed = 0;

        while (list_head != nullptr && list_head->retrieve() == value) {
            pop_front();
            removed++;
        }

        Node* ptr = list_head;
        while (ptr != nullptr && ptr->next() != nullptr) {
            if (ptr->next()->retrieve() == value) {
                Node* temp = ptr->next();
                ptr->next_node = temp->next();
                delete temp;
                removed++;
            }
            else {
                ptr = ptr->next();
            }
        }
        return removed;
    }

    // Sort Ascending
    void sortAscending() {
        for (Node* i = list_head; i != nullptr; i = i->next()) {
            for (Node* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    // Sort Descending
    void sortDescending() {
        for (Node* i = list_head; i != nullptr; i = i->next()) {
            for (Node* j = i->next(); j != nullptr; j = j->next()) {
                if (i->data < j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    // Swap first two nodes' values
    void swap_first_two() {
        if (list_head == nullptr || list_head->next() == nullptr) return;
        swap(list_head->data, list_head->next()->data);
    }

    // Traverse
    void traverse() const {
        Node* ptr = list_head;
        while (ptr != nullptr) {
            cout << ptr->retrieve() << " -> ";
            ptr = ptr->next();
        }
        cout << "NULL\n";
    }
};

/* =======================
            MAIN
   ======================= */
int main() {
    List ls;

    ls.push_end(7);
    ls.push_end(11);
    ls.traverse();

    ls.push_front(17);
    ls.traverse();

    ls.push_end(4);
    ls.traverse();

    ls.insert_at_position(2, 1);
    ls.traverse();

    ls.sortAscending();
    ls.traverse();

    ls.sortDescending();
    ls.traverse();

    ls.pop_front();
    ls.traverse();

    ls.pop_end();
    ls.traverse();

    ls.delete_at_position(2);
    ls.traverse();

    ls.update(2, 8);
    ls.traverse();

    cout << "Size: " << ls.size() << endl;

    ls.swap_first_two();
    ls.traverse();

    return 0;
}


