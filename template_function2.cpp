/*#include<iostream>
using namespace std;

template <typename T>
class Array{
    private:
        T* ptr;
        int size;
    public:
        Array(T arr[],int s);
        void print(); 
};

template <typename T>
Array<T>::Array(T arr[],int s){
    ptr = new T[s];
    size = s;
    for(int i=0;i<size;i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print(){
    
    for(int i=0;i<size;i++)
        cout << " " << *(ptr+i);
    cout << endl;
}

int main(){

    return 0;
}*/

#include<iostream>
using namespace std;

template<typename T>
class Array
{
private:
    /* data */
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template <typename T>
Array<T>::Array(T arr[],int s)
{
    ptr =new T[s];
    size=s;
    for (int i = 0; i < size; i++)
    {
        ptr[i]=arr[i];
    }
}

template <typename T>
void Array<T>::print(){
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout<<" "<<*(ptr +i);
    }
    cout<<endl;
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    Array<int> obj1(arr1, 5);
    obj1.print();

    double arr2[] = {1.4, 1.5, 2.5, 3.5, 5.5};
    Array<double> obj2(arr2, 5); // Change size to 5
    obj2.print();

    return 0;
}