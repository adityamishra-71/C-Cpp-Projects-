#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = nullptr;

void beginInsert();
void lastInsert();
void beginDelete();
void lastDelete();
void search();
void display();

int main() {
    int choice = 0;
    while (choice != 7) {
        cout << "\n**Main Menu\n";
        cout << "\nChoose one option from the following list ...\n";
        cout << "\n===============================================\n";
        cout << "\n1. Insert in beginning\n2. Insert at last\n3. Delete from Beginning\n4. Delete from last\n5. Search for an element\n6. Show\n7. Exit\n";
        cout << "\nEnter your choice?\n";
        cin >> choice;

        switch (choice) {
            case 1:
                beginInsert();
                break;
            case 2:
                lastInsert();
                break;
            case 3:
                beginDelete();
                break;
            case 4:
                lastDelete();
                break;
            case 5:
                search();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                cout << "Please enter a valid choice..\n";
        }
    }

    return 0;
}

void beginInsert() {
    Node* ptr = new Node();
    int item;

    cout << "\nEnter the node data: ";
    cin >> item;

    ptr->data = item;

    if (head == nullptr) {
        head = ptr;
        ptr->next = head; // Circular link
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        ptr->next = head;
        head = ptr;
        temp->next = head; // Maintain circular link
    }

    cout << "\nNode inserted at the beginning.\n";
}

void lastInsert() {
    Node* ptr = new Node();
    int item;

    cout << "\nEnter the node data: ";
    cin >> item;

    ptr->data = item;

    if (head == nullptr) {
        head = ptr;
        ptr->next = head; // Circular link
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head; // Maintain circular link
    }

    cout << "\nNode inserted at the end.\n";
}

void beginDelete() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    Node* temp = head;

    if (head->next == head) { // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* firstNode = head;
        temp->next = head->next;
        head = head->next;
        delete firstNode;
    }

    cout << "\nFirst node deleted.\n";
}

void lastDelete() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    Node* temp = head;

    if (head->next == head) { // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* lastNode = temp->next;
        temp->next = head;
        delete lastNode;
    }

    cout << "\nLast node deleted.\n";
}

void search() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    int item, i = 0;
    cout << "\nEnter the element to search: ";
    cin >> item;

    Node* temp = head;
    do {
        if (temp->data == item) {
            cout << "\nElement found at position " << i + 1 << ".\n";
            return;
        }
        temp = temp->next;
        i++;
    } while (temp != head);

    cout << "\nElement not found.\n";
}

void display() {
    if (head == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\nLinked list elements: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n"; // Indicates circular nature
}
//end of program