#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 20

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
    int isEmpty;


}eNotebook;


int contarCaracteres(char str[],char x);
float aplicarDescuento(float precio);
int ordenarNotebooks(eNotebook lista[], int tam);
int hardcodearNotebooks(eNotebook lista[], int tam, int cant, int* pId);
void mostrarNotebook(eNotebook notebook);
int mostrarNotebooks(eNotebook* lista, int tam);
int inicializarNotebooks(eNotebook lista[], int tam);

int main()
{
    float precio=100;
    char cadena[20]= "Anana";
    char caracter;
    int nextId=2000;

    eNotebook lista[TAM];


    inicializarNotebooks(lista,TAM);
    hardcodearNotebooks(lista,TAM,5,&nextId);

    printf("precio sin descuento: %.2f\n",precio);
    printf("precio con descuento: %.2f\n",aplicarDescuento(precio));


    printf("Ingrese el caracter a buscar en la cadena: ");
    scanf("%c",&caracter);

    printf("El caracter %c aparece un total de %d veces en la cadena.",caracter,contarCaracteres(cadena,caracter));



    ordenarNotebooks(lista,TAM);
    mostrarNotebooks(lista,TAM);






    return 0;
}





float aplicarDescuento(float precio)
{
    float descuento;
    float precioDescontado;

    descuento= (float) 5*precio/100;

    precioDescontado= (float) precio-descuento;

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

int ordenarNotebooks(eNotebook lista[], int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(strcmp(lista[i].marca,lista[j].marca)>0 ||
                        (strcmp(lista[i].marca,lista[j].marca)==0 &&
                         (lista[i].precio<lista[j].precio)))
                {
                    auxNotebook = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNotebook;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearNotebooks(eNotebook lista[], int tam, int cant, int* pId)
{
	int contador = -1;

	char marcas[10][20] = {
		"Toyota",
		"Fiat",
		"Siena",
		"Ferrari",
		"Ferrari",
		"Ferrari",
		"Lamote",
		"Lambda",
		"Alfa",
		"Omega"
};

char procesador[10][20] = {
		"I9",
		"Reddragon",
		"banana",
		"intel",
		"nvidia",
		"motorjhead",
		"Lamote",
		"Lambda",
		"Alfa",
		"Omega"
};



float precios[10] = {262, 275, 275, 262, 291, 297, 298, 202, 263, 205};


	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].marca, marcas[i]);
			strcpy(lista[i].procesador, procesador[i]);
			lista[i].precio=precios[i];

			lista[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}

void mostrarNotebook(eNotebook notebook)
{

printf("---------------------------------------------\n");
    printf("  %d   %s      %s      %.2f\n",
           notebook.id,
           notebook.marca,
           notebook.procesador,
           notebook.precio);
}


int mostrarNotebooks(eNotebook* lista, int tam)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tam > 0)
    {
        printf("\n\n\n");
        printf("       *** Listado de Notebooks ***      \n");
        printf("   Id   Marca    Procesador   Precio\n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarNotebook(lista[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("   No hay notebooks para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarNotebooks(eNotebook lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


