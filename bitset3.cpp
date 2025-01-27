#include<iostream>
#include<bitset>
using namespace std;

int main() {
    int x=128;
    int y=x&(x-1); //this is used for turn off the last binary bit of number

    cout<<"a="<<bitset<16>(x)<<endl;
    cout<<"b="<<bitset<16>(x-1)<<endl;
    cout<<"c="<<bitset<16>(y)<<endl;

    return 0;
}