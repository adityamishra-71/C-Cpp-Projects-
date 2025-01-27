#include<iostream>
using namespace std;
class parent {
    public:
            virtual void show() {
                cout<<"Alto : show() of parent\n";
            }
};
class childA:public parent {
    public:
    void show() {
        cout<<"Fortune:show() of child A\n";
    }
};
int main()
{
    parent*p1=NULL;
    parent*p2=NULL;
    childA*ch1=NULL;

    p1=new parent();
    p1->show();
    p2=new childA();
    p2->show();

    ch1=new childA();
    ch1->show();
}