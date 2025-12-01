#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T>* next_value;

    Node(T val) {
        value = val;
        next_value = NULL;
    }
};

template <typename T>
void traverse(Node<T>* head) {
    Node<T>* temp = head;
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next_value;
    }
    cout << "NULL" << endl;
}

template <typename T>
void insertAtHead(Node<T>*& head, T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next_value = head;
    head = newNode;
}

template <typename T>
void insertionAtEnd(Node<T>*& head, T value) {
    if (head == NULL) {
        insertAtHead(head, value);
        return;
    }
    Node<T>* newNode = new Node<T>(value);
    Node<T>* temp = head;
    while (temp->next_value != NULL) {
        temp = temp->next_value;
    }
    temp->next_value = newNode;
}

template <typename T>
void insertAtMiddle(Node<T>*& head, T value, int position) {
    if (position == 1) {
        insertAtHead(head, value);
        return;
    }
    Node<T>* newNode = new Node<T>(value);
    Node<T>* prev = head;
    int count = 1;

    while (count < position - 1) {
        prev = prev->next_value;
        count++;
    }

    newNode->next_value = prev->next_value;
    prev->next_value = newNode;
}

template <typename T>
void deleteAtStart(Node<T>*& head) {
    if (head == NULL) return;

    Node<T>* temp = head;
    head = head->next_value;
    delete temp;
}

template <typename T>
void deleteAtEnd(Node<T>*& head) {
    if (head == NULL) return;
    if (head->next_value == NULL) { // only one node
        delete head;
        head = NULL;
        return;
    }
    Node<T>* secondLast = head;

    while (secondLast->next_value->next_value != NULL) {
        secondLast = secondLast->next_value;
    }

    Node<T>* lastNode = secondLast->next_value;
    secondLast->next_value = NULL;
    delete lastNode;
}

template <typename T>
void deleteAtMiddle(Node<T>*& head, int position) {
    if (position == 1) {
        deleteAtStart(head);
        return;
    }

    Node<T>* prev = head;
    int count = 1;

    while (count < position - 1) {
        prev = prev->next_value;
        count++;
    }

    Node<T>* curr = prev->next_value;
    prev->next_value = curr->next_value;
    delete curr;
}

template <typename T>
void updateValue(Node<T>*& head, int k, T updatedValue) {
    if (head == NULL) return;

    Node<T>* temp = head;
    int count = 1;

    while (count < k) {
        temp = temp->next_value;
        count++;
    }

    temp->value = updatedValue;
}

template <typename T>
void countNodes(Node<T>* head) {
    if (head == NULL) {
        cout << "The Linked list is Empty" << endl;
        return;
    }

    Node<T>* temp = head;
    int count = 0;

    while (temp != NULL) {
        temp = temp->next_value;
        count++;
    }

    cout << "The Number of Elements in the Linked List are : " << count << endl;
}

template <typename T>
void sortAscending(Node<T>*& head) {
    if (head == NULL || head->next_value == NULL) return;

    Node<T>* current = head;

    while (current != NULL) {
        Node<T>* nextNode = current->next_value;

        while (nextNode != NULL) {
            if (current->value > nextNode->value) {
                T temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next_value;
        }
        current = current->next_value;
    }
}

template <typename T>
void sortDescending(Node<T>*& head) {
    if (head == NULL || head->next_value == NULL) return;

    Node<T>* current = head;

    while (current != NULL) {
        Node<T>* nextNode = current->next_value;

        while (nextNode != NULL) {
            if (current->value < nextNode->value) {
                T temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next_value;
        }
        current = current->next_value;
    }
}

template <typename T>
void swapHead(Node<T>*& head) {
    if (head == NULL || head->next_value == NULL) return;

    T x = head->value;
    head->value = head->next_value->value;
    head->next_value->value = x;
}


int main() {
    Node<int>* Node1 = new Node<int>(7);
    Node<int>* Node2 = new Node<int>(11);
    Node1->next_value = Node2;

    Node<int>* head = Node1;

    traverse(head);
    insertAtHead(head, 17);
    traverse(head);
    insertionAtEnd(head, 4);
    traverse(head);
    insertAtMiddle(head, 2, 1);
    traverse(head);
    sortAscending(head);
    traverse(head);
    sortDescending(head);
    traverse(head);
    deleteAtStart(head);
    traverse(head);
    deleteAtEnd(head);
    traverse(head);
    deleteAtMiddle(head, 3);
    traverse(head);
    updateValue(head, 2, 8);
    traverse(head);
    countNodes(head);
    swapHead(head);
    traverse(head);

    return 0;
}
