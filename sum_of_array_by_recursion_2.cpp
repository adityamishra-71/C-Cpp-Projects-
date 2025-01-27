#include<iostream>
using namespace std;
 int arraySum(int arr[],int size){
    if(size==0) {
        return 0;
    }
    return arr[size-1]+arraySum(arr,size-1);
}

int main(){
    int nums[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(nums)/sizeof(nums[0]);
    cout<<"array elemets"<<endl;
    for(int i =0;i<size;i++){
        cout<<nums[i]<<"";
        int sum=arraySum(nums,size);
        cout<<"\n sum of array elements using recirsion :"<<sum;
    return 0;
    }
}