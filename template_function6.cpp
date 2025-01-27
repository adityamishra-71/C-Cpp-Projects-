#include<iostream>
using namespace std;

template <class T>
class Box{
    public:
    Box(T a) {
        cout<<"\n\n a="<<"size of data in bytes: "<<sizeof(a);
    }
};

int main() {
    Box<char> obj1('x');
    Box<int> obj2(22);
    Box<float> obj3(2.25);

    return 0;
}