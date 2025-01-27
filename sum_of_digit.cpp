#include<iostream>
using namespace std;
int sum_of_digit(int number)
{
    if(number>=0 && number<=9)
    return number;

    return(number%10)+sum_of_digit(number/10);
}
int main()
{
    int n;
    cout<<"Input a number : ";
    cin>>n;
    int sum_of_digits=sum_of_digit(n);
    cout<<sum_of_digits<<endl;
    return 0;
}