#include <bits/stdc++.h>
using namespace std;
void change(int &a) {
a = a + 1;
}
int main() {
int m;
cout<<"Enter any num: ";
cin>>m;
cout<<"\n value of m="<<m;
change(m);
cout<<"\n after change m= "<<m;
}