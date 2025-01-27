#include<iostream>
using namespace std;

int fabi(int n){
    if(n==0)
    return 0;
    else if(n==1){
        return 1;
    }
    return fabi(n-1)+fabi(n-2);
}
int main(){
    int n;
    cout<<"enter the value of n : "<<endl;
    cin>>n;
   int ans =fabi(n); 
   cout<<ans;
   return 0;
}