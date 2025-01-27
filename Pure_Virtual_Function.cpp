#include<iostream>
using namespace std;
class Parent {
    public:
            virtual void show() {
                cout<<"Alto : show() of parent\n";
            }
};
class ChildA:public Parent {
    public:
    void show() {
        cout<<"Fortune:show() of child A\n";
    }
};
class ChildB:public Parent {
    public:
    void show() {
        cout<<"BMW:show() of child B\n";
    }
};
int main()
{
    int choice;
    cout<<"1-ChildA \n2-ChildB \n";
    cout<<"Enter your choice : ";
    cin>>choice;

    Parent*p=NULL;
    if(choice==1) {
        p=new ChildA();
    }
    else {
        p=new ChildB();
    }
    p->show();

    return 0;
}