#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "Mi_libreria.h"

bool SalirMenu = false;
int SelectMenu = 0;
struct Asignatura
{
    int codigo_asig;
    char *descripcion;
    int creditos;
    float p1;
    float p2;
    float p3;
    float p4;

};

struct Estudiantes
{
    int matricula;
    char *nombre;
    char *apellido;
    char carrera[5];
    int CantAsig;
    struct Asignatura asig[10];

};

struct Estudiantes Estudiante[2] = {
{22, "Armando", "Noel", "ISC", 2, {{1, "Conexion con el Cliente", 3, 50,50,75,55}, {7, "Estrategia de Mercado", 3, 89,70,75,88}}}
, {22, "Carlos", "Camacho", "ISC", 2, {{5, "Anatomia", 3, 89,70,75,65}, {45, "Neurocirugia", 3, 55,70,75,88}}}
};

//PARAMETRIZACION DE FUNCIONES
int imprimir_menu();
void ImprimirAprobados();

//FUNCIONES
int imprimir_menu()
{
    system("CLS");
    printf("\n\n***MENU***");
    char menu[][100]={"1- Ingrese Estudiante ", "2- Reportar los Aprobados ", "3- Salir "};
    int longitud_arreglo = sizeof(menu) / sizeof(menu[0]);
    for (int i=0; i<longitud_arreglo; i++)
    {
        printf("\n %s",menu[i]);
    }
    printf("\n\n----> ");
    scanf("%d",&SelectMenu);

    return SelectMenu;
};

void ImprimirAprobados()
{
system("CLS");
int longitud = sizeof(Estudiante) / sizeof(Estudiante[0]);
int j;
float notas, promedio;
bool aprobado = false;


for (int i = 0; i  < 2; i++)
{
printf("\n\n Estudiante: %s %s", Estudiante[i].nombre, Estudiante[i].apellido);
j = 0;

while (Estudiante[i].asig[j].codigo_asig > 0)
{
    notas =   Estudiante[i].asig[j].p1 + Estudiante[i].asig[j].p2 + Estudiante[i].asig[j].p3 + Estudiante[i].asig[j].p4;
    promedio = notas / 4 ;
    printf("\n\t Asignatura : %d - %s [ %f ]",Estudiante[i].asig[j].codigo_asig, Estudiante[i].asig[j].descripcion , promedio   );
    if (promedio > 60)
    {
        printf("\t APROBADA ");
    }
    j++;
    if (promedio < 60)
    {
        printf("\t REPROBADA ");
    };
}

}
printf("\n\n ");

}

int  main()
{

do{
        switch(imprimir_menu())
        {
            case 1:
                //capturar_archivo();
                //Imprimir Archivo Capturado
                //Leer_Archivo(nombre);
                break;
            case 2:
                ImprimirAprobados();
                system("PAUSE");
                break;
            case 3:
                SalirMenu = true;
                break;
            default :
                printf("Funci%cn elegida no es v%clida",162,160);
                break;
        }

    }while(!SalirMenu);



return 0;
};
