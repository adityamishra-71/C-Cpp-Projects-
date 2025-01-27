#include<iostream>
using namespace std;

template <typename T,typename U>

class A{
    T x; U y;
    public:
    A(){
        cout<<"\n\nConstructor\n"<<endl;
        cout<<"\nSizeof(x)= "<<sizeof(x);
        cout<<"\nSizeof(y)= "<<sizeof(y);
    }
};
int main(){
    A< char,char>obj1;
    A< int,double>obj2;
    A< double,long double>obj3;

    return 0;
}