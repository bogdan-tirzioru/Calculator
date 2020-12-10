// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#if 0

#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

#define NMAX 200

typedef long double MyNumberType;

typedef enum {
	operatieAdunare = 1,
	operatieScadere = 2,
	operatieInmultire = 3,
	operatieImpartire = 4,
	operatieEroare = 5,
}ETipOperatie;

class Calculator {

public:

	ETipOperatie DeterminaOperatie(char* buffer);
};


ETipOperatie Calculator::DeterminaOperatie(char* buffer)
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

class Float
{
private:
	MyNumberType Numar;

public:
	Float() :Numar(0.0f) { ; } // constructor
	Float(Float& i1) { Numar = i1.Numar; } // 
	Float(MyNumberType i) : Numar(i) { ; } // 
	MyNumberType Get_Numar(void) { return Numar; } // getter
	~Float() { ; };

	// Overload operatii

	Float operator+(const Float& temp)
	{
		Float in;
		in.Numar = Numar + temp.Numar;
		return in;
	}

	Float operator-(const Float& temp)
	{
		Float in;
		in.Numar = Numar - temp.Numar;
		return in;
	}

	Float operator*(const Float& temp)
	{
		Float in;
		in.Numar = Numar * temp.Numar;
		return in;
	}

	Float operator/(const Float& temp)
	{
		Float in;
		if (temp.Numar != 0)
		{
			in.Numar = Numar / temp.Numar;
		}
		else
		{
			cout << "Not Possible" << endl;
		}
		return in;
	}
};


int main()
{
	FILE* fpIn;
	FILE* fpOut;

	char buffer[NMAX];
	char *pbuf = NULL;
	
	char Math_Sign[4] = { '+', '-' , '*', '/' };

	Float numar;
	Float numar2;
	Float rezultat_overloaded;

	Calculator Calculator;

	ETipOperatie tipOperatie;

	char numefIn[80] = "calc.in";
	char numefOut[80] = "calc.out";

	printf("Open files\n");

	fpIn = fopen(numefIn, "r");
	fpOut = fopen(numefOut, "w");

	printf("Procesinf file %s \n", numefIn);

	if ((fpIn != NULL) && (fpOut != NULL))
	{
		do
		{
			/* If a specific math sign wasn't found, then 0 as default */
			unsigned int Sign_Position_Found = 0;

			/* Read line by line from calc.in file */
			pbuf = fgets(buffer, NMAX, fpIn);

			/* Convert buffer ( line read ) to string to find the sign */
			string LinefromFile(buffer);

			for (unsigned char i = 0; i < 4; i++)
			{
				/* Search for a specific math sign, if not found, then calculation is not possible */
				Sign_Position_Found = LinefromFile.find(Math_Sign[i]);

				/* If found, break for loop to do not waste time here */
				if (Sign_Position_Found != std::string::npos)
				{
					break;
				}
			}

			/* Based on sign position in string, then split in two elements */
			string First_Element = LinefromFile.substr(0, Sign_Position_Found);
			string Second_Element = LinefromFile.substr(Sign_Position_Found + 1);

			/* Convert from string to float */
			numar = atof(First_Element.c_str());
			numar2 = atof(Second_Element.c_str());

			tipOperatie = Calculator.DeterminaOperatie(buffer);

			if (tipOperatie == operatieEroare)
			{
				fprintf(fpOut, "%s\n", "Eroare!");
				continue;
			}

			switch (tipOperatie)
			{
			case operatieAdunare:
				rezultat_overloaded = numar + numar2;
				break;
			case operatieScadere:
				rezultat_overloaded = numar - numar2;
				break;
			case operatieInmultire:
				rezultat_overloaded = numar * numar2;
				break;
			case operatieImpartire:
				rezultat_overloaded = numar / numar2;
				break;
			default:;
			}

			fprintf(fpOut, "%lf\n", rezultat_overloaded);

		} while (!feof(fpIn));
	}
	else
	{
		printf("error opening file");
		if (fpIn == NULL) printf(" %s\n", numefIn);
		if (fpOut == NULL) printf(" %s\n", numefOut);
	}
	if (fpIn != NULL) fclose(fpIn);
	if (fpOut != NULL) fclose(fpOut);
	printf("Done.");

}
#endif