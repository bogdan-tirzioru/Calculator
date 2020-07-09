#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <cstdio>

#include "Header.h"


using namespace std;

#define lungime 200

typedef enum {
	opadunare = 1,
	opscadere = 2,
	opinmultire = 3,
	opimpartire = 4,
	eroare = 5,
}op;

op opp(char* buffer)
{
	char* ret = NULL;
	ret = strchr(buffer, '+');
	if (ret != NULL) return opadunare;
	else
	{
		ret = strchr(buffer, '-');
		if (ret != NULL) return opscadere;
		{
			ret = strchr(buffer, '*');
			if (ret != NULL) return opinmultire;
			else
			{
				ret = strchr(buffer, '/');
				if (ret != NULL) return opimpartire;
				else
				{
					return eroare;
				}
			}
		}
	}

}
int main()
{
	char buffer[lungime];
	
	op tipop;
	ifstream in("calc.in");
	fstream out("calc.out");
	tip c;
	tip d;
	calcule rez;
	
	if (!in & !out)
	{
		cout << "Eroare la deschiderea fisierului";
	}
	else
	{
		
		do
		{
			c = 0;
			d = 0;
			in >> buffer;
			cout << "\n Buffer = " << buffer;
			sscanf(buffer, "%lg %lg", &c, &d);
			tipop = opp(buffer);
			cout << "\n op = " << tipop;

			switch (tipop)
			{
			case opadunare: out << "\n" <<rez.suma(c,d);
				break;
			case opscadere: out << "\n" <<rez.diferenta(c, d);
				break;
			case opinmultire: out << "\n" <<rez.inmultire(c, d);
				break;
			case opimpartire: out << "\n" <<rez.impartire(c, d);
				break;
			default:
				break;
			}
		
		} while (!in.eof());

	}
	
	if (in) { in.close(); }
	if (out) { out.close(); }


	/* */

	Intreg NumarIntreg1 = 10;
	Intreg NumarIntreg2 = 2;
	Intreg rezultat;

	rezultat = NumarIntreg1 + NumarIntreg2;
	cout <<"\n Adunare:"<< rezultat.GetNr()<<endl;

	rezultat = NumarIntreg1 - NumarIntreg2;
	cout << "\n Scadere:" << rezultat.GetNr() << endl;

	rezultat = NumarIntreg1 * NumarIntreg2;
	cout << "\n Inmultire:" << rezultat.GetNr() << endl;

	rezultat = NumarIntreg1 / NumarIntreg2;
	cout << "\n Impartire:" << rezultat.GetNr() << endl;
}
	