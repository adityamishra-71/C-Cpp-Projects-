#include <iostream>
#include <cstdlib>  // For malloc() and free()

using namespace std;

class Node 
{   
    public:
        Node* prev;
        int data;
        Node* next;
};

Node* head = nullptr;

void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

int main() 
{
    int choice = 0;

    while (choice != 9) 
    {
        cout << "\n**Main Menu\n";
        cout << "\nChoose one option from the following list ...\n";
        cout << "\n===============================================\n";
        cout << "\n1. Insert in beginning\n2. Insert at last\n3. Insert at any random location\n4. Delete from Beginning\n";
        cout << "5. Delete from last\n6. Delete the node after the given data\n7. Search\n8. Show\n9. Exit\n";
        cout << "\nEnter your choice?\n";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                deletion_beginning();
                break;
            case 5:
                deletion_last();
                break;
            case 6:
                deletion_specified();
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

void insertion_beginning() 
{
    Node* new_node = new Node();
    int item;
    cout << "Enter the value to be inserted: ";
    cin >> item;

    new_node->data = item;
    new_node->prev = nullptr;
    new_node->next = head;

    if (head != nullptr) 
    {
        head->prev = new_node;
    }
    
    head = new_node;
    cout << "Node inserted at the beginning.\n";
}

void insertion_last() 
{
    Node* new_node = new Node();
    int item;
    cout << "Enter the value to be inserted: ";
    cin >> item;

    new_node->data = item;
    new_node->next = nullptr;
    
    if (head == nullptr) 
    {
        new_node->prev = nullptr;
        head = new_node;
        cout << "Node inserted at the last.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    cout << "Node inserted at the last.\n";
}

void insertion_specified() 
{
    Node* new_node = new Node();
    int item, pos;
    cout << "Enter the value to be inserted: ";
    cin >> item;
    cout << "Enter the position after which the node should be inserted: ";
    cin >> pos;

    Node* temp = head;
    for (int i = 1; i < pos; i++) 
    {
        temp = temp->next;
        if (temp == nullptr) 
        {
            cout << "There are less than " << pos << " nodes.\n";
            return;
        }
    }

    new_node->data = item;
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != nullptr) 
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    cout << "Node inserted after position " << pos << ".\n";
}

void deletion_beginning() 
{
    if (head == nullptr) 
    {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) 
    {
        head->prev = nullptr;
    }
    
    delete temp;
    cout << "Node deleted from the beginning.\n";
}

void deletion_last() 
{
    if (head == nullptr) 
    {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }

    if (temp->prev != nullptr) 
    {
        temp->prev->next = nullptr;
    } 
    else 
    {
        head = nullptr;
    }

    delete temp;
    cout << "Node deleted from the last.\n";
}

void deletion_specified() 
{
    if (head == nullptr) 
    {
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    int item;
    cout << "Enter the value of the node to be deleted: ";
    cin >> item;

    Node* temp = head;
    while (temp != nullptr && temp->data != item) 
    {
        temp = temp->next;
    }

    if (temp == nullptr) 
    {
        cout << "Node with value " << item << " not found.\n";
        return;
    }

    if (temp->prev != nullptr) 
    {
        temp->prev->next = temp->next;
    } 
    else 
    {
        head = temp->next;
    }

    if (temp->next != nullptr) 
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node with value " << item << " deleted.\n";
}

void display() 
{
    Node* temp = head;
    if (temp == nullptr) 
    {
        cout << "List is empty.\n";
        return;
    }

    cout << "Printing values of Doubly Linked List...\n";
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void search() 
{
    int item, pos = 1;
    bool found = false;

    cout << "Enter the value to search: ";
    cin >> item;

    Node* temp = head;
    while (temp != nullptr) 
    {
        if (temp->data == item) 
        {
            cout << "Item found at position " << pos << ".\n";
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) 
    {
        cout << "Item not found in the list.\n";
    }
}