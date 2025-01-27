#include<iostream>
#include<array>
using namespace std;

int main() {
    array<int,10> arr={1,2,3,4,5,6};
    cout<<"The array elements are (using operator[]) : \n";
    for(int i=0;i<6;i++) {
        cout<<arr[i]<<" ";
    }

    cout<<"\nThe array elements are (using at()) : \n";
    for(int i=0;i<6;i++) {
        cout<<arr.at(i)<<" ";
    }

    cout<<"\nThe array element are (using iterator) : \n";
    for(auto it=arr.begin();it!=arr.end();it++)
        cout<<*it<<" ";

    //front
    cout<<"\n First element: "<<arr.front()<<endl;
    //back
    cout<<"\n First element: "<<arr.back()<<endl;
    //size
    cout<<"\n First element: "<<arr.size()<<endl;
    //max size
    cout<<"\n First element: "<<arr.max_size()<<endl;

    array<int,10> arr2;
    arr.swap(arr2);
    cout<<"\nAfter Swap() : "<<arr2.at(3);

    arr.empty() ? cout<<"\nArray empty" : cout<<"Array not empty";

    return 0;
}
