#include <bits/stdc++.h>
using namespace std;

int main() {
    map <char,int> m = {
                            {'A',10},
                            {'B',20},
                            {'C',30},
                            {'A',40},
                            {'F',60},
                            {'F',65},
                            {'F',70},

                        };
    m.emplace('D',1);
    m.emplace('E',2);
    m.at('C')=50;

    m['C']=200;
    m.insert(make_pair('C',300));

    cout<<"\n m['C']="<<m['C']<<endl;
    cout<<"\n m['Z']="<<m['Z']<<endl;

    m['B']=m['B']+5;
    m['B']+=1;

    m['Z']=m['Z']+5;

    for(auto & record : m) {
        cout<<record.first<<" = "<<record.second<<endl;
    }
}