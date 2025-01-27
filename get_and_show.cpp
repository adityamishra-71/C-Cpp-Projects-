#include<iostream>
using namespace std;

class Store{
    int a,b;
    public:
    void get() {
        cout<<"Enter no. of Apple :  ";
        cin>>a;
        cout<<"Enter no. of Banana : ";
        cin>>b;
    }
    void show() {
        cout<<"\nTotal Apple"<<a;
        cout<<"\nTotal Apple"<<b;
    }
    Store operator+(Store &s2) {
        Store tempRes;
        tempRes.a=a+s2.a;
        tempRes.b=b+s2.b;
        tempRes.b=b+s2.b;
        return(tempRes);
    }
};
int main() {
    Store s1,s2,s3;
    cout<<"\n Enter Data of Store-1";
    s1.get();
    s2.get();
    s3.get();
}