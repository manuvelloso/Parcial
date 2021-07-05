
#include <iostream>
#include <string>

using namespace std;

class cFraccion {

private:
    int num, den;
public:
    cFraccion(int a, int b) {
        num = a; den = b;
    }
    bool operator==(cFraccion otra)
    {
        if (this->den == otra.den && this->num == otra.num)
            return true;
        else
            return false;
    }
    friend bool operator<(cFraccion a, cFraccion b);
    friend bool operator>(cFraccion a, cFraccion b);
    bool operator==(float otra) 
    { 
        float A = (float)this->num / this->den;
        if (A == otra)
            return true;
        return false; 
    }
    bool operator==(string otra)
    { 
        string str = (to_string(num) + "/" + to_string(den)).c_str();
        if (str == otra)
            return true;
        return false; 
    }
    bool operator!=(cFraccion a) { return *this != a; }
};
bool operator<(cFraccion a, cFraccion b) { 
    float A = (float)a.num / a.den;
    float B = (float)b.num / b.den;
    return (A < B);
}
bool operator>(cFraccion a, cFraccion b) { return !(a < b); }


int main()

{

    int a, b, c, d;

    string test;

    cin >> a >> b >> c >> d;

    cin >> test;

    cFraccion F1(a, b), F2(c, d);

    cout << (F1 < F2) << endl;

    cout << (F1 > F2) << endl;

    cout << (F1 == .5) << endl;

    cout << (F1 == test) << endl;

}