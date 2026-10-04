#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPTS 20
#define DEPT_NAME_LEN 30

typedef struct {
    char department[DEPT_NAME_LEN];
    float allocated;
    float expenditure;
} Budget;

void budgetMenu(Budget budgets[], int *count);
void addBudget(Budget budgets[], int *count);
void enterExpenditure(Budget budgets[], int count);
void displayBudgets(Budget budgets[], int count);
void checkOverBudget(Budget budgets[], int count);
float getRemaining(Budget b);

#endif
