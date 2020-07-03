// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //1)impliciti conversion
    unsigned int  myvar = 10;
    signed int myvar1 = myvar;

    //2)explicit conversion
    unsigned int myvar2 = 20;
    long myvar3 = (long)myvar2;
    unsigned char ci = (unsigned char)myvar3;

    //3)static_cast for reversing a well - defined implicit conversion
    int ui_j=10;
    double dj = static_cast <double>(ui_j); //conversion of smaller int to larger int
    std::cout << "dj=" << dj << "\n";
    int ui_k=42;
    char uk = static_cast<long>(ui_k);
    std::cout << "uk=" << uk << "\n"; //or larger to small type

    //4)const_cast removes constness from referince and pointers
    const char *pcs = "Ceva text";
    //pcs[0] = '-';
    char *pcmy = const_cast<char*>(pcs); //remove the const qualifier for pointers
   // pcmy[0]= 'O';
    std::cout << pcs << std::endl;

    int ii = 10;
    const int* pi = &ii;


    /*cpp reference*/
    int i = 3;                 // i is not declared const
    const int& rci = i;
    const_cast<int&>(rci) = 4; // OK: modifies i
    const_cast<int&>(i) = 4;

    //5) reinterpret_cast for changing the meaning of bit patterns
    typedef struct MyIO { int id; }IO_device;
    IO_device* d1 = reinterpret_cast<IO_device*>(0Xff00); // device at 0Xff00
    
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
