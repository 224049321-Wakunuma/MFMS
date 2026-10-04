#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50
#define NAME_LEN 50
#define DEPT_LEN 30

typedef struct {
    int id;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

void employeeMenu(Employee employees[], int *count);
void addEmployee(Employee employees[], int *count);
void displayEmployees(Employee employees[], int count);
void searchEmployee(Employee employees[], int count);
void calculateSalary(Employee employees[], int count);
float getTotalSalary(Employee emp);

#endif
