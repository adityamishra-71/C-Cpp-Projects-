#include<iostream>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string &text, int start, int end) {
    if (start >= end) // Base case: If the start index is greater than or equal to end index
        return true;
    if (text[start] != text[end]) // If the characters at start and end are not the same
        return false;
    return isPalindrome(text, start + 1, end - 1); // Recursive call for the next set of characters
}

int main() {
    string text;
    cout << "input string: ";
    cin >> text;

    bool palindrome = isPalindrome(text, 0, text.length() - 1);
    if (palindrome)
        cout << "\nthe string is a palindrome";
    else
        cout << "\nthe string is not a palindrome";

    return 0;
}
