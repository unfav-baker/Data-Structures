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

class Stack {
    Node* top; 

public:
    Stack() {
        top = NULL;
    }

    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        cout << temp->value << " popped from stack\n";
        top = top->next;
        free(temp);
    }

   
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << top->value << endl;
    }

    
    bool isEmpty() {
        return top == NULL;
    }

    
    void display() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();

    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop(); 

    cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
}