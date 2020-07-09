#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <cstdio>

typedef double tip; 

class calcule
{
	tip a;
	tip b;
public:
	tip rezultat;
	tip suma(tip a, tip b)
	{
		return a + b;
	}
	tip diferenta(tip a, tip b)
	{
		return a - b;
	}
	tip inmultire(tip a, tip b)
	{
		return a * b;
	}
	tip impartire(tip a, tip b)
	{
		return a / b;
	}
};

class Intreg 
{
private:
	int NumarIntreg;
public:
	Intreg() :NumarIntreg(0) { ; }
	Intreg(Intreg& i1) { NumarIntreg = i1.NumarIntreg; }
	Intreg(int i) :NumarIntreg(i) { ; }
	
	int GetNr(void){return NumarIntreg;}
	~Intreg() { ; } //destructor

	Intreg operator+(const Intreg& temp)
	{
		Intreg in;
		in.NumarIntreg = NumarIntreg + temp.NumarIntreg;
		return in;
	}

	Intreg operator-(const Intreg& temp)
	{
		Intreg in;
		in.NumarIntreg = NumarIntreg - temp.NumarIntreg;
		return in;
	}

	Intreg operator/(const Intreg& temp)
	{
		Intreg in;
		in.NumarIntreg = NumarIntreg / temp.NumarIntreg;
		return in;
	}

	Intreg operator*(const Intreg& temp)
	{
		Intreg in;
		in.NumarIntreg = NumarIntreg * temp.NumarIntreg;
		return in;
	}
};



