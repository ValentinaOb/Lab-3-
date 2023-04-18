#include <iostream>
#include <math.h>
#include <string>
#include <clocale>
#include <complex>
using namespace std;

typedef double ComplexDouble1;


class ComplexVector1
{
    ComplexDouble1** v;
    int num, num1;
    int state = 0;
public:
    ComplexVector1() : ComplexVector1(2, 2) {}
    ComplexVector1(int n, int n1);
    ComplexVector1(int n, int n1, ComplexDouble1&);
    ComplexVector1(int n, int n1, ComplexDouble1*);
    ComplexVector1(const ComplexVector1& s);
    ComplexVector1& operator=(const ComplexVector1& s);
    ~ComplexVector1() {
        num = 0;
    }
    ComplexDouble1 El(int i);
    ComplexDouble1 Poss(double& b);

    ComplexVector1 Subtr(ComplexVector1& b);
    ComplexVector1 Mult(short  s);
    bool More(ComplexVector1& s);
    bool Less(ComplexVector1& s);
    bool Equal(ComplexVector1& s);
    bool More1(ComplexVector1& s);
    bool Less1(ComplexVector1& s);
    bool Equal1(ComplexVector1& s);

    void Output1();
    void Input1();
    ComplexVector1 Add(ComplexVector1& b);
};

ComplexVector1::ComplexVector1(int num, int num1) {
    if (num <= 0)    num = 2;
    if (num1 <= 0)    num1 = 2;
    int n = num;
    int n1 = num1;
    v = new ComplexDouble1*[num];

    for (int i = 0; i < n; i++) {
        v[i] = new ComplexDouble1 [num];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n1; j++) {
            v[i][j] = 0;
        }
    }
}
ComplexVector1::ComplexVector1(int num, int num1, ComplexDouble1& b) : ComplexVector1(num, num1) {
    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        v[i][j] = b;
    }
}

ComplexVector1::ComplexVector1(int num, int num1, ComplexDouble1* p) : ComplexVector1(num, num1) {
    if (p != nullptr)

        for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++)
        {
            v[i][j] = p[i];
        }
}

ComplexVector1::ComplexVector1(const ComplexVector1& s) {
    num = s.num;
    num1 = s.num1;
    state = 0;
   // ComplexDouble1** v = new ComplexDouble1 * [num];
    v = new ComplexDouble1 * [num];
    for (int i = 0; i < num; i++) {
        v[i] = new ComplexDouble1[num1];
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num1; j++) {
            v[i][j] = rand() % 20;
        }
    }

    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) v[i][j] = s.v[i][j];
}

ComplexVector1& ComplexVector1::operator=(const ComplexVector1& s) {

    if (num != s.num)
    {
        if (v) { delete[] v[0]; }
        num = s.num;
        ComplexDouble1** v = new ComplexDouble1 * [num];
        for (int i = 0; i < num; i++) {
            v[i] = new ComplexDouble1[num1];
        }

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num1; j++) {
                v[i][j] = rand() % 20;
            }
        }
        state = 0;
    }
    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++)  v[i][j] = s.v[i][j];

    return *this;
}


double& ComplexVector1::El(int i) {
    int p, p1;
    cout << "\nInput position: ";
    cin >> p;
    cin >> p1;
    cout << "V: ";
    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        cout << v[i][j] << " ";
    }
    cout << "\n";

    ComplexDouble1 e;
    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        if ((i == p) && (j == p1)) {
            e = v[i][j];
            cout << "Element: " << e;
        }
    }
    return e;
}

double& ComplexVector1::Poss(double& b) {

    int a = 1;
    cout << "V: ";

    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        cout << v[i][j] << " ";
    }

    cout << "\nInput position of element: ";
    int p, p1;
    cin >> p;
    cin >> p1;
    cout << "\nV: ";

    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        if ((i == p) && (j == p1)) { v[i][j] = a; }
        cout << v[i][j] << " ";
        return v[i][j];
    }

    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        return v[i][j];
    }
}

ComplexVector1 ComplexVector1::Subtr(ComplexVector1& b) {
    int tnum, tnum1;
    tnum = num < b.num ? num : b.num;
    tnum1 = num1 < b.num1 ? num1 : b.num1;

    ComplexVector1 tmp(tnum, tnum1);
    for (int i = 0; i < tnum; i++) for (int j = 0; j < tnum1; j++) tmp.v[i][j] = v[i][j] - b.v[i][j];
    return tmp;

    return ComplexVector1(0, 0);
}

ComplexVector1  ComplexVector1::Mult(short s) {

    cout << "Input Multiplier: "; cin >> s;

    cout << "V: ";
    ComplexVector1 tmp(num, num1);  for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++)
    {
        cout << v[i][j] << " ";

    }
    cout << "\n";


    for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
        tmp.v[i][j] = v[i][j] * s;

    }
    return tmp;
}

bool ComplexVector1::Less(ComplexVector1& s) {

    return ((num < s.num) && (num1 < s.num1));
}
bool ComplexVector1::More(ComplexVector1& s) {

    if ((num > s.num) && (num1 > s.num1)) return true;
    return false;
}
bool ComplexVector1::Equal(ComplexVector1& s) {

    if ((num == s.num) && (num1 == s.num1)) return true;
    return false;
}

bool ComplexVector1::Less1(ComplexVector1& s) {
    for (int i = 0; i < num; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < num; i++)
    {
        cout << s.v[i] << " ";
    }
    cout << "\n";
    num = s.num;
    int q = 0, q1 = 0;
    for (int i = 0; i < num; i++) for (int j = 0; j < num; j++)
    {
        q += s.v[i][j];
        q1 += v[i][j];
    }
    if (q < q1) { return true; }
    return false;
}
bool ComplexVector1::More1(ComplexVector1& s) {
    num = s.num;
    int q = 0, q1 = 0;
    for (int i = 0; i < num; i++) for (int j = 0; j < num; j++)
    {
        q += s.v[i][j];
        q1 += v[i][j];
    }
    if (q > q1) { return true; }
    return false;
}
bool ComplexVector1::Equal1(ComplexVector1& s) {
    num = s.num;
    int q = 0, q1 = 0;
    for (int i = 0; i < num; i++) for (int j = 0; j < num; j++)
    {
        q += s.v[i][j];
        q1 += v[i][j];
    }
    if (q == q1) { return true; }

    return 0;
}


void ComplexVector1::Input1() {
    int rows = 0, cols = 0;

    do {
        cout << "Input size: \n";
        cin >> rows >> cols;
    } while ((rows <= 0) && (cols <= 0));

    if ((num != rows) && (num != cols)) {
        num = rows;
        num1 = cols;

        ComplexDouble1** v = new ComplexDouble1 * [num];
        for (int i = 0; i < num; i++) {
            v[i] = new ComplexDouble1[num1];
        }


        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num1; j++) {
                v[i][j] = rand() % 20;
            }
        }

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num1; j++) {
                cout << v[i][j] << "\t";
            }
        }

        for (int i = 0; i < num; i++) {
            if (v) { delete[] v[i]; }
        }


        for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
#if defined(_MSC_VER)
            cout << " v [ " << i << " ][ " << j << " ] real img  "; cin >> v[i][j];
#else 
            double re, im;
            cout << " v [ " << i << " ][ " << j << " ] real img  "; cin >> re >> im;
            v[i].real(re);
            v[i].imag(im);
#endif    
        }
    }
}

void ComplexVector1::Output1() {
    if ((num != 0) && (num1 != 0)) {
        for (int i = 0; i < num; i++) for (int j = 0; j < num1; j++) {
            cout << " v [ " << i << " ][ " << j << " ]   " << v[i][j] << '\t';
            cout << endl;
        }
    }
}
ComplexVector1 ComplexVector1::Add(ComplexVector1& b) {
    int tnum, tnum1;
    tnum = num < b.num ? num : b.num;
    tnum1 = num1 < b.num1 ? num1 : b.num1;

    ComplexVector1 tmp(tnum, tnum1);
    for (int i = 0; i < tnum; i++) for (int j = 0; j < tnum1; j++) tmp.v[i][j] = v[i][j] + b.v[i][j];
    return tmp;

    return ComplexVector1(1, 1);
}


int main()
{
    ComplexDouble1 a(1), b, c;
    cout << a << endl;
#if defined(_MSC_VER)
    b = 21.3;
    b = 22.3;
#else 
    b.real(21.3);
    b.imag(22.3);
#endif  

    cout << b << endl;
    c = a + b;
    cout << c << endl;

    cout << " Test  " << endl;
    ComplexVector1 VecObj2, VecObj3(5, 5);
    cout << "VecObj \n";
    VecObj2.Output1();
    cout << "VecObj1 \n";
    VecObj3.Output1();
    cout << " Input a " << endl;

    cout << a << endl;
    ComplexVector1 VecObj4(10, a);
    VecObj4.Output1();

    
    VecObj2.Input1();
    cout << endl;
    VecObj2.Output1();

    
    cout << "\nEl \n";
    VecObj3 = VecObj2.El(1);
    cout << "\n";
    

    cout << "\nAdd \n";
    VecObj3 = VecObj2.Add(VecObj4);
    VecObj3.Output1();

    cout << "\nSubtr \n";
    VecObj3 = VecObj2.Subtr(VecObj4);
    VecObj3.Output1();
    cout << endl;


    cout << "\Mult \n";
    VecObj3 = VecObj2.Mult(5);
    VecObj3.Output1();
    cout << endl;


    cout << "\nLess \n";

    if (VecObj2.Less(VecObj4) == 1) {
        cout << "true";
    }
    else cout << "false";
    cout << "\n";


    cout << "\nMore \n";

    if (VecObj2.More(VecObj4) == 1) {
        cout << "true";
    }
    else cout << "false";
    cout << "\n";


    cout << "\nEqual \n";

    if (VecObj2.Equal(VecObj4) == 1) {
        cout << "true";
    }
    else cout << "false";
    cout << "\n";



    return 1;
}
