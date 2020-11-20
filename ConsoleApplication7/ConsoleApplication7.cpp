// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class TMyObject {
    float myval;
public:
    TMyObject(float lval) :myval{ myval } {};
   // bool operator<(TMyObject& myref) { return true; };
    bool operator>(const TMyObject &myref) { return false; };
};

template <typename T>
class maimic {
    const T val;
public:
    maimic(const T& v) :val(v) { ; };
    bool operator()(const T& x)const{ return (x < val); };
};

template <typename T>
class maimare {
    const T val;
public:
    maimare(const T& v) :val(v) { ; };
    bool operator()(const T& x)const{ return (x > val); };
};

int main()
{
    /*min <val<max*/
    maimic<TMyObject> limitaMax{12};
    maimare<TMyObject> limitaMin{10};
    std::cout << "numar=";
    float numar;
    std::cin >> numar;
    bool b1 = limitaMin(numar);
    bool b2 = limitaMax(numar);
    std::cout << ((b1)&&(b2));
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
