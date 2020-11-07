//
// Created by arman on 6/11/2020.
//
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

};