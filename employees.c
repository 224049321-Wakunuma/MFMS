#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "common.h"

float getTotalSalary(Employee emp) {
    return emp.basicSalary + emp.housingAllowance + emp.transportAllowance;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nError: Employee list is full (max %d).\n", MAX_EMPLOYEES);
        return;
    }

    Employee emp;
    int idOk = 0;

    printf("\n--- Add New Employee ---\n");

    /* Employee ID */
    do {
        printf("Enter Employee ID (positive number): ");
        if (scanf("%d", &emp.id) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        if (emp.id <= 0) {
            printf("ID must be positive.\n");
            continue;
        }

        /* Check for duplicate ID */
        int exists = 0;
        for (int i = 0; i < *count; i++) {
            if (employees[i].id == emp.id) {
                exists = 1;
                break;
            }
        }
        if (exists) {
            printf("Employee ID already exists. Try another.\n");
        } else {
            idOk = 1;
        }
    } while (!idOk);

    /* Name */
    do {
        printf("Enter Name: ");
        readString(emp.name, NAME_LEN);
        if (isEmpty(emp.name)) {
            printf("Name cannot be empty.\n");
        }
    } while (isEmpty(emp.name));

    /* Department */
    do {
        printf("Enter Department: ");
        readString(emp.department, DEPT_LEN);
        if (isEmpty(emp.department)) {
            printf("Department cannot be empty.\n");
        }
    } while (isEmpty(emp.department));

    /* Basic Salary */
    do {
        printf("Enter Basic Salary (N$): ");
        if (scanf("%f", &emp.basicSalary) != 1) {
            printf("Invalid number.\n");
            clearBuffer();
            emp.basicSalary = -1;
            continue;
        }
        clearBuffer();
        if (emp.basicSalary < 0) {
            printf("Salary cannot be negative.\n");
        }
    } while (emp.basicSalary < 0);

    /* Housing Allowance */
    do {
        printf("Enter Housing Allowance (N$): ");
        if (scanf("%f", &emp.housingAllowance) != 1) {
            printf("Invalid number.\n");
            clearBuffer();
            emp.housingAllowance = -1;
            continue;
        }
        clearBuffer();
        if (emp.housingAllowance < 0) {
            printf("Allowance cannot be negative.\n");
        }
    } while (emp.housingAllowance < 0);

    /* Transport Allowance */
    do {
        printf("Enter Transport Allowance (N$): ");
        if (scanf("%f", &emp.transportAllowance) != 1) {
            printf("Invalid number.\n");
            clearBuffer();
            emp.transportAllowance = -1;
            continue;
        }
        clearBuffer();
        if (emp.transportAllowance < 0) {
            printf("Allowance cannot be negative.\n");
        }
    } while (emp.transportAllowance < 0);

    employees[*count] = emp;
    (*count)++;
    printf("\nEmployee added successfully!\n");
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");
    printf("%-6s %-20s %-15s %-12s %-12s %-12s %-12s\n",
           "ID", "Name", "Department", "Basic", "Housing", "Transport", "Total");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        float total = getTotalSalary(employees[i]);
        printf("%-6d %-20s %-15s N$%-10.2f N$%-10.2f N$%-10.2f N$%-10.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].basicSalary,
               employees[i].housingAllowance,
               employees[i].transportAllowance,
               total);
    }
    printf("===================================\n");
}

void searchEmployee(Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees to search.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n");
    printf("1. Employee ID\n");
    printf("2. Name\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        clearBuffer();
        printf("Invalid choice.\n");
        return;
    }
    clearBuffer();

    int found = 0;

    if (choice == 1) {
        int id;
        printf("Enter Employee ID: ");
        if (scanf("%d", &id) != 1) {
            clearBuffer();
            printf("Invalid ID.\n");
            return;
        }
        clearBuffer();

        for (int i = 0; i < count; i++) {
            if (employees[i].id == id) {
                printf("\n--- Employee Found ---\n");
                printf("ID: %d\n", employees[i].id);
                printf("Name: %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
                printf("Housing: N$%.2f\n", employees[i].housingAllowance);
                printf("Transport: N$%.2f\n", employees[i].transportAllowance);
                printf("Total Salary: N$%.2f\n", getTotalSalary(employees[i]));
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char name[NAME_LEN];
        printf("Enter Name (or part of name): ");
        readString(name, NAME_LEN);

        for (int i = 0; i < count; i++) {
            if (strstr(employees[i].name, name) != NULL ||
                strcmp(employees[i].name, name) == 0) {
                printf("\n--- Employee Found ---\n");
                printf("ID: %d\n", employees[i].id);
                printf("Name: %s\n", employees[i].name);
                printf("Department: %s\n", employees[i].department);
                printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
                printf("Housing: N$%.2f\n", employees[i].housingAllowance);
                printf("Transport: N$%.2f\n", employees[i].transportAllowance);
                printf("Total Salary: N$%.2f\n", getTotalSalary(employees[i]));
                found = 1;
            }
        }
    } else {
        printf("Invalid search option.\n");
        return;
    }

    if (!found) {
        printf("\nNo matching employee found.\n");
    }
}

void calculateSalary(Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees registered.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to calculate total salary: ");
    if (scanf("%d", &id) != 1) {
        clearBuffer();
        printf("Invalid ID.\n");
        return;
    }
    clearBuffer();

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            float total = getTotalSalary(employees[i]);
            printf("\n--- Salary Calculation ---\n");
            printf("Employee: %s (ID: %d)\n", employees[i].name, employees[i].id);
            printf("Basic Salary:      N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
            printf("----------------------------\n");
            printf("TOTAL SALARY:      N$%.2f\n", total);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void employeeMenu(Employee employees[], int *count) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("       EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input. Please enter a number.\n");
            choice = 0;
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: displayEmployees(employees, *count); break;
            case 3: searchEmployee(employees, *count); break;
            case 4: calculateSalary(employees, *count); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
