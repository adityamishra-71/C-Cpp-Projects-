#include<iostream>
using namespace std;

int multiply(int n1, int n2) {
    if(n1==0||n2==0){
    return 0;
    }
    return n1+multiply(n1,n2-1);
}

int main() {
    int n1,n2;
    cout<<"Input the first number : ";
    cin>>n1;
    cout<<"Input the second number : ";
    cin>>n2;
    
    int result=multiply(n1,n2);
    cout<<"Product of "<<n1<<" and "<<n2<<" : "<<result;

    return 0;
}