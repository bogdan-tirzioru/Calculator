// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>

//                      Precedenta operatorilor(C++98)
// Prioritate             Operatori                                      Evaluare 
//     1                  () [] -> :: .                                     ->
//     2                  ! ~ + - ++ -- & * (tip)                           <-
//                        sizeof new delete                                 
//     3                  *. ->*                                            ->
//     4                  * / %                                             ->
//     5                  + -                                               ->
//     6                  << >>                                             ->
//     7                  < <= > >=                                         ->
//     8                  == !=                                             ->
//     9                  &                                                 ->
//    10                  ^                                                 ->
//    11                  |                                                 ->
//    12                  &&                                                ->
//    13                  ||                                                ->
//    14                  ?:                                                <-
//    15                  = *= /= %= += -= &= ^= |= <<= >>=                 <-
//    16                  ,                                                 ->

// forma postfixata si prefixata
using namespace std;
int main()
{
    int x=0;
    int y = 1;
    int z = 2;
    int k = 3;
    int* w = &y;
    int& r4 = x;
    
    //       x = ++y + z++ + +k;
    //lvalue = rvalue
    k  =  y < 7 + z >10 & 9 * *w ? sizeof(w) : sizeof(r4);

    const std::type_info &ti = typeid(r4);
    cout << "tipul este =" << ti.name()<<endl;
    char c1;
    const char c2 = 'p';

    const char* p1;             //pointer la o constanta caracter
    char* const p2 = &c1;       //pointer constant catre o caracter
    const char *const p3=&c2;   //pointer constant la o constanta caracter
    const char& r1 = c1;        //referinta la o constanta carater
    char& const r2 = c1;        //referinta constanta catre un caracter
    const char& const r3 = c2;  //referinta constanta catre o constanta caracter
    // Care este diferenta intre un pointer la o constanta si o constanta pointer ?

    if (x == 0)
    {
        y = 1;
        k = 3;
    }
    else
    {
        y = 2;
    }

    y = x == 0 ? k = 3, 1 : 2;
    int i, j;
    for (i = 0, j = 0; i < 10; i++, j++)
    {

    }
    cout << "x="<<x <<"y=" << y;
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
