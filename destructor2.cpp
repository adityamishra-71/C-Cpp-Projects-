#include<bits/stdc++.h>
using namespace std;
class Demo{
    public:
        string name;
        // Demo(){
            
        //     cout << endl <<"Default Constructor"<< name ;
        // }
        // Demo(string n){
            
        //     name = n;
        //     cout << endl << "Parametrized Constructor" << name;
        // }
        // void show(){
        //     cout << "show started.... " << endl;
        //     cout << "show completed... " << endl;
        //     Demo obja("A");
        // }
        // ~Demo(){
        //     cout << endl << "Destructor Called" << name;
        // }
        Demo();
        Demo(string n);
        ~Demo();
};
Demo::Demo(){
            
            cout << endl <<"Default Constructor"<< name ;
        }
Demo::Demo(string n){
             
name = n;
cout << endl << "Parametrized Constructor" << name;            
}                   
        
        Demo::~Demo(){
            cout << endl << "Destructor Called" << name;
        }
void show(){
            cout << endl << "show started.... " << endl;
            Demo obja("A");
            cout << endl << "show completed... " << endl;
            
        }

 Demo obj("C");
int main(){
     cout << endl << "main started.... " << endl;
     Demo obj("B");
     show();
     cout << endl<<"main completed... " << endl;
     return 0;
}