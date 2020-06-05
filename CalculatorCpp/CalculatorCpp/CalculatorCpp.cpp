// CalculatorCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
constexpr  int NMAX = 200;
typedef enum {
    operatieAdunare = 1,
    operatieScadere = 2,
    operatieInmultire = 3,
    operatieImpartire = 4,
    operatieEroare = 5,
}ETipOperatie;

typedef double MyNumberType;

MyNumberType Adunare(MyNumberType a, MyNumberType b)
{
    return (a + b);
}

MyNumberType Scadere(MyNumberType a, MyNumberType b)
{
    return (a - b);
}

MyNumberType Inmultire(MyNumberType a, MyNumberType b)
{
    return (a * b);
}

MyNumberType Impartire(MyNumberType a, MyNumberType b)
{
    return (a / b);
}

ETipOperatie DeterminaOperatie(char* buffer)
{
    char* pReturn = NULL;
    pReturn = strchr(buffer, '+');
    if (pReturn != NULL) return operatieAdunare;
    else
    {
        pReturn = strchr(buffer, '-');
        if (pReturn != NULL) return operatieScadere;
        {
            pReturn = strchr(buffer, '*');
            if (pReturn != NULL) return operatieInmultire;
            else
            {
                pReturn = strchr(buffer, '/');
                if (pReturn != NULL) return operatieImpartire;
                else
                {
                    return operatieEroare;
                }
            }
        }
    }
}
int main()
{
    ifstream fpIn;
    ofstream fpOut;
    char buffer[NMAX];
    MyNumberType a;
    MyNumberType b;
    MyNumberType rezultat=0;
    char numefIn[80] = "calc.in";
    char numefOut[80] = "calc.out";
    ETipOperatie tipOperatie;
    cout << "Open files"<<endl;
    fpIn.open(numefIn);
    fpOut.open(numefOut);
    cout << "Procesinf file"<< numefIn;
    if ((fpIn.is_open()) && (fpOut.is_open()))
    {
        do
        {
            a = 0;
            b = 0;
            fpIn.getline(buffer, NMAX);
            sscanf_s(buffer, "%g %g", &a, &b);
            tipOperatie = DeterminaOperatie(buffer);
            switch (tipOperatie)
            {
                case operatieAdunare: rezultat = Adunare(a, b);
                    break;
                case operatieScadere: rezultat = Scadere(a, b);
                    break;
                case operatieInmultire: rezultat = Inmultire(a, b);
                    break;
                case operatieImpartire: rezultat = Impartire(a, b);
                    break;
                default:;
            }
            fpOut.precision(100);
            fpOut << rezultat <<endl;

        } while (!fpIn.eof());
    }
    else
    {
        cout <<"error opening file";
        if (fpIn.is_open()) cout << numefIn<<endl;
        if (fpOut.is_open()) cout << numefOut<<endl;
    }
    if (fpIn.is_open()) fpIn.close();
    if (fpOut.is_open()) fpOut.close();
    cout <<"Done.";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
