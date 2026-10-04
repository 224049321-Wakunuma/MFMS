#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50
#define SUP_NAME_LEN 50
#define EMAIL_LEN 50
#define PHONE_LEN 20
#define TOWN_LEN 30

typedef struct {
    int id;
    char name[SUP_NAME_LEN];
    char email[EMAIL_LEN];
    char phone[PHONE_LEN];
    char town[TOWN_LEN];
} Supplier;

void supplierMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(Supplier suppliers[], int count);
void searchSupplier(Supplier suppliers[], int count);

#endif
