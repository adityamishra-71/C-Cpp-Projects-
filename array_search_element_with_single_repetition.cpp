#include <iostream>
#include <bitset>
using namespace std;

    int signleNumber(int arr[],int size){
        int res=arr[0];
        for(int i=1; i<size;i++){
            res =res^ arr[i]
        }
        return res;
int main() {
    int arr[5]={2,1,3,2,1};
    int result=signleNumber(arr,5)
    }
    cout<<result;
}