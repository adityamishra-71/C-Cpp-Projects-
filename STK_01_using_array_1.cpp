#include <iostream>
#define MAX_SIZE 5
using namespace std;

int stack[MAX_SIZE], top = -1;
int choice = 0;

void push();
void pop();
void show(); // LIFO
void peek();

int main()
{
    cout << "***Stack operations using array*********" << endl;
    cout << "----------------------------------------------" << endl;
    while (choice != 5)
    {
        cout << "\n\nChoose one from the below options..." << endl;
        cout << "\n1. Push\n2. Pop\n3. Show\n4. Peek\n5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
    	   case 1:	push();		break;
           case 2:	pop();		break;
           case 3:	show();		break;
           case 4:	peek();		break;
           case 5:	cout <<"\nExiting...." << endl;	  break;
           default:cout <<"\nPlease Enter valid choice " << endl;
        } // end of switch
    }     // end of while loop
    return 0;
} // end of main()

void push()
{   int val;
    if (top == MAX_SIZE - 1)
        cout << "\n Overflow" << endl;
    else
    {	cout << "Enter the value? ";
        cin >> val;
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{	if (top == -1)
        cout << "Underflow" << endl;
    else
    {	stack[top] = 0;
        top = top - 1;
    }
}

void show()
{
    for (int i = top; i >= 0; i--)
    {	cout << stack[i] << endl;
    }

    if (top == -1)
    {	cout << "Stack is empty" << endl;
    }
}

void peek()
{	if (top > -1)
    {	cout << "Peek: Top of the stack = " << stack[top] << endl;
    }
    else
    {	cout << "Stack is empty" << endl;
    }
}

