#include <iostream>
#include <bitset>
using namespace std;

int main() {

    int x = 168, i = 6;
    cout << "x=" << x << endl;
    cout << "i =" << i << endl;
    cout << "\n" << bitset<16>(x) << " = " << x << " =x";
    cout << "\n" << bitset<16>(1) << " = " << 1 << " =1";
    cout << "\n" << bitset<16>(1 << i) << " = " << (1 << i) << " =(1<<i)";
    cout << "\n" << bitset<16>((1 << i) - 1) << " = " << (1 << i) - 1;

    return 0;
}
