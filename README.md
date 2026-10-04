# Municipal Financial Management System (MFMS)

**Project A – Foundation System**  
**Course:** PAP521S – Programming in Practice  
**Language:** ANSI C (C99)  
**Environment:** GCC / Visual Studio Code  

## Project Description

This is a simple console-based Municipal Financial Management System developed in C.  
It demonstrates the use of:

- Menu-driven interface
- Variables and appropriate data types
- Input validation
- Arithmetic, relational and logical operators
- Decision making (`if`, `if-else`, `switch`)
- Loops
- Arrays of structures
- String manipulation (`strlen`, `strcmp`, `strcpy`, `strstr`)
- Functions with parameters and return values
- Modular program organisation (separate .c / .h files)
- Shared common utilities (`common.c` / `common.h`)

## Project Structure

```
MFMS/
├── main.c
├── common.h
├── common.c
├── employees.h
├── employees.c
├── budget.h
├── budget.c
├── suppliers.h
├── suppliers.c
├── assets.h
├── assets.c
├── reports.h
├── reports.c
└── README.md
```

## System Features

1. **Employee Management**
   - Add employee (ID, Name, Department, Basic Salary, Housing & Transport Allowance)
   - Display all employees
   - Search by ID or Name
   - Calculate total salary

2. **Budget Management**
   - Enter departmental budgets
   - Record expenditure
   - Display budget status (Within / Over Budget)
   - Identify departments that exceeded budget

3. **Supplier Management**
   - Add supplier (ID, Name, Email, Phone, Town)
   - Display all suppliers
   - Search by ID, Name or Town

4. **Asset Management**
   - Add asset (ID, Name, Type, Purchase Value, Department, Condition)
   - Display all assets
   - Search by ID, Name, Type or Department

5. **Reports**
   - Employee Report (count, average, highest, lowest salary)
   - Budget Report (totals + over-budget departments)
   - Supplier Report
   - Asset Report (count + total value)

## Compilation Instructions

Open a terminal in the `MFMS` folder and run:

```bash
gcc -std=c99 -Wall -Wextra -o mfms main.c common.c employees.c budget.c suppliers.c assets.c reports.c
```

## How to Run

```bash
./mfms
```

(On Windows: `mfms.exe`)

## Individual Responsibilities (Solo Implementation)

This version was developed as a complete single-developer solution covering all modules:

- Employee Management
- Budget Management
- Supplier Management
- Asset Management
- Reports
- Common utilities, functions, integration and validation
- Documentation

## Notes

- All data is stored in memory (arrays). Data is lost when the program exits.
- Input validation prevents negative salaries/budgets, empty names, duplicate IDs and invalid menu choices.
- Shared helper functions (`clearBuffer`, `readString`, `isEmpty`) are placed in `common.c` / `common.h`.
- The program uses clear modular design with header files and separate source files.
