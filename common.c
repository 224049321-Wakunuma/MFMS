#include "common.h"

void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(char *str, int size) {
    if (fgets(str, size, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        } else {
            clearBuffer();
        }
    }
}

int isEmpty(const char *str) {
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
