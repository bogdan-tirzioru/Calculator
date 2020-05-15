// CalculatorCversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#define NMAX 200
typedef enum {
    operatieAdunare = 1,
    operatieScadere = 2,
    operatieInmultire = 3,
    operatieImpartire = 4,
    operatieEroare = 5,
}ETipOperatie;

typedef double MyNumberType;

MyNumberType Adunare(MyNumberType a, MyNumberType b)
{
    return (a + b);
}

MyNumberType Scadere(MyNumberType a, MyNumberType b)
{
    return (a - b);
}

MyNumberType Inmultire(MyNumberType a, MyNumberType b)
{
    return (a * b);
}

MyNumberType Impartire(MyNumberType a, MyNumberType b)
{
    return (a / b);
}

ETipOperatie DeterminaOperatie(char* buffer)
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
    MyNumberType a;
    MyNumberType b;
    MyNumberType rezultat;
    char numefIn[80] = "calc.in";
    char numefOut[80] = "calc.out";
    ETipOperatie tipOperatie;
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
            sscanf(buffer, "%g %g", &a, &b);
            tipOperatie = DeterminaOperatie(buffer);
            switch (tipOperatie)
            {
                case operatieAdunare: rezultat = Adunare(a, b);
                    break;
                case operatieScadere: rezultat = Scadere(a, b);
                    break;
                case operatieInmultire: rezultat = Inmultire(a, b);
                    break;
                case operatieImpartire: rezultat = Impartire(a, b);
                    break;
                default:;
            }

            fprintf(fpOut, "%1.75e\n", rezultat);

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
