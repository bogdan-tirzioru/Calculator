// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
class MyException {
    int eroare;
public:
    MyException(int err) :eroare{ err } { ; };
};

class MyExceptionText
{
    std::string sTipExc;
public:
    MyExceptionText(std::string lsTipException) : sTipExc{ lsTipException }{ ; };
};


int main()
{
    int number = 0;
    std::cout << "number= ";
    try
    {
        std::cin >> number;
        if (number < 0) throw MyException{-1};
        std::cout << "Ajunge aici?"<<std::endl;
        if (number > 10) throw MyExceptionText{ "Index mai mare decat trebuie" };
        std::cout << "Dar aici?" << std::endl;
    }
    catch (MyException)
    {
        std::cout << "negativ invalid range" << std::endl;
    }
    catch (MyExceptionText)
    {
        std::cout << "pozitiv invalid range" << std::endl;
    }
    std::cout << "Sfarsitul programului" << std::endl;
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
