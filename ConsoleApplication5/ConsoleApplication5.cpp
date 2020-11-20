// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
typedef int myint;
typedef int (*TypePFunc)(int,int);
int max(int a, int b)
{
    int aux = 0;
    if (a > b) aux = a;
    else aux = b;
    return aux;
}
int min(int a, int b)
{
    int aux = 0;
    if (a < b) aux = a;
    else aux = b;
    return aux;
}
int maimare(int a, int b)
{
    if (a > b) return 1;
    else return 0;
}
int maimic(int a, int b)
{
    if (a < b) return 1;
    else return 0;
}
int parcurgere(int a[], TypePFunc pf)
{
    int aux = a[0];
    for (int i = 1; i < (sizeof(a) / sizeof(int)); i++)
    {
        if (!((*pf)(aux,a[i])))
        {
            aux = a[i];
        }
    }
    return aux;
}


int main()
{
    int a, b;
    TypePFunc pf;
    pf = max;
    std::cout << "a=";
    std::cin >> a;
    std::cout << "b=";
    std::cin >> b;
    std::cout << "max operatie="<< (*pf)(a,b);
    pf = min;
    std::cout << "min operatie=" << (*pf)(a, b);
    int v[] = { 10,24,9,-9,5 };
    std::cout << "max din serie" << parcurgere(v,maimare);
    std::cout << "min din serie" << parcurgere(v,maimic);
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
