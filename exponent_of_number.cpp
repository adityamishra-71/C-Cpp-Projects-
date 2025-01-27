#include<iostream>
using namespace std;
int power(int b, int e){
    if(e==0){
        return 1;
    }
    return b*power(b,e-1);
}
int main(){
    int b,e;
    cout<<"enter base : ";
    cin>>b;
    cout<<"enter exponent :";
    cin>>e;
    int result=power(b,e);
    cout<<b<<" raise to power "<<e<<" is : "<<result;
    return 0;
}