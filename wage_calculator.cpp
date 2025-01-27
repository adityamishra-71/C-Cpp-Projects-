#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double hourlyRate, hoursWorked, regularPay, overtimePay, totalPay;
    const double overtimeThreshold = 40.0;
    const double overtimeMultiplier = 1.5;

    // Get input from the user
    cout << "Enter hourly rate: ";
    cin >> hourlyRate;
    cout << "Enter hours worked: ";
    cin >> hoursWorked;

    // Calculate regular pay
    if (hoursWorked <= overtimeThreshold) {
        regularPay = hoursWorked * hourlyRate;
        overtimePay = 0.0;
    } else {
        regularPay = overtimeThreshold * hourlyRate;
        overtimePay = (hoursWorked - overtimeThreshold) * hourlyRate * overtimeMultiplier;
    }

    // Calculate total pay
    totalPay = regularPay + overtimePay;

    // Display results
    cout << fixed << setprecision(2);
    cout << "Regular pay: $" << regularPay << endl;
    cout << "Overtime pay: $" << overtimePay << endl;
    cout << "Total pay: $" << totalPay << endl;

    return 0;
}