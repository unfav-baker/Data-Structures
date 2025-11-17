                                   // Doubly Linked List //

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        value = val;
        next = NULL;
        prev = NULL;
    }
};


void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}


void insertAtEnd(Node*& head, int value) {

    if (head == NULL) {
        insertAtHead(head, value);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node(value);
    temp->next = newNode;
    newNode->prev = temp;
}


void insertAtMiddle(Node*& head, int value, int position) {

    if (position == 1) {
        insertAtHead(head, value);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}


void deleteAtStart(Node*& head) {

    if (head == NULL) return;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}


void deleteAtEnd(Node*& head) {

    if (head == NULL) return;
    if (head->next == NULL) {
        deleteAtStart(head);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void deleteAtMiddle(Node*& head, int position) {

    if (position == 1) {
        deleteAtStart(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position) {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}


void updateValue(Node*& head, int k, int updatedValue) {
    Node* temp = head;
    int count = 1;

    while (count < k) {
        temp = temp->next;
        count++;
    }

    temp->value = updatedValue;
}

void count(Node* head) {
    int c = 0;
    Node* temp = head;

    while (temp != NULL) {
        c++;
        temp = temp->next;
    }

    cout << "Total nodes: " << c << endl;
}


void swap(Node*& head) {

    if (head == NULL || head->next == NULL) return;

    int x = head->value;
    head->value = head->next->value;
    head->next->value = x;
}


void sortAscending(Node*& head) {

    if (head == NULL || head->next == NULL) return;

    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (current->value > nextNode->value) {
                int temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next;
        }

        current = current->next;
    }
}


void sortDescending(Node*& head) {

    if (head == NULL || head->next == NULL) return;

    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;

        while (nextNode != NULL) {
            if (current->value < nextNode->value) {
                int temp = current->value;
                current->value = nextNode->value;
                nextNode->value = temp;
            }
            nextNode = nextNode->next;
        }

        current = current->next;
    }
}


int main() {

    Node* head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertAtEnd(head, 20);
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
