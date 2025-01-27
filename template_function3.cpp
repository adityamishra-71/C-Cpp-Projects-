#include<iostream>
using namespace std;

template<typename T,typename U>
class A
{
    T x; U y;
    public:
        A() {
            cout<<"Constructor called : "<<sizeof(A)<<endl;
        }

};

int main() {
    A<char,char>obj1;
    A<int,double>obj2;
    A<float,float>obj3;
    return 0;
}