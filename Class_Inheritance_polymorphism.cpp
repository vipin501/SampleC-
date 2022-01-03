/* Class, Inheritance,Polymorphism and Casting*/
#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    Human(const string& str) :_name(str) {}
    virtual void GetInfo()
    {
        cout << "Hello, I am " << _name<<".";
    }
private:
    string _name;
};

class Student:public Human
{
public:
    Student(const string& str) :Human(str) {}
    void GetInfo()
    {
        Human::GetInfo();
        cout << " I am a student" << endl;
    }
};

class Teacher :public Human
{
public:
    Teacher(const string& str) :Human(str) {}
    void GetInfo()
    {
        Human::GetInfo();
        cout << " I am a Teacher" << endl;
    }
};


int main()
{
    Human* h1 = new Student("Sam");
    h1->GetInfo();
    Human* h2 = new Teacher("john");
    h2->GetInfo();
	
	Student* s1 = dynamic_cast<Student*>(h1);
    if (s1 != nullptr)
    {
        cout << "Cast successful\n";
        s1->GetInfo();
    }
    else
        cout << "Cast unsuccessful\n";

    Teacher* t1 = dynamic_cast<Teacher*>(h1);
    if (t1 != nullptr)
    {
        cout << "Cast successful\n";
        t1->GetInfo();
    }
    else
        cout << "Cast unsuccessful\n";

    delete h1;
    delete h2;
    return 0;
}
