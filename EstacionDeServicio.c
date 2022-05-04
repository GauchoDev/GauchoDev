#include <stdio.h>
#include <ctype.h>
char cOption = 'Y';
int flag = 1;
int iPlayeroOptions = 0;

float iPlayero1 = 0;
float iPlayero2 = 0;
float iPlayero3 = 0;
float iPlayero4 = 0;
float iPlayero5 = 0;
double iArrayPlayeros[5];
const float Np$ = 60.35;
const float Nc$ = 53.28;
const float Gp$ = 58.32;
const float Gc$ = 42.56;
int iSurtidor = 0;
int iFuelType = 0;
float fLitros = 0;
float fFuel$ = 0;
float Np1 = 0;
float Nc2 = 0;
float Gp3 = 0;
float Gc4 = 0;
float fNpTotal$ = 0;
float fNcTotal$ = 0;
float fGpTotal$ = 0;
float fGcTotal$ = 0;

float i2Darray[7][4];

int venta()
{
    /*Por cada venta deberá solicitar : Nro de playero, Tipo de combustible
    y cantidad(litros) vendida.f.De ingresarse un playero o el tipo de
    combustible inválidos deberá informar al operador y solicitar valores
    correctos.g.La venta en Litros No podrá ser 0(cero).*/
    while (cOption != 'N')
    {
        printf("\n\n");
        printf("Ingrese surtidor (1)(2)(3)(4)(5)(6)(7):\t");
        scanf("%d", &iSurtidor);
        printf("\n\n");
        while (flag == 1)
        {
            printf("Ingrese Nro de playero (1)(2)(3)(4)(5):\t");
            scanf("%d", &iPlayeroOptions);
            printf("\n\n");
            printf("Ingrese Tipo de combustible Nafta Premium:(1)  Nafta común:(2)\n");
            printf("Ingrese Tipo de combustible GasOil Premium:(3) GasOil común  (4)\t");
            scanf("%d", &iFuelType);

            printf("\n\n");
            if (iPlayeroOptions == 1 || iPlayeroOptions == 2 || iPlayeroOptions == 3 || iPlayeroOptions == 4 || iPlayeroOptions == 5 || iFuelType == 1 || iFuelType == 2 || iFuelType == 3 || iFuelType == 4)
            {
                flag = 0;
                break;
            }
        }
        printf("\n\n");
        printf("Ingrese los litros:\t");
        scanf("%f", &fLitros);

        if (iFuelType == 1)
        {
            fFuel$ = Np$;
        }
        else if (iFuelType == 2)
        {
            fFuel$ = Nc$;
        }
        else if (iFuelType == 3)
        {
            fFuel$ = Gp$;
        }
        else if (iFuelType == 4)
        {
            fFuel$ = Gc$;
        }

        i2Darray[iSurtidor - 1][iFuelType - 1] = fLitros; // Assign values to 2D array

        if (iPlayeroOptions == 1)
        {
            iPlayero1 = fLitros * fFuel$;
        }
        else if (iPlayeroOptions == 2)
        {
            iPlayero2 = fLitros * fFuel$;
        }
        else if (iPlayeroOptions == 3)
        {
            iPlayero3 = fLitros * fFuel$;
        }
        else if (iPlayeroOptions == 4)
        {
            iPlayero4 = fLitros * fFuel$;
        }
        else if (iPlayeroOptions == 5)
        {
            iPlayero5 = fLitros * fFuel$;
        }
        iArrayPlayeros[0] = iPlayero1;
        iArrayPlayeros[1] = iPlayero2;
        iArrayPlayeros[2] = iPlayero3;
        iArrayPlayeros[3] = iPlayero4;
        iArrayPlayeros[4] = iPlayero5;

        printf("\n\n");
        printf("Qiere realizar otra operacion: si(S)--no(N)\t");
        scanf(" %c", &cOption);
        cOption = toupper(cOption);
        if (cOption == 'S')
        {
            flag = 1;
        }
        if (cOption == 'N')

        {

            break;
        }
    }

    return 0;
}

float cierre()
{
    printf("\t\tNp    Nc    Gp    Gc");
    printf("\n");
    for (int s = 0; s < 7; s++)
    {
        if (s == 0)
        {
            printf("Surtidor 1\t");
        }
        else if (s == 1)
        {
            printf("Surtidor 2\t");
        }
        else if (s == 2)
        {
            printf("Surtidor 3\t");
        }
        else if (s == 3)
        {
            printf("Surtidor 4\t");
        }
        else if (s == 4)
        {
            printf("Surtidor 5\t");
        }
        else if (s == 5)
        {
            printf("Surtidor 6\t");
        }
        else if (s == 6)
        {
            printf("Surtidor 7\t");
        }

        for (int c = 0; c < 4; c++)
        {

            printf("%.2f  ", i2Darray[s][c]);
            if (c == 0)
            {
                Np1 += i2Darray[s][c]; // Total Litros Nafta Premium
            }
            else if (c == 1)
            {
                Nc2 += i2Darray[s][c]; // Total Litros Nafta Comun
            }
            else if (c == 2)
            {
                Gp3 += i2Darray[s][c]; // Total Litros Gasoil Premium
            }
            else if (c == 3)
            {
                Gc4 += i2Darray[s][c]; // Total Litros Gasoil Comun
            }
        }
        printf("\n");
    }
    fNpTotal$ = Np1 * Np$; // Totales en $$ por tipo de combustible
    fNcTotal$ = Nc2 * Nc$;
    fGpTotal$ = Gp3 * Gp$;
    fGcTotal$ = Gc4 * Gc$;

    printf("\n");
    printf("          Nomenclaturas:\n");
    printf("Np: Nafta Premium,  Nc: Nafta Común\n");
    printf("Gp: GasOil Premium,	Gc: GasOil Común\n\n");
    for (int p = 0; p < 5; p++)
    {
        printf("\nPlayero %d:  $%.2f\n", p + 1, iArrayPlayeros[p]);
    }
    printf("\n\n");
    printf("Total litror vendidos de Np: %.2f\n", Np1);
    printf("Total litror vendidos de Nc: %.2f\n", Nc2);
    printf("Total litror vendidos de Gp: %.2f\n", Gp3);
    printf("Total litror vendidos de Gc: %.2f\n", Gc4);
    printf("Total litror vendidos en la estacion de servivio: %.2f\n", Np1 + Nc2 + Gp3 + Gc4);
    printf("\n\n");
    printf("Totales en $$ vendidos de Np: $%.2f\n", fNpTotal$);
    printf("Totales en $$ vendidos de Nc: $%.2f\n", fNcTotal$);
    printf("Totales en $$ vendidos de Gp: $%.2f\n", fGpTotal$);
    printf("Totales en $$ vendidos de Gc: $%.2f\n", fGcTotal$);
    printf("Totales en $$ vendidos en la estacion de servicio: $%.2f\n", fNpTotal$ + fNcTotal$ + fGpTotal$ + fGcTotal$);

    return 0;
}
int main()
{
    char cLoop = 'P';
    int flag = 1;
    char cOptionV_C = 'V';
    while (cLoop != 'X')
    {
        printf("\n\nDesea iniciar una venta (V) o hacer el cierre del día (C)\t");
        scanf(" %c", &cOptionV_C);
        cOptionV_C = toupper(cOptionV_C);
        printf("\n");
        switch (cOptionV_C)
        {
        case 'V':
            flag = 0;

            venta();
            break;
        case 'C':
            flag = 0;

            cierre();
            break;

        default:
            while (flag == 1)
            {
                printf("\nOpción incorrecta, ingrese Venta (V) o Cierre (C)\t");
                scanf(" %c", &cOptionV_C);
                cOptionV_C = toupper(cOptionV_C);
                if (cOptionV_C == 'V')
                {
                    flag = 0;

                    venta();
                    break;
                }
                else if (cOptionV_C == 'C')
                {
                    flag = 0;
                    cierre();
                    break;
                }
            }
        }
        printf("\n");

        printf("Precione (X) para salir u otra letra para seguir:\t");
        scanf(" %c", &cLoop);
        cLoop = toupper(cLoop);
        if (cLoop == 'X')
        {
            break;
        }
        printf("\n");
        printf("\n");
    }

    return 0;
}
