// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

private:
	ETipOperatie Tip_Operatie;

public:
	Calculator() : Tip_Operatie(operatieAdunare) { ; }; /* Default operation : adunare */

	void SetOperatie(ETipOperatie tip) { Tip_Operatie = tip; };
	ETipOperatie GetOperatie(void) { return Tip_Operatie; };

	MyNumberType Adunare(MyNumberType a, MyNumberType b);
	MyNumberType Adunare(MyNumberType a, MyNumberType b, MyNumberType c);
	MyNumberType Scadere(MyNumberType a, MyNumberType b);
	MyNumberType Inmultire(MyNumberType a, MyNumberType b);
	MyNumberType Impartire(MyNumberType a, MyNumberType b);
	ETipOperatie DeterminaOperatie(char* buffer);
};

MyNumberType Calculator::Adunare(MyNumberType a, MyNumberType b)
{
	return (a + b);
}

MyNumberType Calculator::Adunare(MyNumberType a, MyNumberType b, MyNumberType c)
{
	return (a + b + c);
}

MyNumberType Calculator::Scadere(MyNumberType a, MyNumberType b)
{
	return (a - b);
}

MyNumberType Calculator::Inmultire(MyNumberType a, MyNumberType b)
{
	return (a * b);
}

MyNumberType Calculator::Impartire(MyNumberType a, MyNumberType b)
{
	return (a / b);
}

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


int main()
{
	FILE* fpIn;
	FILE* fpOut;

	char buffer[NMAX];
	char *pbuf = NULL;
	Calculator Calculator;
	MyNumberType a;
	MyNumberType b;
	MyNumberType rezultat;
	//ETipOperatie tipOperatie;

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
			a = 0;
			b = 0;
			pbuf = fgets(buffer, NMAX, fpIn);
			sscanf(buffer, "%lg %lg", &a, &b);


			Calculator.SetOperatie(Calculator.DeterminaOperatie(buffer));
			switch (Calculator.GetOperatie())
			{
			case operatieAdunare:
				rezultat = Calculator.Adunare(a, b);
				//rezultat = Calculator.Adunare(a, b, 45.0);
				break;
			case operatieScadere: rezultat = Calculator.Scadere(a, b);
				break;
			case operatieInmultire: rezultat = Calculator.Inmultire(a, b);
				break;
			case operatieImpartire: rezultat = Calculator.Impartire(a, b);
				break;
			default:;
			}

			fprintf(fpOut, "%1.75e\n", rezultat);
			printf("rezultat %lg \n ", rezultat);

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
