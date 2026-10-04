#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 50
#define ASSET_NAME_LEN 50
#define ASSET_TYPE_LEN 30
#define ASSET_DEPT_LEN 30
#define CONDITION_LEN 20

typedef struct {
    int id;
    char name[ASSET_NAME_LEN];
    char type[ASSET_TYPE_LEN];
    float purchaseValue;
    char department[ASSET_DEPT_LEN];
    char condition[CONDITION_LEN];
} Asset;

void assetMenu(Asset assets[], int *count);
void addAsset(Asset assets[], int *count);
void displayAssets(Asset assets[], int count);
void searchAsset(Asset assets[], int count);

#endif
