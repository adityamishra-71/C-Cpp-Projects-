#include<iostream>
using namespace std;
class abc {
    int num;
    public:
    abc() {
    num=0;
    cout<<"Default Constructor";
}
    abc(int n) {
    cout<<"Parameterized Constructor";
    num=n;
}
};
int main() {
    abc o1;
    abc o2(50);
    }


/*#include <iostream>
using namespace std;

class abc {
    int num;
public:
    // Default Constructor
    abc() {
        num = 0;
        cout << "Default Constructor" << endl;
    }
    
    // Parameterized Constructor
    abc(int n) {
        num = n;
        cout << "Parameterized Constructor" << endl;
    }

    // Main function inside the class
    int main() {
        abc o1;        // Will call the default constructor
        abc o2(50);    // Will call the parameterized constructor
        return 0;
    }
};

int main() {
    abc obj;
    return obj.main();
}*/
