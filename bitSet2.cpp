#include<iostream>
#include<bitset>
using namespace std;

int main() {
    int a=32;
    int b=a>>1;

    cout<<"a="<<bitset<8>(a)<<endl;
    cout<<"b="<<bitset<8>(b)<<endl;

    int c=a<<3;

    cout<<"c="<<bitset<8>(c)<<endl;
    return 0;
}