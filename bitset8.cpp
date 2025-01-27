#include <iostream>
#include <bitset>
using namespace std;

int main() {
    char ch = 'B';
    int res;
    cout << "87654321";
    cout << "\n" << bitset<8>(ch) << " = " << ch;
    cout << "\n" << bitset<8>(' ') << " = " << "space"; // Corrected ' ' for space character
    res = ch;
    cout << "\n" << bitset<8>(res) << " - " << res;

    return 0;
}
