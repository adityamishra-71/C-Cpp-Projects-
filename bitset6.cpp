/*#include<iostream>
#include<bitset>
using namespace std;
    int offNth(int n,int k){
    return n & ~(1 << k-1);
    }
int main(){
    int x=128;
    int result=offNth(x);
    cout<<"number of 1 is :"<<bitset<16>(x)<<endl;
    cout<<result;
}*/

#include<iostream>
#include<bitset>
using namespace std;

int main() {
int x = 170, res;
cout<<"\n"<<bitset<16>(x) <<" = " <<x ;
cout<<"\n"<<bitset<16> (1) <<" = 1";
cout<<"\n"<<bitset<16>(1<<3) <<" = 1<<3";
cout<<"\n"<<bitset<16>(~(1<<3)) <<" = ~(1<<3)";
cout<<"\n1) Turn Off k= 4th bit in a number:";
res = turnoffKthBit(x, 4);
cout<<"\n"<<bitset<16>(res)<<" = " <<res;
}