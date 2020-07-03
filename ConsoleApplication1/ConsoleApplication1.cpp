// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Obiect
{
public:
    virtual double CalculeazaArie() = 0;
};
//------------------------------------------------------------------
//                     Mostenire                                   |
//------------------------------------------------------------------
//drept de acces in     | Modificator de      | Drept de acces     |
//clasa de baza         | acces               | in clasa derivata  |
//------------------------------------------------------------------
// PUBLIC               | PUBLIC              | PUBLIC             |
// PRIVATE              | PUBLIC              | inaccesibil        |
// PROTECTED            | PUBLIC              | PROTECTED          |
//------------------------------------------------------------------
// PUBLIC               | PRIVATE             | PRIVATE            |
// PRIVATE              | PRIVATE             | inaccesibil        |
// PROTECTED            | PRIVATE             | PRIVATE            |
//------------------------------------------------------------------

class Punct : public Obiect
{
private:
    int x, y;
public:
    Punct() { x = 0; y = 0; };
    Punct(const Punct& p) { x = p.x; y = p.y; }; //copy contructor
    Punct(int x, int y) :x(x), y(y) {};
    int GetX(void) { return x; };
    int GetY(void) { return y; };
    virtual double CalculeazaArie() { return 0; };
    friend ostream& operator<<(ostream& os, const Punct& dt) {
        os << '('<<dt.x << ',' << dt.y<<')';
        return os;
    }
};

class Dreptunghi :public Punct
{
    Punct sus;
    Punct jos;
public:
    Dreptunghi() { ; };
    Dreptunghi(Punct s, Punct j) : sus(s), jos(j) { ; }
    double CalculeazaArie() { return (static_cast<long>(jos.GetX() - sus.GetX())) * (static_cast<long>(jos.GetY()) - sus.GetY()); };
    friend ostream& operator<<(ostream& os, const Dreptunghi& dt) {
        os << dt.sus << '/' << dt.jos;
        return os;
    }
};

class Cerc :public Punct
{
    Punct centru;
    int raza;
public:
    Cerc(Punct c, int r):centru(c),raza(r)
    {

    }
    double CalculeazaArie() { return 3.14 * raza * raza; };
};

int main()
{
    Punct p1(1, 2);
    Punct p2 = p1;
    cout << p1.GetX() << endl << p1.GetY() << endl;
    cout << p1 <<endl;
    cout << p2 <<endl;
    Cerc c1({ 1, 0 }, 2);
    Dreptunghi d1({ 0,1 }, { 2,2 });
    Obiect* lista[4] = { nullptr,nullptr,nullptr,nullptr };
    lista[0] = dynamic_cast<Obiect*> (&p1);
    lista[1] = dynamic_cast<Obiect*> (&p2);
    lista[2] = dynamic_cast<Obiect*> (&c1);
    lista[3] = dynamic_cast<Obiect*> (&d1);
    for (auto o : lista)
    {
        cout << o->CalculeazaArie()<<endl;
    }
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
