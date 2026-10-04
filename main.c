#include <stdio.h>
#include <stdlib.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "common.h"

void displayMainMenu(void) {
    printf("\n");
    printf("========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

int main(void) {
    /* Data storage (arrays of structs) */
    Employee employees[MAX_EMPLOYEES];
    int empCount = 0;

    Budget budgets[MAX_DEPTS];
    int budCount = 0;

    Supplier suppliers[MAX_SUPPLIERS];
    int supCount = 0;

    Asset assets[MAX_ASSETS];
    int assetCount = 0;

    int choice;

    printf("\nWelcome to the Municipal Financial Management System (MFMS)\n");
    printf("Foundation Version - Project A\n");

    do {
        displayMainMenu();

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("\nInvalid input. Please enter a number between 1 and 6.\n");
            choice = 0;
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                employeeMenu(employees, &empCount);
                break;
            case 2:
                budgetMenu(budgets, &budCount);
                break;
            case 3:
                supplierMenu(suppliers, &supCount);
                break;
            case 4:
                assetMenu(assets, &assetCount);
                break;
            case 5:
                reportsMenu(employees, empCount,
                            budgets, budCount,
                            suppliers, supCount,
                            assets, assetCount);
                break;
            case 6:
                printf("\nThank you for using MFMS. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select 1-6.\n");
        }
    } while (choice != 6);

    return 0;
}
