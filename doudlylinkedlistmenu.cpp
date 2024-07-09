#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    
public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (!head) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAfter(int value) {
        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "No node exists after the given node with value " << value << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next) {
            nodeToDelete->next->prev = temp;
        }
        delete nodeToDelete;
    }

    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, nodeValue;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Delete after a given node\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;

            case 2:
                cout << "Enter the value of the node after which deletion should occur: ";
                cin >> nodeValue;
                dll.deleteAfter(nodeValue);
                break;

            case 3:
                dll.traverse();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
