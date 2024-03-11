#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method sorts the linked list using the       |
    //   |   Selection Sort algorithm.                         |
    //   | - Iterates through the list to find the smallest    |
    //   |   node and swaps it with the current node.          |
    //   |                                                     |
    //   | Return type: void                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses nested while loops for traversal.            |
    //   | - Swaps values, not nodes, for simplicity.          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
void selectionSort() {
    if (head == nullptr || head->next == nullptr) {
        return; // The list is either empty or has only one element and is already sorted.
    }

    Node* current = head;
    // Outer loop: Iterates through the entire list
    while (current != nullptr) {
        Node* minNode = current;
        Node* nextNode = current->next;
        // Inner loop: Finds the minimum value in the rest of the list
        while (nextNode != nullptr) {
            if (nextNode->value < minNode->value) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap values if the minimum is not the current node
        if (minNode != current) {
            int temp = current->value;
            current->value = minNode->value;
            minNode->value = temp;
        }

        current = current->next; // Move to the next element in the list
    }
}

};


