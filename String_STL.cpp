/* String manipulation, call by reference, few STL functions and various operations*/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class StringAnalyzer
{
public:
    StringAnalyzer(const string& s) :_sinput(s) {}		//constructor

    void CheckPallindrome()
    {
        cout << "Property:" << ++prop << "\n";
        string tmp(_sinput.rbegin(), _sinput.rend());
        if (tmp == _sinput)
            cout << "The string is a pallindrome\n";
        else
            cout << "The string in not a pallindrome\n";

        cout << "**********************\n";
    }

    void ContainsDigits()
    {
        cout << "Property:" << ++prop << "\n";
        if (_sinput.find_first_of("0123456789") != std::string::npos)
            cout << "The string contains digits\n";
        else
            cout << "The string does not contain digits\n";

        cout << "**********************\n";
    }

    void GetCharFrequency()
    {
        cout << "Property:" << ++prop << "\n";
        std::unordered_map<char, int> umap;
        for (int i = 0; i < _sinput.size(); ++i)
            umap[_sinput[i]]++;

        for (auto it = umap.begin(); it != umap.end(); ++it)
            cout << "Frequency of character:'" << it->first << "' is " << it->second << "\n";

        cout << "**********************\n";
    }

    void ResetPropertyCount() { prop = 0; }

    void RotateLeft(int x)
    {
        int d = x % _sinput.size();
        string tmp = _sinput;
        if (d != 0)
        {
            for (int i = 0; i < _sinput.size(); ++i)
            {
                if (i < d)
                    tmp[_sinput.size() + i - d] = _sinput[i];
                else
                    tmp[i - d] = _sinput[i];
            }
        }
        cout << "Input after " << x << " rotation is:" << tmp << "\n";
    }

private:
    std::string _sinput;
    static int prop;
};

int StringAnalyzer::prop = 0;

int main()
{
    string input1;
    cout << "Enter a string to analyze\n";
    cin >> input1;

    if (input1.empty())
    {
        cout << "Empty string exiting";
        return 0;
    }

    StringAnalyzer obj(input1);
    obj.CheckPallindrome();
    obj.ContainsDigits();
    obj.GetCharFrequency();
    obj.ResetPropertyCount();
    
    int x;
    cout << "Enter no. of indexes each char should be left rotated\n";
    cin >> x;
    obj.RotateLeft(x);

    return 0;
}