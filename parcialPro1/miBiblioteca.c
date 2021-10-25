#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include <string.h>

int aplicarDescuento(int precio)
{
    int descuento;
    int precioDescontado;

    descuento= 5*precio/100;

    precioDescontado=precio-descuento;

    return precioDescontado;




}

int contarCaracteres(char str[],char x)
{
    int contador=0;
    int tam;

    tam=strlen(str);



    for(int i=0;i<tam;i++)
    {

        if(str[i]==toupper(x)||str[i]==tolower(x))
        {
            contador++;
        }



    }

    return contador;

}
