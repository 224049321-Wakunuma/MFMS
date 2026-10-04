#include <stdio.h>
#include "reports.h"
#include "common.h"

void employeeReport(Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees to report on.\n");
        return;
    }

    float totalSalary = 0.0f;
    float highest = employees[0].basicSalary + employees[0].housingAllowance + employees[0].transportAllowance;
    float lowest = highest;

    for (int i = 0; i < count; i++) {
        float tot = employees[i].basicSalary + employees[i].housingAllowance + employees[i].transportAllowance;
        totalSalary += tot;
        if (tot > highest) highest = tot;
        if (tot < lowest) lowest = tot;
    }

    float average = totalSalary / count;

    printf("\n========== EMPLOYEE REPORT ==========\n");
    printf("Total Employees:   %d\n", count);
    printf("Average Salary:    N$%.2f\n", average);
    printf("Highest Salary:    N$%.2f\n", highest);
    printf("Lowest Salary:     N$%.2f\n", lowest);
    printf("=====================================\n");
}

void budgetReport(Budget budgets[], int count) {
    if (count == 0) {
        printf("\nNo budget data available.\n");
        return;
    }

    float totalAllocated = 0.0f;
    float totalExpenditure = 0.0f;

    for (int i = 0; i < count; i++) {
        totalAllocated += budgets[i].allocated;
        totalExpenditure += budgets[i].expenditure;
    }

    float remaining = totalAllocated - totalExpenditure;

    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Allocated Budget:  N$%.2f\n", totalAllocated);
    printf("Total Expenditure:       N$%.2f\n", totalExpenditure);
    printf("Remaining Budget:        N$%.2f\n", remaining);
    printf("\nDepartments exceeding budget:\n");

    int over = 0;
    for (int i = 0; i < count; i++) {
        if (budgets[i].expenditure > budgets[i].allocated) {
            printf("  - %s (Over by N$%.2f)\n",
                   budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocated);
            over = 1;
        }
    }
    if (!over) {
        printf("  None\n");
    }
    printf("===================================\n");
}

void supplierReport(Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n========== SUPPLIER REPORT ==========\n");
    printf("Total Suppliers: %d\n\n", count);
    printf("%-6s %-20s %-15s\n", "ID", "Name", "Town");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-15s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].town);
    }
    printf("=====================================\n");
}

void assetReport(Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets registered.\n");
        return;
    }

    float totalValue = 0.0f;
    for (int i = 0; i < count; i++) {
        totalValue += assets[i].purchaseValue;
    }

    printf("\n========== ASSET REPORT ==========\n");
    printf("Total Assets:        %d\n", count);
    printf("Total Asset Value:   N$%.2f\n\n", totalValue);
    printf("%-6s %-20s %-15s %-12s\n", "ID", "Name", "Type", "Value");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-15s N$%-10.2f\n",
               assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue);
    }
    printf("==================================\n");
}

void reportsMenu(Employee employees[], int empCount,
                 Budget budgets[], int budCount,
                 Supplier suppliers[], int supCount,
                 Asset assets[], int assetCount) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("              REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input.\n");
            choice = 0;
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1: employeeReport(employees, empCount); break;
            case 2: budgetReport(budgets, budCount); break;
            case 3: supplierReport(suppliers, supCount); break;
            case 4: assetReport(assets, assetCount); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}
