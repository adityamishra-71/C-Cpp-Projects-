#include <iostream>
#include <functional>
#include <numeric>

using namespace std;

int myfunction(int x,int y) {
    return x+2*y;
}
class myclass {
    public:
    int operator()(int x,int y) {
        return x+3*y;
    }
};

int main() {
    int init = 100;
    int numbers[]={10,20,30};

    cout<<"using default accumulate : ";
    cout<<accumulate(numbers,numbers+3,init);
    cout<<"\n";

    cout<<"using functional's minus : ";
    cout<<accumulate(numbers,numbers+3,init,minus<int>());
}