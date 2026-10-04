# Individual Contribution Records  
**Project A – Municipal Financial Management System (MFMS)**  
**Course:** PAP521S – Programming in Practice  

---

## Student 1 – Employee Management

**Student Name:** wakunuma leeh  
**Student Number:** 224049321  
**Assigned Responsibility:** Employee Management  

### Functions / Modules Developed
- Designed the `Employee` structure
- Implemented `addEmployee()`
- Implemented `displayEmployees()`
- Implemented `searchEmployee()` (by ID and by name)
- Implemented `calculateSalary()` and `getTotalSalary()`
- Created `employees.h` and `employees.c`
- Added input validation for employee ID, name, department and salary fields

### GitHub Contribution
- Multiple commits related to the employee module
- Initial structure of `employees.h` and `employees.c`
- Bug fixes for duplicate ID checking and negative salary rejection

### Testing Performed
- Tested adding employees with valid and invalid data
- Tested searching by exact ID and partial name
- Verified total salary calculation (basic + housing + transport)
- Confirmed that empty names and negative salaries are rejected

---

## Student 2 – Budget Management

**Student Name:** wakunuma leeh 
**Student Number:** 224049321  
**Assigned Responsibility:** Budget Management  

### Functions / Modules Developed
- Designed the `Budget` structure
- Implemented `addBudget()`
- Implemented `enterExpenditure()`
- Implemented `displayBudgets()`
- Implemented `checkOverBudget()` and `getRemaining()`
- Created `budget.h` and `budget.c`
- Added logic to detect departments that exceeded their allocated budget

### GitHub Contribution
- Commits for budget module creation and updates
- Added status messages (“WITHIN BUDGET” / “OVER BUDGET”)
- Fixed remaining budget calculation

### Testing Performed
- Tested entering departmental budgets
- Tested recording multiple expenditures for the same department
- Verified over-budget detection
- Confirmed that negative budget and expenditure values are rejected

---

## Student 3 – Supplier Management

**Student Name:** wakunuma leeh  
**Student Number:** 224049321  
**Assigned Responsibility:** Supplier Management  

### Functions / Modules Developed
- Designed the `Supplier` structure
- Implemented `addSupplier()`
- Implemented `displaySuppliers()`
- Implemented `searchSupplier()` (by ID, name and town)
- Created `suppliers.h` and `suppliers.c`
- Added validation for supplier ID, name, email, phone and town

### GitHub Contribution
- Commits for supplier module
- Added search by town functionality
- Improved display formatting of supplier list

### Testing Performed
- Tested adding suppliers with valid and invalid data
- Tested search by ID, partial name and town
- Confirmed duplicate supplier IDs are rejected
- Verified empty fields are not accepted

---

## Student 4 – Asset Management

**Student Name:** wakunuma leeh  
**Student Number:** 224049321 
**Assigned Responsibility:** Asset Management  

### Functions / Modules Developed
- Designed the `Asset` structure
- Implemented `addAsset()`
- Implemented `displayAssets()`
- Implemented `searchAsset()` (by ID, name, type and department)
- Created `assets.h` and `assets.c`
- Added validation for asset ID, name, type, purchase value, department and condition

### GitHub Contribution
- Commits for asset module
- Added multiple search options
- Improved asset register display layout

### Testing Performed
- Tested adding different types of assets (Vehicle, Computer, Building, etc.)
- Tested all four search options
- Confirmed negative purchase values are rejected
- Verified empty fields are handled correctly

---

## Student 5 – Reports

**Student Name:** wakunuma leeh  
**Student Number:** 224049321  
**Assigned Responsibility:** Reports  

### Functions / Modules Developed
- Implemented `employeeReport()` (total, average, highest and lowest salary)
- Implemented `budgetReport()` (total allocated, total expenditure, remaining, over-budget departments)
- Implemented `supplierReport()`
- Implemented `assetReport()` (total assets and total value)
- Created `reports.h` and `reports.c`
- Designed the Reports sub-menu

### GitHub Contribution
- Commits for reports module
- Added summary calculations
- Improved report formatting

### Testing Performed
- Tested all four reports with empty data and with sample data
- Verified average, highest and lowest salary calculations
- Confirmed over-budget departments appear correctly in the budget report
- Checked that reports handle zero records gracefully

---

## Student 6 – Functions, Integration and Validation

**Student Name:** wakunuma leeh  
**Student Number:** 224049321  
**Assigned Responsibility:** Functions, Integration and Validation  

### Functions / Modules Developed
- Created the shared utility module (`common.h` and `common.c`)
- Implemented `clearBuffer()`, `readString()` and `isEmpty()`
- Integrated all modules into `main.c`
- Designed the main menu and overall program flow
- Ensured consistent input validation across all modules
- Standardised function prototypes and header guards

### GitHub Contribution
- Initial project structure commits
- Created and refined `common.c` / `common.h`
- Integration commits linking all modules
- Final clean-up and compilation fixes

### Testing Performed
- Tested full program flow from main menu through every sub-menu
- Verified that invalid menu choices are handled everywhere
- Confirmed that shared helper functions work correctly across modules
- Checked for compilation warnings and resolved them

---

## Student 7 – Testing, Documentation and Git Coordination

**Student Name:** wakunuma leeh  
**Student Number:** 224049321 
**Assigned Responsibility:** Testing, Documentation and Git Coordination  

### Functions / Modules Developed
- Created and maintained the project `README.md`
- Wrote compilation and usage instructions
- Coordinated the final modular structure
- Documented all identified issues (see Testing Report)
- Prepared the final submission package

### GitHub Contribution
- Repository initialisation and structure
- Organised commit history so each module is identifiable
- Final repository clean-up before submission
- Ensured all source files and documentation were present

### Testing Performed
- Full system testing of all modules after integration
- Documented realistic issues found (input buffer, case-sensitive search, etc.)
- Verified that the program compiles cleanly with `-Wall -Wextra`
- Confirmed that the program runs without crashing under normal and invalid input

---

## Declaration

Although this document lists seven students, the complete system was developed, tested and documented by a single developer for the purpose of this submission. All modules, functions, validation and documentation were implemented by the same person.

**Date:** 02 October 2026
