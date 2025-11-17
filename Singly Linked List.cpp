


                                                  // Singly Linked List //


#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next_value;

	Node(int val) {
		value = val;
		next_value = NULL;
	}
};
void traverse(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->value << "->";
		temp = temp->next_value;
	}cout << NULL << endl;
}

void insertAtHead(Node*& head, int value) {
	Node* newNode = new Node(value);
	newNode->next_value = head;
	head = newNode;

}

void insertionAtEnd(Node*& head, int value) {

	if (head == NULL) {
		insertAtHead(head, value);
		return;
	}
	Node* newNode = new Node(value);
	Node* temp = head;
	while (temp->next_value != NULL) {
		temp = temp->next_value;
	}
	temp->next_value = newNode;
	newNode->next_value = NULL;

}

void insertAtMiddle(Node*& head, int value, int position) {

	if (position == 1) {
		insertAtHead(head, value);
		return;
	}
	Node* newNode = new Node(value);
	Node* prev = head;
	int count = 1;
	while (count < (position - 1)) {
		prev = prev->next_value;
		count++;

	}
	newNode->next_value = prev->next_value;
	prev->next_value = newNode;

}

void deleteAtStart(Node*& head) {

	if (head == NULL) {
		return;

	}

	Node* temp = head;
	head = head->next_value;
	free(temp);

}

void deleteAtEnd(Node*& head) {
	if (head == NULL) {
		return;
	}
	Node* secondLastNode = head;
	while (secondLastNode->next_value->next_value
		!= NULL) {
		secondLastNode = secondLastNode->next_value;
	}
	Node* LastNode = secondLastNode->next_value;
	secondLastNode->next_value = NULL;
	free(LastNode);
}

void deleteAtMiddle(Node*& head, int position) {

	if (position == 1) {
		deleteAtStart(head);
	}
	Node* prev = head;
	int count = 1;
	while (count < (position - 1)) {
		prev = prev->next_value;
		count++;
	}
	// prev is now poiting to the position - 1

	Node* curr = prev->next_value;
	prev->next_value = curr->next_value;
	free(curr);
}

void updateValue(Node*& head, int k, int updatedValue) {
	if (head == NULL) {
		return;
	}
	Node* temp = head;
	int count = 1;
	while (count < k) {
		temp = temp->next_value;
		count++;
	}
	temp->value = updatedValue;
}

void count(Node* head) {

	if (head == NULL) {
		cout << "The Linked list is Empty" << endl;
		return;
	}

	Node* temp = head;
	int count = 1;
	while (temp != NULL) {
		temp = temp->next_value;
		count++;
	}
	cout << "The Number of Elements in the Linked List are : " << count << endl;// Here we write count+1 because loop condition becomes false when temp = NULL so that element will not be included 
}

void sortAscending(Node*& head) {

	if (head == NULL || head->next_value == NULL) {
		return; // already sorted
	}

	Node* current = head;

	while (current != NULL) {
		Node* nextNode = current->next_value;

		while (nextNode != NULL) {
			if (current->value > nextNode->value) {
				// swap values
				int temp = current->value;
				current->value = nextNode->value;
				nextNode->value = temp;
			}
			nextNode = nextNode->next_value;
		}

		current = current->next_value;
	}
}



void sortDescending(Node*& head) {

	if (head == NULL || head->next_value == NULL) {
		return; // already sorted
	}

	Node* current = head;

	while (current != NULL) {
		Node* nextNode = current->next_value;

		while (nextNode != NULL) {
			if (current->value < nextNode->value) {
				// swap values
				int temp = current->value;
				current->value = nextNode->value;
				nextNode->value = temp;
			}
			nextNode = nextNode->next_value;
		}

		current = current->next_value;
	}
}


void swap(Node*& head) {
	int x;
	x = head->value;
	head->value = head->next_value->value;
	head->next_value->value = x;
}

int main() {
	Node* Node1 = new Node(7);
	Node* Node2 = new Node(11);
	Node1->next_value = Node2;
	Node* head = Node1;
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
	count(head);
	swap(head);
	traverse(head);
}