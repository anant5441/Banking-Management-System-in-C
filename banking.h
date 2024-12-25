#ifndef BANKING_H
#define BANKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for customer record
struct customer {
    int account;
    char name[30];
    int UserID[10];
    char phone[15];
    char address[100];
    char email[50];
    char citiz[20];
    double blnc;
};

extern struct customer rec;  // Declaration for global customer record

// Function prototypes
void menu();
void chkblnc();
void deposit();
void withdrawl();
void about();
void search();
void search_acc();
void search_name();
void update();
void del();
void transaction();
int chkacc(int account);
void gotoxy(int x, int y);

#endif // BANKING_H
