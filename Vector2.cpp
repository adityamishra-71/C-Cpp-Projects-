#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1; // Growable array
     
    for (int i = 11; i <= 20; i++) 
    { 
        v1.push_back(i);
    } 

    cout << "\n\n";
    for (int i = 0; i < 10; i++) 
    {
        cout << v1[i] << " ";
    }
    cout << "\n\n";

    for (int i = 0; i < v1.size(); i++) 
    {
        cout << v1[i] << " ";
    }
    cout << "\n\n";

    for (int i = v1.size() / 2; i < v1.size(); i++) 
    {
        cout << v1[i] << " ";
    }
    cout << "\n\n";

    // Error: Invalid condition for reverse loop
    for (int i = v1.size() / 2 - 1; i >= 0; i--) 
    {
        cout << v1[i] << " ";
    }
    cout << "\n\n";

    int sum = 0;
    for (int i = 0; i <= v1.size() - 1; i++) 
    {
        int rem = v1[i] % 2;
        if (rem == 0) 
        {
            sum = sum + v1[i];
        }
    }
    // cout << sum; // Uncomment if you want to display the sum

    cout << "\n\n";
    for (int i = 0; i <= v1.size() - 1; i++) 
    {
        int rem = v1[i] % 2;
        if (rem != 0) 
        {
            cout << " " << v1[i];
            cout << " " << v1[i] * v1[i];
            cout << "\n";
        }
    }

    int mid = v1.size() / 2;
    for (int i = v1.size() - 1; i >= mid; i--) 
    {
        cout << v1[i] << " ";
    }
    cout << "\n\n";

    printf("\nEnter 5 data:\n");
    for (int i = 1; i <= 5; i++) 
    {
        int data;
        cout << "Enter any number: ";
        cin >> data;
        v1.push_back(data);
    }

    cout << "\n";
    int n = v1.size();
    cout << "After adding elements, the size of the vector is: " << n << "\n";

    // Error: Incorrect syntax for insert
    v1.insert(v1.begin(), 5);  // Insert 5 at the beginning
    v1.insert(v1.begin() + 3, 6); // Insert 6 at the 4th position in the vector
    cout << "After insertion:\n";
    for (int i = 0; i < v1.size(); i++) 
    {
        cout << v1.at(i) << " ";
    }

    v1.erase(v1.begin());

    cout<<"\nafter the deleting the first element\n";
    for (int i = 0; i < v1.size(); i++) 
    {
        cout << v1.at(i) << " ";
    }
     cout<<"\nafter the deleting the last element\n";

    

     v1.erase(v1.end()-1);
    for (int i = 0; i < v1.size(); i++) 
    {
        cout << v1.at(i) << " ";
        
    vector<int> myvector1 = { 11, 22, 33, 44 }; vector<int> myvector2 = { 55, 66, 77, 88};

// using swap() function to swap

// elements of vector myvector1.swap(myvector2);

cout<<"\n"<<myvector2.at(3);
}
    
    cout << "\n\nmax size of vector" << v1.max_size();
    
    return 0;
}