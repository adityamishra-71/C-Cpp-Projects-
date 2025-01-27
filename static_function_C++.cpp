#include <bits/stdc++.h>
using namespace std;
class abc
{
    int x;

    static int count;
    public:
    static void show1(){
        cout<<count;
    }
    void show2(){
        cout<<x<<count;
    }
};
int abc::count=10;
int main(){
    abc o1;
    abc::show1();
    o1.show2();
    o1.show1();
}