#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = nullptr;

void beginInsert();
void lastInsert();
void randomInsert();
void beginDelete();
void lastDelete();
void randomDelete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        cout << "\n\n**Main Menu";
        cout << "\nChoose one option from the following list ...";
        cout << "\n===============================================\n";
        cout << "\n1. Insert in beginning\n2. Insert at last\n3. Insert at any random location\n4. Delete from Beginning";
        cout << "\n5. Delete from last\n6. Delete node after specified location\n7. Search for an element\n8. Show\n9. Exit\n";
        cout << "\nEnter your choice? ";
        cin >> choice;

        switch (choice) {
            case 1:
                beginInsert();
                break;
            case 2:
                lastInsert();
                break;
            case 3:
                randomInsert();
                break;
            case 4:
                beginDelete();
                break;
            case 5:
                lastDelete();
                break;
            case 6:
                randomDelete();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                cout << "Please enter a valid choice..\n";
        }
    }

    return 0;
}

void beginInsert() {
    cout << "Code for beginInsert()" << endl;
    Node* ptr = new Node;
    int item;
    if (ptr == nullptr) {
        cout << "\n Overflow";
    } else {
        cout << "\n Enter the value: ";
        cin >> item;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        cout << "The Node is inserted";
    }
}

void lastInsert() {
    cout << "Code for lastInsert()" << endl;
    Node* ptr = new Node;
    Node* temp = head;
    int item;
    if (ptr == nullptr) {
        cout << "\n Overflow";
    } else {
        cout << "Enter the value: ";
        cin >> item;
        ptr->data = item;
        ptr->next = nullptr;
        if (head == nullptr) {
            head = ptr;
        } else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = ptr;
        }
        cout << "\n Node inserted";
    }
}

void randomInsert() {
    cout << "Code for randomInsert()" << endl;
    int loc, item;
    Node* ptr = new Node;
    Node* temp = head;

    if (ptr == nullptr) {
        cout << "\n Overflow";
    } else {
        cout << "\n Enter the value: ";
        cin >> item;
        ptr->data = item;
        cout << "\n Enter the location where you want to insert: ";
        cin >> loc;
        if (loc == 1) {
            ptr->next = head;
            head = ptr;
        } else {
            for (int i = 1; i < loc - 1; i++) {
                if (temp == nullptr) {
                    cout << "\n Can't insert at this location\n";
                    delete ptr; // Clean up memory
                    return;
                }
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "\n Can't insert at this location\n";
                delete ptr; // Clean up memory
                return;
            }
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
}

void beginDelete() {
    cout << "Code for beginDelete()" << endl;
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from beginning";
}

void lastDelete() {
    cout << "Code for lastDelete()" << endl;
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
        cout << "Node deleted from last";
        return;
    }
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
    cout << "Node deleted from last";
}

void randomDelete() {
    cout << "Code for randomDelete()" << endl;
    int loc;
    cout << "Enter the location of the node to delete: ";
    cin >> loc;
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    if (loc == 1) {
        head = head->next;
        delete temp;
        cout << "Node deleted at location " << loc;
        return;
    }
    Node* prev = nullptr;
    for (int i = 1; i < loc; i++) {
        if (temp == nullptr) {
            cout << "Location out of bounds\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Location out of bounds\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Node deleted at location " << loc;
}

void search() {
    cout << "Code for search()" << endl;
    int item;
    cout << "Enter the value to search: ";
    cin >> item;
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == item) {
            cout << "Element found at position " << pos;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found";
}

void display() {
    cout << "Code for display()" << endl;
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr";
}