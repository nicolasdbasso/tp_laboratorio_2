/*
 ============================================================================
 Name        : empleados.c
 Author      : se
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "Employees.h"

#define QTY_TAM 3
#define TEXT_SIZE 51



int menu();
void initEmployees(Employee* list, int tam);

int Utils_isValidChar(char charRecibido);

int main() {

	char continuar = 's';
	Employee employees[QTY_TAM];
	initEmployees(employees, QTY_TAM);
	int countID = 0;

	do {

		switch (menu()) {
		case 1:
			printf("\nAlta de empleado\n\n");
			addEmployee(employees, sizeof(employees), countID);
			system("pause");
			break;
		case 2:
			printf("\nModificar datos de empleado\n\n");
			employeedModify (employees, sizeof(employees));
			break;
		case 3:
			printf("\nBaja de cliente\n\n");
			removeEmployee(employees, sizeof(employees));
			break;
		case 4:
			printf("\nINFORME\n\n");

			break;
		}
		printf("\nDesea continuar 's': ");
		scanf("%c", &continuar);
	} while (continuar == 's');

	return 0;

}
