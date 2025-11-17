// Circular Singly Linked List //

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = NULL;
    }
};

// Traverse circular list
void traverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->value << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

// Insert at head
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        newNode->next = newNode; // circular
        head = newNode;
        return;
    }

    Node* temp = head;

    // go to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertionAtEnd(Node*& head, int value) {

    if (head == NULL) {
        insertAtHead(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert at middle (position)
void insertAtMiddle(Node*& head, int value, int position) {

    if (position == 1) {
        insertAtHead(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Sort ascending (swap values)
void sortAscending(Node*& head) {
    if (head == NULL || head->next == head)
        return;

    Node* current = head;

    do {
        Node* nextNode = current->next;

        while (nextNode != head) {
            if (current->value > nextNode->value) {
                int temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next;
        }

        current = current->next;
    } while (current != head);
}

// Sort descending
void sortDescending(Node*& head) {
    if (head == NULL || head->next == head)
        return;

    Node* current = head;

    do {
        Node* nextNode = current->next;

        while (nextNode != head) {
            if (current->value < nextNode->value) {
                int temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next;
        }

        current = current->next;
    } while (current != head);
}

// Delete at start
void deleteAtStart(Node*& head) {

    if (head == NULL)
        return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    Node* deleteNode = head;
    temp->next = head->next;
    head = head->next;
    free(deleteNode);
}

// Delete at end
void deleteAtEnd(Node*& head) {

    if (head == NULL)
        return;

    if (head->next == head) {
        deleteAtStart(head);
        return;
    }

    Node* temp = head;

    while (temp->next->next != head) {
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = head;
    free(del);
}

// Delete at middle
void deleteAtMiddle(Node*& head, int position) {

    if (position == 1) {
        deleteAtStart(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

// Update value at position
void updateValue(Node*& head, int k, int updatedValue) {

    if (head == NULL)
        return;

    Node* temp = head;
    int count = 1;

    while (count < k) {
        temp = temp->next;
        count++;
    }

    temp->value = updatedValue;
}

// Count nodes
void count(Node* head) {
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    int c = 0;
    Node* temp = head;

    do {
        c++;
        temp = temp->next;
    } while (temp != head);

    cout << "Total nodes: " << c << endl;
}

// Swap first two nodes (value)
void swap(Node*& head) {
    if (head == NULL || head->next == head) return;

    int x = head->value;
    head->value = head->next->value;
    head->next->value = x;
}

int main() {

    Node* head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertionAtEnd(head, 20);
    insertAtMiddle(head, 7, 2);

    traverse(head);

    sortAscending(head);
    traverse(head);

    sortDescending(head);
    traverse(head);

    deleteAtStart(head);
    traverse(head);

    deleteAtEnd(head);
    traverse(head);

    deleteAtMiddle(head, 2);
    traverse(head);

    updateValue(head, 1, 99);
    traverse(head);

    count(head);

    swap(head);
    traverse(head);

    return 0;
}
