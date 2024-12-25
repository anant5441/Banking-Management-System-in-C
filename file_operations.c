#include "banking.h"

int chkacc(int account) {
    FILE *f;
    int found = 0;

    f = fopen("record.bin", "rb");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fread(&rec, sizeof(rec), 1, f)) {
        if (rec.account == account) {
            found = 1;
            break;
        }
    }
    fclose(f);
    return found;  // Returns 1 if found, 0 otherwise
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x); // Moves cursor to position (x, y)
}

// You can define other functions to handle file opening, writing, etc. here
