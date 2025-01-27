#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> v)
{
    // Lambda expression to print vector

    // Use of for_each(start , end , process)
    for_each(v.begin(), v.end(), [](int i)
             { cout << i << " "; });
    cout << endl;
}

auto privec = [](vector<int> arr)
{
    for (int n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
};

int main()
{
    vector<int> v{4, 1, 2, 3, 5, 2, 3, 1, 7};

    printVector(v);
    sort(v.begin(), v.end(), [](const int &a, const int &b) -> bool
         { return a > b; });
    cout << "\n";
    privec(v);
 
    // find_if(start , end , process stops when given condition is true)
    vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i)
                                      { return i > 4; });
    cout << "First Number greater than 4 : " << *p << endl;

    int count_5=count_if(v.begin(), v.end(),
            [](int a)
         { return a >= 5; });

         cout<<"the no of elements are :"<<count_5<<endl;
         
         int count_even=count_if(v.begin(),v.end(),
    	[](int a) {
    		return !(a%2);
    		}
    		);
    		
    		cout << "Even elements : " << count_even << endl;
    		
    return 0;
}