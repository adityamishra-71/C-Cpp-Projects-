#include<iostream>
using namespace std;
class Student{
    private:
            int marks;
    public:
            void input()
            {
                cout<<"Enter marks : ";
                cin>>marks;
            }
            void output()
            {
                cout<<"\nYour Marks : "<<marks;
            }
            friend void graceMarks(int m);
};
Student std1;
void graceMarks(int m)
{
    std1.marks=std1.marks+m;
}
int main() {
    std1.input();
    std1.output();
    graceMarks(2);
    std1.output();
}