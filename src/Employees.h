
#define TEXT_SIZE 51

typedef struct {
	int id;
	char name[TEXT_SIZE];
	char lastName[TEXT_SIZE];
	float salary;
	int sector;
	int isEmpty;
} Employee;

int findEmployeeById(Employee* list, int len,int id, int* position);
void captureData(char *name, char *lastName, float *salary, int *sector);
int printEmployees(Employee* list, int length);
int employeedModify (Employee* employee, int len);
int removeEmployee(Employee* list, int len);
int addEmployee(Employee *list, int len, int* countID);
int findEmployeeFree(Employee* list, int tam, int* position);
