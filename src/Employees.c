#include "Employees.h"

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

#define QTY_TAM 3


void initEmployees(Employee list[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		list[i].isEmpty = 0;
	}
}

int sortEmployees(Employee *list, int len, int order) {
	int i, j, r;
	Employee employeeAux;
	for (i = 0; i < 50 - 1; i++)
		for (j = i + 1; j < 50; j++) {
			/* Verificar si:
			 ** A) El apellido de empleado[i] es mayor que el apellido de empleado[j]
			 ** B) Si los apellidos son iguales pero el nombre de empleado[i] es
			 **    mayor que el nombre de empleado[j].
			 */
			r = strcmp(list[i].lastName, list[j].lastName);
			if (r > 0
					|| (r == 0 && strcmp(list[i].lastName, list[j].lastName) > 0)) {
				/* Intercambiar el valor de empleado[i] y empleado[j] */
				employeeAux = list[i];
				list[i] = list[j];
				list[j] = employeeAux;
			}
		}
	return 0;
}

int findEmployeeFree(Employee list[], int tam, int* position) {
	int indice = -1;
	int i;
	int retorno = -1;
	for (i = 0; i < tam; i++) {
		if (list[i].isEmpty == 0) {
			 retorno=0;
			 *position=i;
			 break;
		}
	}
	return retorno;
}

int menu() {
	int opcion;
	system("cls");
	printf("\n1--Alta cliente\n");
	printf("2--Modificar datos de cliente\n");
	printf("3--Baja de cliente\n");
	printf("4--Publicar\n");
	printf("5--Pausar publicación:\n");
	printf("5- Reanudar publicación:\n");
	printf("6--Pausar publicación:\n");
	printf("7--Imprimir Clientes:\n");
	printf("8--Imprimir publicaciones:\n");
	printf("9--Informar clientes:\n");
	printf("10--Informar publicaciones:\n");
	printf("11--SALIR\n\n");
	printf("\n Ingrese opcion: ");
	scanf("%d", &opcion);
	return opcion;
}

int printEmployees(Employee* list, int length)
{

	    int retorno=-1;
	    int i;
	    if(list!=NULL && length>=0)
	    {
	        for(i=0;i<length;i++)
	        {
	            if(list[i].isEmpty==0)
	                continue;
	            else
	                printf("\n ID: %d\n Nombre: %s\n Apelldio: %s\n Salario: %f\n Sector: %i",
	                       list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);      //cambiar todos
	        }
	        retorno=0;
	    }
	    return retorno;
	}

int employeedFindID(Employee* employed, int len, int idSearch, int* position)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(employed!= NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(employed[i].isEmpty==1)
                continue;
            else if(employed[i].id==idSearch)                                                   //cambiar campo ID
            {
                retorno=0;
                *position=i;
                break;
            }
        }
    }
    return retorno;
}

int employeedModify (Employee* employee, int len){
	    int retorno=-1;
	    int position;
	    int id;
	    char opcion;
	    if(employee!=NULL && len>0)
	    {
	        Utils_getInt("\nID a modificar: ","\nError",1,sizeof(int),1,len,1,&id);
	        if(employeedFindID(employee,len,id,&position)==-1)
	        {
	            printf("\nNo existe este ID");
	        }
	        else
	        {
	            do
	            {
	            	printEmployees(employee, QTY_TAM);
	                Utils_getChar("\nModificar: 1 2 3 4 S(salir)","\nError",'A','Z',1,&opcion);
	                switch(opcion)
	                {
	                    case 'A':
	                        Utils_getInt("\n: ","\nError",1,sizeof(int),1,1,1,&employee[position].name);
	                        break;
	                    case 'B':
	                        Utils_getFloat("\n: ","\nError",1,sizeof(float),0,1,1,&employee[position].lastName);
	                        break;
	                    case 'C':
	                        Utils_getChar("\n: ","\nError",1,TEXT_SIZE,1,employee[position].salary);
	                        break;
	                    case 'D':
	                        Utils_getTexto("\n: ","\nError",1,TEXT_SIZE,1,employee[position].sector);
	                        break;
	                    case 'S':
	                        break;
	                    default:
	                        printf("\nOpcion no valida");
	                }
	            }while(opcion!='S');
	            retorno=0;
	        }
	    }
	    return retorno;

}

int findEmployeeById(Employee* list, int len,int id, int* position)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
                continue;
            else if(list[i].id==id)
            {
                retorno=0;
                *position=i;
                break;
            }
        }
    }
    return retorno;
}



int addEmployee(Employee *list, int len, int* countID) {
    int retorno=-1;
    int position;
    if(list!=NULL && len>0 && countID!=NULL)
    {
        if(findEmployeeFree(list,len,&position)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else {
			(*countID)++;
			list[position].id = *countID;
			list[position].isEmpty = 1;
			Utils_getChar("getName\n: ", "\nError", 1, TEXT_SIZE, 1,
					list[position].name);
			Utils_getChar("getName\n: ", "\nError", 1, TEXT_SIZE, 1,
					list[position].lastName);
			Utils_getFloat("\ngetFloat: ", "\nError", 1, sizeof(float), 0, 1, 1,
					&list[position].salary);
			Utils_getInt("\ngetUnsignedInt: ", "\nError", 1, sizeof(int),
					1, 1, 1, &list[position].sector);
			printf(
					"\n ID: %d\n Nombre: %s\n Apelldio: %s\n Salario: %f\n Sector: %i",
					list[position].id, list[position].name,
					list[position].lastName, list[position].salary,
					list[position].sector);
			retorno = 0;
		}
	}
    return retorno;
}

void captureData(char *name, char *lastName, float *salary, int *sector) {

	printf("Ingrese el name: ");
	fgets(name, sizeof(name), stdin);
	__fpurge(stdin);
	printf("\nIngrese el lastname: ");
	fgets(lastName, sizeof(lastName), stdin);
	printf("\nIngrese salary ");
	scanf("%f", salary);
	printf("\nIngrese sector ");
	scanf("%d", sector);
}


int removeEmployee(Employee* list, int len)
{
    int retorno=-1;
    int position;
    int id;
    if(list!=NULL && len>0)
    {
        Utils_getInt("\nID a cancelar: ","\nError",1,sizeof(int),1,len,1,&id);
        if(findEmployeeById(list,len,id,&position)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	list[position].id=0;
        	strcpy(list[position].name,"");
        	strcpy(list[position].lastName,"");
        	list[position].sector=0;
        	list[position].salary=0;
        	list[position].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
