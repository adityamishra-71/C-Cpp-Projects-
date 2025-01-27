#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    string str = "HELLO WORLD";
    
    for (char &c : str) {
        c = tolower(c);
    }
    
    cout << "Lowercase: " << str << std::endl;
    return 0;
}