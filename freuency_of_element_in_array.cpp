#include<iostream>
using namespace std;

int countoccur(int nums[], int size, int n) {
    if (size == 0) {
        return 0;
    }
    int count = 0;
    if (nums[size - 1] == n) {
        count = 1;
    }
    return count + countoccur(nums, size - 1, n);
}

int main() {
    int nums[] = {3, 4, 5, 73, 9, 5, 3, 9, 3, 4, 3, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int n;
    cout<< "Enter the number to count: ";
    cin>> n;
    
    int count = countoccur(nums, size, n);
    cout << count;

    return 0;
}