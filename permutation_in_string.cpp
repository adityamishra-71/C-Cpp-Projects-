#include<iostream>
using namespace std;
void generate_Permutations(string text, int left, int right) {
    // Base case: if left is equal to right, print the current permutation
    if (left == right) {
        cout << text << endl;
    } else {
        // Iterate through the string
        for (int i = left; i <= right; i++) {
            // Swap the current index with the left index
            swap(text[left], text[i]);
            // Recur with the next index
            generate_Permutations(text, left + 1, right);
            // Backtrack and undo the swap
            swap(text[left], text[i]);
        }
    }
}
int main(){
string text;
cout << "Input a string: ";
cin >> text;
cout << "All permutations of the string: " << endl;
 generate_Permutations(text, 0, text.length() - 1);
return 0;
}