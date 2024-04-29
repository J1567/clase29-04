#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

/*---PROTOTIPADO---*/
int cargaAlumnos (stAlumno arreglo[],int dimencion);
void muestraAlumnado (stAlumno arreglo[],int validos);
void muestraXmatricula (stAlumno arreglo[],int validos,int matricula);
void muestraGeneroDeter(stAlumno arreglo[],int validos,char genero);
int contadorAlumnosGendet (stAlumno arreglo[],int validos,int genero);

int main()
{
stAlumno arreglo[30];

int validos = cargaAlumnos(arreglo,30);
system ("pause");
system ("cls");
muestraAlumnado(arreglo,validos);

int matriculados;
printf("ingrese el numero de matricula del alumno a ubicar: \n");
fflush(stdin);
scanf("%i",&matriculados);
muestraXmatricula(arreglo,validos,matriculados);
char genero;
printf("\ningrese el genero de los alumnos a ubicar: (mujer = f o varon = m) \n");
fflush(stdin);
scanf("%c",&genero);
muestraGeneroDeter(arreglo,validos,genero);
int alumnosGenDeter = contadorAlumnosGendet (arreglo,validos,genero);
printf ("\nla cantidad de alumnos del genero seleccionado %c es de: %i\n",genero,alumnosGenDeter);

    return 0;
}
int cargaAlumnos (stAlumno arreglo[],int dimencion)
{
    int i =0;

    char seguir ='s';
    while (seguir == 's' && i<dimencion)
    {
        printf("ingrese el nombre del alumno: \n");
        fflush(stdin);
        gets(arreglo[i].nombre);

        printf("ingrese el genero del alumno (M O F)\n");
        fflush(stdin);
        scanf("%c",&arreglo[i].genero);

        printf("ingrese el numero de matricula del alumno: \n");
        fflush(stdin);
        scanf("%i",&arreglo[i].matricula);

        i++;
        printf("desea continuar (S/N) \n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    return i;
}

void muestraAlumnado (stAlumno arreglo[],int validos)
{
    for (int i=0;i<validos;i++)
    {
        printf("%i | %s | %c\n",arreglo[i].matricula,arreglo[i].nombre,arreglo[i].genero);
    }
}
void muestraXmatricula (stAlumno arreglo[],int validos,int matricula)
{
for (int i=0;i<validos;i++)
{
    if (arreglo[i].matricula == matricula)
    {
        printf (" %i | %s | %c",arreglo[i].matricula,arreglo[i].nombre,arreglo[i].genero);
    }
}
}

void muestraGeneroDeter(stAlumno arreglo[],int validos,char genero)
{
    for (int i=0;i<validos;i++)
    {
        if (arreglo[i].genero == genero)
        {
            printf("%i | %s | %c\n",arreglo[i].matricula,arreglo[i].nombre,arreglo[i].genero);
        }
    }
}

int contadorAlumnosGendet (stAlumno arreglo[],int validos,int genero)
{
    int cont=0;
    for(int i=0;i<validos;i++)
    {
        if (arreglo[i].genero == genero)
        {
            cont++;
        }
    }
    return cont;
}


