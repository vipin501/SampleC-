/* Class, Abstaction ,overloading and STL concepts*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ComplexNo
{
public:
    ComplexNo()                             //default constructor
    {
        real = 0;
        img = 0;
    }

    ComplexNo(int a, int b) : real(a), img(b) {} //parametrized constructor

    ComplexNo(const ComplexNo& c)           //copy constructor
    {
        real = c.real;
        img = c.img;
    }

    void PrintComplexNo()
    {
        cout << "Complex no:" << real << "+ i(" << img <<")"<< endl;
    }

    bool operator==(const ComplexNo& c)     //overloading == operator
    {
        if (this->real == c.real && this->img == c.img)
            return true;

        return false;
    }

    ComplexNo operator+(const ComplexNo& c)     //overloading + operator
    {
        ComplexNo result;
        result.real = this->real + c.real;
        result.img = this->img + c.img;

        return result;
    }

    ComplexNo operator-(const ComplexNo& c)     //overloading - operator
    {
        ComplexNo result;
        result.real = this->real - c.real;
        result.img = this->img - c.img;

        return result;
    }

    ComplexNo operator*(const ComplexNo& c)     //overloading * operator
    {
        ComplexNo result;
        result.real = (this->real)*c.real - (this->img)*c.img;
        result.img = (this->real)*c.img + (this->img)*c.real;

        return result;
    }

    void operator=(const ComplexNo& c)          //overloading assignment operator
    {
        this->real = c.real;
        this->img = c.img;
    }

    bool operator<(const ComplexNo& c)          //overloading < operator for sorting purpose
    {
        float r1, r2;
        r1 = sqrt((this->real)*(this->real) + (this->img)*(this->img));
        r2 = sqrt(c.real * c.real + c.img * c.img);

        return r1 < r2;                         //We can have any criteria, here we are determining the lesser                 
                                                //complex no. based on the resultant of the complex no.
    }

private:
    int real, img;
};

/* Class and STL concepts*/
int main()
{
    ComplexNo c1(3,4);
    ComplexNo c2(c1);
    ComplexNo c3 = c1 + c2;
    ComplexNo c4 = c1 - c3;
    ComplexNo c5 = c4 * c3;

    vector<ComplexNo> c_vec;
    c_vec.push_back(c1);
    c_vec.push_back(c5);
    c_vec.push_back(c4);
    c_vec.push_back(c3);
    c_vec.push_back(c2);

    cout << "Before sorting\n";
    for (auto it = c_vec.begin(); it != c_vec.end(); ++it)
        (*it).PrintComplexNo();

    cout << "**********************\n";
    sort(c_vec.begin(), c_vec.end());         // Uses '<' overloaded operated member function to do sorting
    cout << "**********************\n";

    cout << "After sorting based on resultant\n";
    for (auto it = c_vec.begin(); it != c_vec.end(); ++it)
        (*it).PrintComplexNo();

    cout << "**********************\n";
    cout << "Duplicate complex no.\n";
    for (int i = 0; i < c_vec.size(); ++i)
    {
        for (int j = i + 1; j < c_vec.size(); ++j)
        {
            if (c_vec[i] == c_vec[j])
            {
                cout << "**********************\n";
                c_vec[i].PrintComplexNo();
                cout << "Above Duplicate entries at " << i + 1 << " and " << j + 1 << " position\n";
            }
        }
    }


    c_vec.clear();
    return 0;
}
