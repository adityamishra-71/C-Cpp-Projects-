#include<iostream>
using namespace std;
 class Test
    { 
        public:
        int a, b;
        Test() //Default Constructor
        { 
            a = 100;
            b = 100;
            cout<<"default constructor";
        }
        Test(int x ,int y){
            a=x;
            b=y;
            cout<<"/nperameter constructor";
        }
        Test(Test &t1){
            a=t1.a;
            cout<<"\n copy constructor";
        }
 };
 int main(){
    Test obj1;
    Test obj2(200,300);
 }