#include <iostream>
using namespace std;
int calcArraySum(int arr[], int n){
   int sumVal = 0;
   for(int i = 0; i < n; i++){
      sumVal += arr[i];
   }
   return sumVal;
}
int main(){
   int arr[] = {1, 4, 5, 7, 6};
   int n = sizeof(arr)/ sizeof(arr[0]);
   cout<<"The sum of elements in a given array is"<<calcArraySum(arr, n);
   return 0;
}