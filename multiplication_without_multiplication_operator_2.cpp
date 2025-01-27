#include <iostream>
using namespace std;

int multiply(int a, int b) {
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < b; ++i) { // Loop 'b' times
        sum += a; // Add 'a' to sum in each iteration
    }
    return sum;
}

int main() {
    int a, b;
    cout << "Input the first number: ";
    cin >> a;
    cout << "Input the second number: ";
    cin >> b;
    
    // Use the multiply function to calculate the product
    int result = multiply(a, b);
    cout << "Product of " << a << " and " << b << " : " << result << endl;

    return 0;
}
