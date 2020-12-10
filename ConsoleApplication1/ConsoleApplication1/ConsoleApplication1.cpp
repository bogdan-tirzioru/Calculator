
#include <string.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define NMAX 200

//typedef long double MyNumberType;

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

template <class MyNumberType>
class Calculate
{
private:
	MyNumberType Numar;

public:
	Calculate() : Numar(0) { } // constructor
	Calculate(Calculate& i1) { Numar = i1.Numar; } 
	Calculate(MyNumberType i) : Numar(i) { }  
	
	MyNumberType Get_Numar(void) { return Numar; } // getter

	virtual ~Calculate() { } //destructor

	void Set_Numar(MyNumberType s) { Numar = s; }

	// Overload operatii

	Calculate operator+(const Calculate& temp)
	{
		Calculate in;
		in.Numar = Numar + temp.Numar;
		return in;
	}

	Calculate operator-(const Calculate& temp)
	{
		Calculate in;
		in.Numar = Numar - temp.Numar;
		return in;
	}

	Calculate operator*(const Calculate& temp)
	{
		Calculate in;
		in.Numar = Numar * temp.Numar;
		return in;
	}

	Calculate operator/(const Calculate& temp)
	{
		Calculate in;
		if (temp.Numar != 0)
		{
			in.Numar = (Numar / temp.Numar);
		}
		else
		{
			cout << "Not Possible" << endl;
		}
		return in;
	}

	friend fstream& operator << (fstream& output, Calculate& temp)
	{
		output << temp.Get_Numar();
		return output;
	}

};

int main()
{
	//FILE* fpIn;
	//FILE* fpOut;

	char numefIn[80] = "calc.in";
	char numefOut[80] = "calc.out";
	char buffer[NMAX];

	ifstream fpIn(numefIn, ifstream::in);
	fstream fpOut(numefOut, fstream::out); /* Default mode doesn't delete the output file to be clear for writing data*/

	fpOut.setf(ios_base::fixed); /* write floating point values in fixed-point notation */

	//char *pbuf = NULL;
	
	//char math_sign;
	
	char Math_Sign[4] = { '+', '-' , '*', '/' };

	Calculate <long double> numar;
	Calculate <long double> numar2;
	Calculate <long double> rezultat_overloaded;

	
	//numar.Set_Numar(43);

	Calculator Calculator;
	ETipOperatie tipOperatie;

	//fpIn = fopen(numefIn, "r");
	//fpOut = fopen(numefOut, "w");

	//printf("Procesinf file %s \n", numefIn);

	if ((fpIn) && (fpOut))
	{
		cout << "File opened !" << endl;
		do
		{
			/* If a specific math sign wasn't found, then 0 as default */
			unsigned int Sign_Position_Found = 0;

			/* Read line by line from calc.in file */
			//pbuf = fgets(buffer, NMAX, fpIn);
			//fpIn >> buffer; 
			fpIn.getline(buffer, NMAX);

			/* Convert buffer (line read) to string to find the sign */
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

			/* Convert from string to nr */
			numar.Set_Numar(atof(First_Element.c_str()));
			numar2.Set_Numar(atof(Second_Element.c_str()));
			
			//sscanf(buffer, "%Lf %c %Lf", &numar, &math_sign, &numar2);
			
			tipOperatie = Calculator.DeterminaOperatie(buffer);

			switch (tipOperatie)
			{
			case operatieAdunare:
				rezultat_overloaded = numar + numar2;
				fpOut << rezultat_overloaded << endl;
				break;
			case operatieScadere:
				rezultat_overloaded = numar - numar2;
				fpOut << rezultat_overloaded << endl;
				break;
			case operatieInmultire:
				rezultat_overloaded = numar * numar2;
				fpOut << rezultat_overloaded << endl;
				break;
			case operatieImpartire:
				rezultat_overloaded = numar / numar2;
				fpOut << rezultat_overloaded << endl;
				break;
			default:;
			}
			//fprintf(fpOut, "%lf\n", rezultat_overloaded);
			
		} while (!fpIn.eof());
	}
	else
	{
		cout<<"error opening file"<<endl;
		if (!fpIn) { cout << numefIn; }
		if (!fpOut) { cout << numefOut; }

		//if (fpIn == NULL) printf(" %s\n", numefIn);
		//if (fpOut == NULL) printf(" %s\n", numefOut);
	}

	if (fpIn)
	{
		fpIn.close();
	}

	if (fpOut)
	{
		fpOut.close();
	}

	//if (fpIn != NULL) fclose(fpIn);
	//if (fpOut != NULL) fclose(fpOut);

	cout << "Done." << endl;
	//printf("Done.");


}
