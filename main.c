#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
float aplicarDescuento(float precio);

int contarCaracteres(char cadena[], int tam, char caracter);

typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    int precio;

}eNotebook;

int ordenarNotebookPorMarca(eNotebook vec[], int tam);
int main()
{
    /*float precioInicial=100;
    float precioConDescuento;

    precioConDescuento=aplicarDescuento(precioInicial);

    printf("El precio con el descuento del 5porciento es %2f", precioConDescuento);*/

    /*int cant;
    char cadena[10]="alpaca";
    char caracter='a';

    cant=contarCaracteres(cadena, 10, caracter);


    printf("%d", cant);*/

    eNotebook note[5] = {{1000, "AMD", "ASUS", 10000},
                        {1001, "INTEL", "DELL", 20000},
                        {1002, "AMD", "EACRO", 15000},
                        {1003, "INTEL", "CAM", 11000},
                        {1004, "AMD", "BP", 12000}};
    for(int i=0; i<5; i++)
    {
        printf("%d%20s%20s    %d\n", note[i].id, note[i].procesador, note[i].marca, note[i].precio);
    }


    ordenarNotebookPorMarca(note, 5);
    printf("\n\n");
    for(int i=0; i<5; i++)
    {
        printf("%d%20s%20s    %d\n", note[i].id, note[i].procesador, note[i].marca, note[i].precio);
    }



    return 0;
}



float aplicarDescuento(float precio)
{
    float descuento;
    float precioFinal;

    descuento=(precio*5)/100;
    precioFinal=precio-descuento;
    return precioFinal;
}

int contarCaracteres(char cadena[], int tam, char caracter)
{
    int cant=0;
    if(cadena!=NULL && isalpha(caracter) && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(cadena[i]==caracter)
            {
                cant++;
            }
        }
    }
    return cant;
}
int ordenarNotebookPorMarca(eNotebook vec[], int tam)
{
    int retorno=0;
    eNotebook auxNote;

    if(vec!=NULL && tam>0)
    {

        for(int i=0; i<tam-1;i++)
        {
            for(int j=i+1;j<tam;j++)
            {
                                  //Z a A strcmp(vec[i].nombre, vec[j].nombre
                if(strcmp(vec[i].marca, vec[j].marca)>0)
                {

                  auxNote=vec[i];
                  vec[i]=vec[j];
                  vec[j]=auxNote;

                }
            }
        }
        retorno=1;
    }

    return retorno;
}
