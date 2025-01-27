#include <iostream>
#include <set>

using namespace std;

void show(set<int> ms) {
    set<int>::iterator it;
    cout<<"\n Contents of myset are : ";
    for( it=ms.begin(); it!=ms.end(); ++it) {
        cout<<*it<<" ";
    }
}
int main() {
    set<int> myset={2,2,2,5,5,7,4,8};
    show(myset);
    cout<<"\nsize of myset : "<<myset.size();

    myset.insert(10);
    myset.insert(20);
    myset.insert(5);
    show(myset);
    cout<<"\nsize of myset : "<<myset.size();

    myset.erase(7);
    cout<<"\n after erase the element : ";
    show(myset);
    cout<<"\nsize of myset : "<<myset.size();

    myset.clear();
    cout<<"\n after clear the set : ";
    show(myset);
    cout<<"\nsize of myset : "<<myset.size();

    set<int> set2={10,20,30,40,50};
    myset.swap(set2);
    cout<<"\n after swap the set : ";
    show(myset);
    cout<<"\n size of myset : "<<myset.size();
    show(set2);
    cout<<"\n size of set2 : "<<set2.size();

    auto it=myset.find(7);
    cout<<"\nvalue = "<<*it;

return 0;
}