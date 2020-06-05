#pragma once
typedef int TData;
typedef double TDataF;
/*abstractizare*/
class NumarNatural
{
	/*incapsulare*/
private:
	TData data;
public:
	NumarNatural() :data(0) { ; };
	NumarNatural(TData a) { data = a; };
	void SetData(TData a) { data = a; };
	TData GetData(void) { return data; };
	/*polimorfism*/
	NumarNatural Adunare(NumarNatural a, NumarNatural b,int ai=0)
	{
		NumarNatural temp;
		temp.SetData(a.GetData() + b.GetData());
		return temp;
	};

	NumarNatural Adunare(TData a, TData b)
	{
		NumarNatural temp;
		temp.SetData(a + b);
		return temp;
	}
	NumarNatural * Adunare(TData const * a, TData const * b,int ai=0)
	{
		
		NumarNatural rez;
		return &rez;
	}
	virtual ~NumarNatural(void)
	{
		data = 0;
	}
};
/*Mostenire*/
class NumarReal :NumarNatural
{
private:
	TDataF dataf;
public:
	NumarReal() :dataf() {
		; };
	NumarReal(TDataF a) { dataf = a; };
	void SetData(TDataF a) { dataf = a; };
	TDataF GetData(void) { return dataf; };
	NumarReal Adunare(NumarReal a, NumarReal b)
	{
		NumarReal temp;
		temp.SetData(a.GetData() + b.GetData());
		return temp;
	}
};

