#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "common.h"

float getRemaining(Budget b) {
    return b.allocated - b.expenditure;
}

void addBudget(Budget budgets[], int *count) {
    if (*count >= MAX_DEPTS) {
        printf("\nError: Maximum departments reached (%d).\n", MAX_DEPTS);
        return;
    }

    Budget b;
    printf("\n--- Enter Departmental Budget ---\n");

    do {
        printf("Enter Department Name: ");
        readString(b.department, DEPT_NAME_LEN);
        if (isEmpty(b.department)) {
            printf("Department name cannot be empty.\n");
        }
    } while (isEmpty(b.department));

    /* Check if department already exists */
    for (int i = 0; i < *count; i++) {
        if (strcmp(budgets[i].department, b.department) == 0) {
            printf("Department already has a budget entry.\n");
            return;
        }
    }

    do {
        printf("Enter Allocated Budget (N$): ");
        if (scanf("%f", &b.allocated) != 1) {
            printf("Invalid number.\n");
            clearBuffer();
            b.allocated = -1;
            continue;
        }
        clearBuffer();
        if (b.allocated < 0) {
            printf("Budget cannot be negative.\n");
        }
    } while (b.allocated < 0);

    b.expenditure = 0.0f;  /* start with zero expenditure */

    budgets[*count] = b;
    (*count)++;
    printf("Budget for %s added successfully.\n", b.department);
}

void enterExpenditure(Budget budgets[], int count) {
    if (count == 0) {
        printf("\nNo budgets defined yet. Please add a budget first.\n");
        return;
    }

    char dept[DEPT_NAME_LEN];
    printf("\nEnter Department Name: ");
    readString(dept, DEPT_NAME_LEN);

    int found = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(budgets[i].department, dept) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Department not found.\n");
        return;
    }

    float amount;
    do {
        printf("Enter Expenditure Amount (N$): ");
        if (scanf("%f", &amount) != 1) {
            printf("Invalid number.\n");
            clearBuffer();
            amount = -1;
            continue;
        }
        clearBuffer();
        if (amount < 0) {
            printf("Expenditure cannot be negative.\n");
        }
    } while (amount < 0);

    budgets[found].expenditure += amount;
    printf("Expenditure recorded. New total expenditure for %s: N$%.2f\n",
           budgets[found].department, budgets[found].expenditure);
}

void displayBudgets(Budget budgets[], int count) {
    if (count == 0) {
        printf("\nNo budget information available.\n");
        return;
    }

    printf("\n========== BUDGET INFORMATION ==========\n");
    printf("%-20s %-15s %-15s %-15s %-15s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        float rem = getRemaining(budgets[i]);
        const char *status = (rem >= 0) ? "WITHIN BUDGET" : "OVER BUDGET";
        printf("%-20s N$%-13.2f N$%-13.2f N$%-13.2f %s\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].expenditure,
               rem,
               status);
    }
    printf("========================================\n");
}

void checkOverBudget(Budget budgets[], int count) {
    if (count == 0) {
        printf("\nNo budgets defined.\n");
        return;
    }

    printf("\n--- Departments Exceeding Budget ---\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (getRemaining(budgets[i]) < 0) {
            printf("%s: Allocated N$%.2f | Spent N$%.2f | Over by N$%.2f\n",
                   budgets[i].department,
                   budgets[i].allocated,
                   budgets[i].expenditure,
                   -getRemaining(budgets[i]));
            found = 1;
        }
    }
    if (!found) {
        printf("All departments are within budget.\n");
    }
}

void budgetMenu(Budget budgets[], int *count) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("         BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Enter Departmental Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. Display Budget Information\n");
        printf("4. Check Departments Over Budget\n");
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
            case 1: addBudget(budgets, count); break;
            case 2: enterExpenditure(budgets, *count); break;
            case 3: displayBudgets(budgets, *count); break;
            case 4: checkOverBudget(budgets, *count); break;
            case 5: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}
