/* Class, Constructor and Deep copy*/
#include <iostream>
#include <string>
using namespace std;

class TestClass
{
    int* a;
public:
    TestClass(int ia)
    {
        a = new int;
        *a = ia;
    }

    TestClass(TestClass& objNewTest)	// copy constructor for deep copy
    {
        a = new int;
        *a = objNewTest.getvalue();
    }

    void display()
    {
        cout << "a is :" << *a << endl;
    }
    int getvalue()
    {
        return *a;
    }
    void setvalue(int ia)
    {
        *a = ia;
    }

    ~TestClass()		//Destructor
    {
        cout << "Destroying object:" << *a << endl;
        delete a;
    }
};

int main()
{
    TestClass obj1(11);
    TestClass  obj2 = obj1; // copy constructor allocates and assigns int pointer member. Synthesised contructor from complier would
                            // have just referred the passing object and not create separate copy.
    obj1.display(); //display obj1
    obj2.display(); //display obj2

    cout<<"Changing value of obj1"<<endl;
	obj1.setvalue(12); // change value of obj1. Because of deep copy the changes are not reflected in obj2
    obj1.display(); // display obj1
    obj2.display(); // display obj2

    return 0;
}
