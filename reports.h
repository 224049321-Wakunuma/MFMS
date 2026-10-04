#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void reportsMenu(Employee employees[], int empCount,
                 Budget budgets[], int budCount,
                 Supplier suppliers[], int supCount,
                 Asset assets[], int assetCount);

void employeeReport(Employee employees[], int count);
void budgetReport(Budget budgets[], int count);
void supplierReport(Supplier suppliers[], int count);
void assetReport(Asset assets[], int count);

#endif
