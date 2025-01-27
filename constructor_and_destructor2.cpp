#include<iostream>
using namespace std;

class Store{
    int a,b;
    public:
    void get(){
        cout << endl << "Enter no. of Apple: " ;
        cin >> a;
        cout << endl << "Enter no. of Banana: " ;
        cin >> b;
    }
    void show(){
        cout << "\nTotal Apple" << a;
        cout << "\nTotal Apple" << b;
    }
    
    Store operator +(Store &s2){
        Store tempRes;
        tempRes.a = a + s2.a;
        tempRes.b= b+s2.b;
        return(tempRes);
    }


    Store operator +(int n){
        Store temp;
        temp.a = a+n;
        temp.b = b+n;
        return(temp);
    }

    int operator +(Store &s2){
        int temp;
        temp = a + s2.a;
        temp = temp + b+s2.b;
        return(temp);
    }

};

int main(){
    Store  s1,s2,s3,s4;
    cout << "\nEnter Data of Store-1";
    s1.get();
    cout << "\nEnter Data of Store-2";
    s2.get();
    s3 = s1 + s2;
    s4 = s1 +5;
    cout << "\n\n Data of Store-1";
    s1.show();
    cout << "\n\n Data of Store-2";
    s2.show();
    cout << "\n\n Data of Store-3";
    s3.show();
    
    s4 = s1 +5;
    cout << "\n\n Data of Store-4";
    s4.show();

    int total = s1+s2;
    cout << "\n\nTotal no. of units" << endl;
    return 0;
}