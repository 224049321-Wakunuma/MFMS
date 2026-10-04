#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "common.h"

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("\nError: Supplier list is full (max %d).\n", MAX_SUPPLIERS);
        return;
    }

    Supplier s;
    int idOk = 0;

    printf("\n--- Add New Supplier ---\n");

    do {
        printf("Enter Supplier ID (positive number): ");
        if (scanf("%d", &s.id) != 1) {
            printf("Invalid input.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        if (s.id <= 0) {
            printf("ID must be positive.\n");
            continue;
        }

        int exists = 0;
        for (int i = 0; i < *count; i++) {
            if (suppliers[i].id == s.id) {
                exists = 1;
                break;
            }
        }
        if (exists) {
            printf("Supplier ID already exists.\n");
        } else {
            idOk = 1;
        }
    } while (!idOk);

    do {
        printf("Enter Supplier Name: ");
        readString(s.name, SUP_NAME_LEN);
        if (isEmpty(s.name)) printf("Name cannot be empty.\n");
    } while (isEmpty(s.name));

    do {
        printf("Enter Email: ");
        readString(s.email, EMAIL_LEN);
        if (isEmpty(s.email)) printf("Email cannot be empty.\n");
    } while (isEmpty(s.email));

    do {
        printf("Enter Telephone Number: ");
        readString(s.phone, PHONE_LEN);
        if (isEmpty(s.phone)) printf("Phone cannot be empty.\n");
    } while (isEmpty(s.phone));

    do {
        printf("Enter Town/Location: ");
        readString(s.town, TOWN_LEN);
        if (isEmpty(s.town)) printf("Town cannot be empty.\n");
    } while (isEmpty(s.town));

    suppliers[*count] = s;
    (*count)++;
    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n========== SUPPLIER LIST ==========\n");
    printf("%-6s %-20s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
    printf("===================================\n");
}

void searchSupplier(Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers to search.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n");
    printf("1. Supplier ID\n");
    printf("2. Name\n");
    printf("3. Town\n");
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
        printf("Enter Supplier ID: ");
        if (scanf("%d", &id) != 1) {
            clearBuffer();
            printf("Invalid ID.\n");
            return;
        }
        clearBuffer();

        for (int i = 0; i < count; i++) {
            if (suppliers[i].id == id) {
                printf("\n--- Supplier Found ---\n");
                printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",
                       suppliers[i].id, suppliers[i].name,
                       suppliers[i].email, suppliers[i].phone, suppliers[i].town);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char name[SUP_NAME_LEN];
        printf("Enter Name (or part of name): ");
        readString(name, SUP_NAME_LEN);

        for (int i = 0; i < count; i++) {
            if (strstr(suppliers[i].name, name) != NULL) {
                printf("\n--- Supplier Found ---\n");
                printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",
                       suppliers[i].id, suppliers[i].name,
                       suppliers[i].email, suppliers[i].phone, suppliers[i].town);
                found = 1;
            }
        }
    } else if (choice == 3) {
        char town[TOWN_LEN];
        printf("Enter Town: ");
        readString(town, TOWN_LEN);

        for (int i = 0; i < count; i++) {
            if (strcmp(suppliers[i].town, town) == 0 ||
                strstr(suppliers[i].town, town) != NULL) {
                printf("\n--- Supplier Found ---\n");
                printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",
                       suppliers[i].id, suppliers[i].name,
                       suppliers[i].email, suppliers[i].phone, suppliers[i].town);
                found = 1;
            }
        }
    } else {
        printf("Invalid search option.\n");
        return;
    }

    if (!found) {
        printf("\nNo matching supplier found.\n");
    }
}

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("       SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input.\n");
            choice = 0;
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}
