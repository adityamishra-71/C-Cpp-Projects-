//Use of stack from C++ STL Library
#include <iostream> 
#include <stack> 
using namespace std;
int main() 
{   stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(23);
    stack.push(24);
    stack.push(25);
    
	cout<<"\ntop of element :  " <<stack.top();
	cout<<"\nsize of stack  :  " <<stack.size() ; 
	stack.pop();
    stack.pop();
    
    cout<<"\n element of stack : \n";
    while (!stack.empty()) 
	{   cout<<stack.top()<<endl;
        stack.pop();
    }
    
}//end of main()
