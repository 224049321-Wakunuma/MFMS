#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "common.h"

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) {
        printf("\nError: Asset list is full (max %d).\n", MAX_ASSETS);
        return;
    }

    Asset a;
    int idOk = 0;

    printf("\n--- Add New Asset ---\n");

    do {
        printf("Enter Asset ID (positive number): ");
        if (scanf("%d", &a.id) != 1) {
            printf("Invalid input.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        if (a.id <= 0) {
            printf("ID must be positive.\n");
            continue;
        }

        int exists = 0;
        for (int i = 0; i < *count; i++) {
            if (assets[i].id == a.id) {
                exists = 1;
                break;
            }
        }
        if (exists) {
            printf("Asset ID already exists.\n");
        } else {
            idOk = 1;
        }
    } while (!idOk);

    do {
        printf("Enter Asset Name: ");
        readString(a.name, ASSET_NAME_LEN);
        if (isEmpty(a.name)) printf("Name cannot be empty.\n");
    } while (isEmpty(a.name));

    do {
        printf("Enter Asset Type (e.g. Vehicle, Computer, Building, Equipment, Furniture): ");
        readString(a.type, ASSET_TYPE_LEN);
        if (isEmpty(a.type)) printf("Type cannot be empty.\n");
    } while (isEmpty(a.type));

    do {
        printf("Enter Purchase Value (N$): ");
        if (scanf("%f", &a.purchaseValue) != 1) {
            printf("Invalid number.\n");
            clearBuffer();
            a.purchaseValue = -1;
            continue;
        }
        clearBuffer();
        if (a.purchaseValue < 0) {
            printf("Value cannot be negative.\n");
        }
    } while (a.purchaseValue < 0);

    do {
        printf("Enter Department: ");
        readString(a.department, ASSET_DEPT_LEN);
        if (isEmpty(a.department)) printf("Department cannot be empty.\n");
    } while (isEmpty(a.department));

    do {
        printf("Enter Condition (e.g. Good, Fair, Poor, New): ");
        readString(a.condition, CONDITION_LEN);
        if (isEmpty(a.condition)) printf("Condition cannot be empty.\n");
    } while (isEmpty(a.condition));

    assets[*count] = a;
    (*count)++;
    printf("\nAsset added successfully!\n");
}

void displayAssets(Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }

    printf("\n========== ASSET REGISTER ==========\n");
    printf("%-6s %-20s %-15s %-12s %-15s %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("----------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-15s N$%-10.2f %-15s %-10s\n",
               assets[i].id,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }
    printf("====================================\n");
}

void searchAsset(Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets to search.\n");
        return;
    }

    int choice;
    printf("\nSearch by:\n");
    printf("1. Asset ID\n");
    printf("2. Name\n");
    printf("3. Type\n");
    printf("4. Department\n");
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
        printf("Enter Asset ID: ");
        if (scanf("%d", &id) != 1) {
            clearBuffer();
            printf("Invalid ID.\n");
            return;
        }
        clearBuffer();

        for (int i = 0; i < count; i++) {
            if (assets[i].id == id) {
                printf("\n--- Asset Found ---\n");
                printf("ID: %d\nName: %s\nType: %s\nValue: N$%.2f\nDept: %s\nCondition: %s\n",
                       assets[i].id, assets[i].name, assets[i].type,
                       assets[i].purchaseValue, assets[i].department, assets[i].condition);
                found = 1;
                break;
            }
        }
    } else if (choice == 2 || choice == 3 || choice == 4) {
        char search[50];
        if (choice == 2) printf("Enter Name (or part): ");
        else if (choice == 3) printf("Enter Type: ");
        else printf("Enter Department: ");
        readString(search, 50);

        for (int i = 0; i < count; i++) {
            int match = 0;
            if (choice == 2 && strstr(assets[i].name, search) != NULL) match = 1;
            if (choice == 3 && (strcmp(assets[i].type, search) == 0 ||
                                strstr(assets[i].type, search) != NULL)) match = 1;
            if (choice == 4 && (strcmp(assets[i].department, search) == 0 ||
                                strstr(assets[i].department, search) != NULL)) match = 1;

            if (match) {
                printf("\n--- Asset Found ---\n");
                printf("ID: %d\nName: %s\nType: %s\nValue: N$%.2f\nDept: %s\nCondition: %s\n",
                       assets[i].id, assets[i].name, assets[i].type,
                       assets[i].purchaseValue, assets[i].department, assets[i].condition);
                found = 1;
            }
        }
    } else {
        printf("Invalid search option.\n");
        return;
    }

    if (!found) {
        printf("\nNo matching asset found.\n");
    }
}

void assetMenu(Asset assets[], int *count) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("         ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
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
            case 1: addAsset(assets, count); break;
            case 2: displayAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}
