// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

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

class Intreg 
{
	private:
		MyNumberType Numar;
		
	public:
		Intreg() :Numar(0.0f) { ; }
		Intreg(Intreg& i1) { Numar = i1.Numar; }
		Intreg(MyNumberType i) : Numar(i) { ; }
		MyNumberType Get_Numar(void) { return Numar; }
		~Intreg() { ; };


		Intreg operator+(const Intreg& temp)
		{
			Intreg in;
			in.Numar = Numar + temp.Numar;
			return in;
		}

		Intreg operator-(const Intreg& temp)
		{
			Intreg in;
			in.Numar = Numar - temp.Numar;
			return in;
		}

		Intreg operator*(const Intreg& temp)
		{
			Intreg in;
			in.Numar = Numar * temp.Numar;
			return in;
		}

		Intreg operator/(const Intreg& temp)
		{
			Intreg in;
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
	char math_sign;

	Intreg numar;
	Intreg numar2;
	Intreg rezultat_overloaded;
	
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

			pbuf = fgets(buffer, NMAX, fpIn);
			sscanf(buffer, "%Lf %c %Lf", &numar, &math_sign, &numar2);

			tipOperatie = Calculator.DeterminaOperatie(buffer);

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

			//fprintf(fpOut, "%1.75e\n", rezultat_overloaded);
			fprintf(fpOut, "%lf\n", rezultat_overloaded);
			printf("rezultat %lf \n ", rezultat_overloaded);

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
