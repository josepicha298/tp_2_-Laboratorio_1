#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#define LENEMP 100

int main()
{
    int option;
    char pedirApellido[51];
    char pedirNombre[51];
    float pedirSalario;
    int pedirId;
    int pedirSector;
    int espacioVacio;
    int procesarDeNuevo;
    int contarDeEmpleado=0;
    int validarNombre=0;
    int validarApelliodo=0;
    int validarSalario=0;
    int validarSector=0;
    Employee employees[LENEMP];
    initEmployees(employees,LENEMP);

    do
    {
        switch(mainMenu())
        {
        case 1:
            procesarDeNuevo=0;
            espacioVacio=findEmptyIndex(employees,LENEMP);
            if(espacioVacio>=0)
            {
                getRandomId(employees,LENEMP,&pedirId);
                do
                {
                    validarNombre=getString(pedirNombre,"Ingrese el nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);
                    if(validarNombre==-1)
                    {
                        procesarDeNuevo++;
                        if(procesarDeNuevo>2)
                        {
                            break;
                        }
                    }
                }
                while(validarNombre==-1);

                if(validarNombre!=-1)
                {
                    procesarDeNuevo=0;
                    do
                    {
                        validarApelliodo=getString(pedirApellido,"Ingrese el apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);
                        if(validarApelliodo==-1)
                        {
                            procesarDeNuevo++;
                            if(procesarDeNuevo>2)
                            {
                                break;
                            }
                        }
                    }
                    while(validarApelliodo==-1);
                }

                if(validarNombre!=-1 && validarApelliodo!=-1)
                {
                    procesarDeNuevo=0;
                    do
                    {
                        validarSalario=getFloat(&pedirSalario,"Ingrese el salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,1000000);
                        if(validarSalario==-1)
                        {
                            procesarDeNuevo++;
                            if(procesarDeNuevo>2)
                            {
                                break;
                            }
                        }
                    }
                    while(validarSalario==-1);
                }

                if(validarNombre!=-1 && validarApelliodo!=-1 && validarSalario!=-1)
                {
                    do
                    {
                        validarSector=getInt(&pedirSector,"Ingrese sector del empleado","Opcion invalida, rango [1-5]",1,5);
                        if(validarSector==-1)
                        {
                            procesarDeNuevo++;
                            if(procesarDeNuevo>2)
                            {
                                break;
                            }
                        }
                    }
                    while(validarSector==-1);
                }

                if((validarNombre!=-1) && (validarApelliodo!=-1) && (validarSalario!=-1) && (validarSector!=-1))
                {
                    addEmployee(employees,LENEMP,pedirId,pedirNombre,pedirApellido,pedirSalario,pedirSector);
                    contarDeEmpleado++;
                }
                else
                {
                    printf("No se pudo validar al empleado..!\n\n");
                }
            }
            else
            {

                printf("No hay espacio para mas empleados..!!\n");
            }
            system("pause");
            break;
        case 2:
            if(contarDeEmpleado>0)
            {
                modifyEmployee(employees,LENEMP);
            }
            else
            {
                printf("\nNo hay empleados cargados en el sistema!!\n\n");
            }
            system("pause");
            break;

        case 3:
            if(contarDeEmpleado>0)
            {
                removeEmployee(employees,LENEMP);
                contarDeEmpleado--;
            }
            else
            {
                printf("\nNo hay empleados cargados en el sistema!!\n\n");
            }
            system("pause");
            break;
        case 4:
            if(contarDeEmpleado>0)
            {
                reports(employees,LENEMP);
            }
            else
            {
                printf("\nNo hay empleados cargados en el sistema\n\n");
            }
            system("pause");
            break;
        }
        option=mainMenu();
    }
    while(option!=5);

    return 0;
}
