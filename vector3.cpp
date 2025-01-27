#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> myvector1 = { 11, 22, 33, 44 }; 
    vector<int> myvector2 = { 55, 66, 77, 88};
    // using swap() function to swap
    // elements of vector 
    cout<<"\n"<<myvector2.at(3);
    myvector1.swap(myvector2);
    cout<<"\n"<<myvector2.at(3);
}