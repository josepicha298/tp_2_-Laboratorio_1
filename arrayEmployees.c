#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "arrayEmployees.h"
#define EMPTY 1
#define OCCUPIED 0


int initEmployees(Employee* employees, int lengthEmployees)
{
    for(int i=0; i<lengthEmployees; i++)
    {
        employees[i].isEmpty=EMPTY;
    }
    return 0;
}

int mainMenu()
{
    int option;
    system("cls");
    printf("\t MENU TP 2 \n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificacion empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n\n");
    printf("Ingrese option: ");
    scanf("%d",&option);
    return option;
}

int addEmployee(Employee* employees, int lengthEmployees, int id, char name[],char lastName[],float salary,int sector)
{
    int validation=0;
    int index;

    index=findEmptyIndex(employees,lengthEmployees);

    employees[index].id=id;
    strcpy(employees[index].name,name);
    strcpy(employees[index].lastName,lastName);
    employees[index].salary=salary;
    employees[index].sector=sector;
    employees[index].isEmpty=OCCUPIED;

    system("cls");
    printf("\t Alta de empleado \n\n");
    printf("%8s %12s %12s %12s %12s\n", "ID", "Sector", "Nombre", "Apellido", "Sueldo");
    printEmployee(employees[index]);

    return validation;
}

int getRandomId(Employee* employees, int lengthEmployees, int* requestedRandomId)
{
    int firstRandomId=1000;
    int index;
    int validation=-1;

    index=findEmptyIndex(employees,lengthEmployees);

    if(index>=0)
    {
        *requestedRandomId=firstRandomId+index;
        validation=0;
    }
    return validation;
}

int findEmptyIndex(Employee* employees, int lengthEmployees)
{
    int index=-1;

    for(int i=0; i<lengthEmployees; i++)
    {
        if(employees[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int findEmployeeById(Employee* employees, int lengthEmployees,int id)
{
    int index=-1;
    for(int i=0; i<lengthEmployees; i++)
    {
        if(employees[i].id==id)
        {
            index=i;
        }
    }
    return index;
}

int removeEmployee(Employee* employees, int lengthEmployees)
{
    int idEmployee;
    int validation=0;
    int index;
    char confirm;
    printEmployees(employees,lengthEmployees);
    printf("Ingrese ID del empleado a eliminar: ");
    scanf("%d",&idEmployee);

    index=findEmployeeById(employees,lengthEmployees,idEmployee);

    if(index==-1)
    {
        printf("No se encontrado al empleado\n");
        system("pause");
        validation=-1;
    }
    else
    {
        system("cls");
        printf("\t EMPLEADO A ELIMINAR \n\n");
        printf("%8s %12s %12s %12s %12s\n", "ID", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);
        printf("Confirma eliminacion?\n");
        fflush(stdin);
        printf("Ingrese s/n: ");
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            employees[index].isEmpty=EMPTY;
            validation=0;
            printf("\nBaja Satisfactoria!!\n\n");
        }
        else
        {
            validation=-1;
        }
    }
    return validation;
}

int modifyMenu()
{
    int option;

    system("cls");
    printf("Que desea modificar?\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");

    printf("Ingrese opcion: ");
    scanf("%d",&option);

    return option;
}

int modifyEmployee(Employee* employees, int lengthEmployees)
{
    int validation=0;
    int index;
    int option;
    int idEmployee;

    printEmployees(employees,lengthEmployees);
    printf("Ingrese ID del empleado a modificar: ");
    scanf("%d",&idEmployee);

    index=findEmployeeById(employees,lengthEmployees,idEmployee);

    if(index==-1)
    {
        printf("No se ha encontrado al empleado\n");
        validation=-1;
    }
    else
    {
        option=modifyMenu();

        switch(option)
        {
        case 1:
            modifyNameEmployee(employees,lengthEmployees,index);
            break;
        case 2:
            modifyLastNameEmployee(employees,lengthEmployees,index);
            break;
        case 3:
            modifySalaryEmployee(employees,lengthEmployees,index);
            break;
        case 4:
            modifySectorEmployee(employees,lengthEmployees,index);
            break;
        default:
            printf("Opcion Invalida\n");
            break;
        }
    }
    return validation;
}

int modifyNameEmployee(Employee* employees, int lengthEmployees, int index)
{
    char auxName[51];
    char confirm;
    int validation;

    validation=getString(auxName,"Ingrese el NUEVO nombre del empleado","Nombre invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1)
    {
        system("cls");

        printf("\t EMPLEADO A MODIFICAR \n\n");
        printf("%8s %12s %12s %12s %12s\n", "ID", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);

        printf("Confirma NUEVO nombre: %s? s/n\n",auxName);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            strcpy(employees[index].name,auxName);
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }
    return validation;
}

int modifyLastNameEmployee(Employee* employees, int lengthEmployees, int index)
{
    char auxLastName[51];
    char confirm;
    int validation;

    validation=getString(auxLastName,"Ingrese el NUEVO apellido del empleado","Apellido invalido, cantidad de caracteres [min 2 - max 50]",2,50);

    if(validation==1)
    {
        system("cls");

        printf("\t MODIFICAR EMPLEADO\n\n");
        printf("6%8s %12s %12s %12s %12s\n", "ID", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);

        printf("Confirma NUEVO apellido: %s? s/n\n",auxLastName);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            strcpy(employees[index].lastName,auxLastName);
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }

    return validation;
}

int modifySalaryEmployee(Employee* employees, int lengthEmployees, int index)
{
    float auxSalary;
    int validation;
    char confirm;

    validation=getFloat(&auxSalary,"Ingrese el NUEVO salario del empleado","Salario invalido, rango [min 1 - max 999999]",1,100000);

    if(validation==1)
    {
        system("cls");

        printf("\t MODIFICAR EMPLEADO \n\n");
        printf("%8s %12s %12s %12s %12s\n", "ID", "Sector", "Nombre", "Apellido", "Sueldo");
        printEmployee(employees[index]);

        printf("Confirma Nuevo salario: %.2f? s/n\n",auxSalary);
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            employees[index].salary=auxSalary;
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }

    return validation;
}

int modifySectorEmployee(Employee* employees, int lengthEmployees, int index)
{
    int auxIdSector=0;
    int validation;
    char confirm;


    validation=getInt(&auxIdSector,"Elija el Nuevo sector del empleado","Opcion invalida, rango [0-5]",0,5);

    if(validation==1)
    {
        system("cls");

        printf("\t MODIFICAR EMPLEADO \n\n");
        printf("%8s %12s %12s %12s %12s\n", "ID", "Sector", "Apellido", "Nombre", "Sueldo");
        printEmployee(employees[index]);

        printf("AUXILIAR SECTORS ID(recibo): %d\n\n",auxIdSector);
        printf("Confirma NUEVO sector ?:s/n\n");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            employees[index].sector=auxIdSector;
            validation=0;
        }
        else
        {
            validation=-1;
        }
    }
    else
    {
        validation=-1;
    }
    return validation;
}

int sortingMenu(Employee* employees, int lengthEmployees)
{
    int order;

    system("cls");
    printf("Ordenar \n");
    printf("1- [A-Z]\n");
    printf("2- [Z-A]\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    sortEmployeesByName(employees,lengthEmployees,order);

    return order;
}

int sortEmployeesByName(Employee* employees, int lengthEmployees, int order)
{
    int sortingOk=0;

    for(int i=0; i<lengthEmployees-1; i++)
    {
        for(int j=i+1; j<lengthEmployees; j++)
        {
            if(employees[i].isEmpty==OCCUPIED)
            {
                if(order==1)
                {
                    if(employees[i].sector>employees[j].sector)
                    {
                        bubbleSorting(employees,lengthEmployees,i,j);
                    }
                    else
                    {
                        if((employees[i].sector==employees[j].sector)&&(strcmp(employees[i].name,employees[j].name)>0))
                        {
                            bubbleSorting(employees,lengthEmployees,i,j);
                        }
                    }
                }
                else if(order==2)
                {
                    if(employees[i].sector<employees[j].sector)
                    {
                        bubbleSorting(employees,lengthEmployees,i,j);
                    }
                    else
                    {
                        if((employees[i].sector==employees[j].sector)&&(strcmp(employees[i].name,employees[j].name)<0))
                        {
                            bubbleSorting(employees,lengthEmployees,i,j);
                        }
                    }
                }
            }
        }
    }

    return sortingOk;
}

void bubbleSorting(Employee* employees, int length, int i, int j)
{
    Employee auxEmp;

    auxEmp=employees[i];
    employees[i]=employees[j];
    employees[j]=auxEmp;
}

int printEmployees(Employee* employees, int lengthEmployees)
{
    system("cls");
    printf("\t LISTA DE EMPLEADOS ACTIVOS EN EL SISTEMA \t\n\n");
    printf("%8s %12s %12s %12s %12s\n", "ID", "Sector", "Nombre", "Apellido", "Sueldo");

    for(int i=0; i<lengthEmployees; i++)
    {
        if(employees[i].isEmpty==OCCUPIED)
        {
            printEmployee(employees[i]);
        }
    }
    return 0;
}

int printEmployee(Employee employee)
{

    printf("%8d %12d %12s %12s %12.2f\n", employee.id,employee.sector,employee.name,employee.lastName,employee.salary);

    return 0;
}

int reportsMenu()
{
    int option;

    system("cls");
    printf("\t MENU de Informes \n\n");
    printf("1- Lista de empleados por orden alfabetico\n");
    printf("2- Lista de total y promedio de salarios\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&option);

    return option;
}

int reports(Employee* employees, int lengthEmployees)
{

    int validation=0;

    switch(reportsMenu())
    {
    case 1:
        sortingMenu(employees,lengthEmployees);
        printf("\t EMPLEADOS ORDENADOS ALFABETICAMENTE \n\n");
        printEmployees(employees,lengthEmployees);
        break;
    case 2:
        reportsSalary(employees,lengthEmployees);
        break;
    default:
        printf("Opcion invalida!!");
        system("pause");
        validation=-1;
        break;
    }
    return validation;
}

void reportsSalary(Employee* employees, int lengthEmployees)
{

    float averageSalary=0;
    float accumulateSalary=0;
    int countAverage=0;
    int countEmployees=0;

    for(int i=0; i<lengthEmployees; i++)
    {
        if(employees[i].isEmpty==OCCUPIED)
        {
            accumulateSalary+=employees[i].salary;
            countEmployees++;
        }
    }

    averageSalary=accumulateSalary/countEmployees;

    for(int i=0; i<lengthEmployees; i++)
    {
        if(employees[i].isEmpty==OCCUPIED)
        {
            if(employees[i].salary>averageSalary)
            {
                countAverage++;
            }
        }
    }

    system("cls");
    printf("*** INFORME ***\n\n");
    printf("TOTAL sueldos: %.2f\n\n",accumulateSalary);
    printf("PROMEDIO sueldos: %.2f\n\n",averageSalary);
    printf("Cant. Emp. que superan el promedio: %d\n\n",countAverage);
}


int isInt(char auxNumero[]){
   int i=0;
   int todoOk = 1;
   while(auxNumero[i] != '\0'){
       if((atoi(auxNumero))==0){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}
int getInt(int* input,char mensaje[],char eMensaje[], int lowLimit, int hiLimit){
    int todoOk=1;
    int isInteger=0;
    int numeroValidado=0;
    char auxNumero[10]={'0'};

    printf("%s : ", mensaje);
    scanf("%s", auxNumero);
    isInteger=isInt(auxNumero);

    if(isInteger){
        numeroValidado=atoi(auxNumero);
        if(numeroValidado<lowLimit || numeroValidado>hiLimit){
            printf("%s : ", eMensaje);
            scanf("%s", auxNumero);
            todoOk=-1;
        }else{
            *input=numeroValidado;
        }
    }else{
        printf("Ingrese solo numeros!\n");
        todoOk=-1;
    }

    return todoOk;
}
int getFloat(float* input,char mensaje[],char eMensaje[], float lowLimit, float hiLimit){
    int todoOk=1;
    int isFloating=0;
    int numeroValidado=0;
    char auxNumero[10]={'0'};

    printf("%s : ", mensaje);
    scanf("%s", auxNumero);
    isFloating=isFloat(auxNumero);

    if(isFloating){
        numeroValidado=atof(auxNumero);
        if(numeroValidado<lowLimit || numeroValidado>hiLimit){
            printf("%s : ", eMensaje);
            scanf("%s", auxNumero);
            todoOk=-1;
        }else{
            *input=numeroValidado;
        }
    }else{
        printf("Ingrese solo numeros!\n");
        todoOk=-1;
    }
    return todoOk;
}

int isFloat(char auxNumero[]){
   int i=0;
   int todoOk = 1;
   int contadorComas=0;

   while(auxNumero[i] != '\0'){
       if(auxNumero[i]<'0' || auxNumero[i]>'9'){
           if(auxNumero[i]=='.'){
               contadorComas++;
           }
       }
       if((atof(auxNumero))==0 || contadorComas>1){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}

int getString(char* input,char mensaje[],char eMensaje[], int lowLimit, int hiLimit){
    char auxString[100]={"0"};
    int sizeOfString=0;
    int todoOk=0;
    int isCharacter=0;

    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%s", auxString);

    isCharacter=isChar(auxString);

    if(isCharacter){
      sizeOfString=strlen(auxString);
        if(sizeOfString>hiLimit || sizeOfString<lowLimit){
            system("cls");
            printf("%s ", eMensaje);
            todoOk=-1;

        }else{
            auxString[0]=toupper(auxString[0]);
            strcpy(input,auxString);
            todoOk=1;
        }
    }
    else{
        printf("Ingrese solo letras!\n");
        todoOk=-1;
    }

    return todoOk;
}

int isChar(char auxString[]){
   int i=0;
   int todoOk = 1;
   while(auxString[i] != '\0'){
       if((auxString[i] < 'a' || auxString[i] > 'z') && (auxString[i] < 'A' || auxString[i] > 'Z')){
           todoOk = 0;
       }
       i++;
   }
   return todoOk;
}

