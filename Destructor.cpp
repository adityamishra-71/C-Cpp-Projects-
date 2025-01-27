/*#inclue<iostream>
using namespace std;
Class Demo() 
{ name = "No Name";
cout<<"\nDefault Constructor of:"<<name; }
Demo(string n)
{ name = n;
cout<<"\nParam Constructor of:"<<name;
}
~Demo()
cout<<"\nDestructor of:"<<name;
};
void sho
{ cout<<"\n show() started....."; Demo obja("A"); cout<<"\n show() completed...";
int main()
{ show();
cout<<"\n main() started....."; cout<<"\n main() completed...";
}//end of main*/

#include<bits/stdc++.h>
using namespace std;
class Demo{
    public:
        string name;
        Demo(){
            
            cout << endl <<"Default Constructor"<< name ;
        }
        Demo(string n){
            
            name = n;
            cout << endl << "Parametrized Constructor" << name;
        }
        void show(){
            cout << "show started.... " << endl;
            cout << "show completed... " << endl;
            Demo obja("A");
        }
        ~Demo(){
            cout << endl << "Destructor Called";
        }
};
void show(){
            cout << "show started.... " << endl;
            Demo obja("A");
            cout << "show completed... " << endl;
            
        }

int main(){
    cout << endl << "main started.... " << endl;
     Demo obj("B");
     show();
     cout << endl<<"main completed... " << endl;
     return 0;
}