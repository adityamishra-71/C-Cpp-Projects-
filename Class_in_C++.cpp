#include <bits/stdc++.h>
using namespace std;
class Student
{

int roll;

string name;

public:

void input();

void output();
};

int main(){
    Student s1;
    Student s2;
    Student *s3=new Student();

    cout<<"\n\nFill tha data od s1";
    s1.input();
    cout<<"\n\n Fill tha data od s2";
    s2.input();
    cout<<"\n\n Fill tha data od s3";
    s3->input();

    cout<<"\nAll data saved.";
    s1.output();
    s2.output();
    s3->output();
}

void Student::input() { 
cout<<"\nEnter roll no :";
cin>>roll;
cout<<"\nEnter name :";
cin>>name;
}
inline void Student::output()
{ cout<<"\nROLL : "<<roll;
cout<<"\nNAME : "<<name;
}