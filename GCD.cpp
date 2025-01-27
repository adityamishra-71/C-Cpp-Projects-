#include<iostream>
using namespace std;

int gcd(int n1, int n2) {
    if(n2==0)
        return n1;
    if(n1==0)
        return n2;
    return gcd(n2,n1%n2);
}

int main() {
    int n1,n2;
    cout<<"Input the first number : ";
    cin>>n1;
    cout<<"Input the second number : ";
    cin>>n2;

    int result=gcd(n1,n2);
    cout<<"The GCD of "<<n1<<" and "<<n2<<" is : "<<result;

    return 0;
}