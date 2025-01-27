#include <iostream>
#include <bitset>
int toggleKthBit(int number, int k) {
    // Shift 1 left by k-1 positions to create a mask
    int mask = 1 << (k - 1);
    // Toggle the kth bit using XOR
    return number ^ mask;
}

int main() {
    int number, k;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "Enter the bit position to toggle (1-based index): ";
    std::cin >> k;

    int toggledNumber = toggleKthBit(number, k);

    std::cout << "The number after toggling the " << k << "th bit of " << number << " is " << toggledNumber << "." << std::endl;

    return 0;
}