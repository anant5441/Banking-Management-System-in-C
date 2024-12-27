#include "banking.h"


void chkblnc() {
    FILE *f;
    int a;

    gotoxy(48, 4);
    printf(" BALANCE INQUIRY ");
    gotoxy(47, 12);
    printf("Enter Your Account Number : ");
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f = fopen("record.bin", "rb");
        while (fread(&rec, sizeof(rec), 1, f)) {
            if (rec.account == a) {
                gotoxy(50, 15);
                printf("Your Balance is : $%.2lf", rec.blnc);
            }
        }
        fclose(f);
    }
    if (chkacc(a) == 0) {
        system("cls");
        gotoxy(52, 15);
        printf("Account Doesn't Exist.");
        chkblnc();
    }
    gotoxy(46, 21);
    printf("Press any key to return back to main menu. ");
    getch();
    transaction();
}

// module for adding amount to a account
void deposit(){
    int a;
    double b;
    FILE *x, *y;
    gotoxy(54, 4);

    printf(" CASH DEPOSIT ");
    gotoxy(47, 10);
    printf("Enter Your Account Number : ");
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        while (fread(&rec, sizeof(rec), 1, x)) {
            if (rec.account != a)
                fwrite(&rec, sizeof(rec),1, y);
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;

                gotoxy(45, 13);
                printf("Enter The Amount To Deposit : $ ");
                scanf("%lf", &b);
                rec.blnc += b;
                gotoxy(45,23);
                printf("THE TOTAL AMOUNT IN THE ACCOUNT:%.3lf",rec.blnc);
                fwrite(&rec, sizeof(rec), 1, y);
            }
        }
        fclose(x);
        fclose(y);

        x = fopen("record.bin", "wb");
        y = fopen("new.bin", "rb");
        while (fread(&rec, sizeof(rec), 1, y))
            fwrite(&rec, sizeof(rec), 1, x);
        fclose(x);
        fclose(y);
    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(52, 21);
        printf("Account Doesn't Exist. ");
        gotoxy(41, 22);
        deposit();
    }
    gotoxy(52, 21);
    printf("CASH DEPOSIT SUCCESSFULL");
    gotoxy(50, 24);
    printf("Press any key to return back...");
    getch();
    transaction();

}

// module to withdraw amount from account
void withdrawl() {
    FILE *x, *y;
    int a;
    double b, z;
    gotoxy(54, 4);
    printf(" CASH WITHDRAWAL ");
    gotoxy(45, 10);
    printf("Enter Your Account Number : ");
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        gotoxy(42, 13);
        printf("Enter The Amount To Withdraw : $ ");
        scanf("%lf", &b);

        while (fread(&rec, sizeof(rec), 1, x)) {
            if (rec.account != a)
                fwrite(&rec, sizeof(rec), 1, y);
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                z = rec.blnc;
                if (b <= rec.blnc) {
                    rec.blnc -= b;
                    gotoxy(44, 21);
                    printf("    CASH WITHDRAWAL SUCCESSFULL     ");
                }
                fwrite(&rec, sizeof(rec), 1, y);
            }
        }
        fclose(x);
        fclose(y);
        remove("record.bin");
        rename("new.bin", "record.bin");
        if (z < b) {
            system("CLS");
            gotoxy(48, 21);
            printf("Current Balance is $%.2lf", z);
            gotoxy(42, 24);
            printf("Entered amount exceeds current balance");
            withdrawl();
        }

    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(50, 21);
        printf("Account Doesn't Exist.");
        gotoxy(39, 22);
        withdrawl();
    }
    gotoxy(42, 24);
    printf("     Press Any Key To Continue ....   ");
    getch();
    transaction();
}

//module for logging out of the program.
void menuexit() {
    system("cls");
    gotoxy(48, 10);
    printf("!!! THANK YOU !!!");

    gotoxy(50, 12);
    printf("USER :: %s");
    getch();
    gotoxy(0, 26);
    exit(0);
}

//module for know about Developer.
void about() {
    gotoxy(48,10);
    printf("!!!WANNA KNOW US!!!");
    gotoxy(33,12);
    printf("Project developer name:-");
    gotoxy(46,14);
    printf("Anant Bhardwaj");
    gotoxy(40,20);
    printf("It is a Simple Bank Management System ");
    gotoxy(40, 22);
    printf("Press any key to return back to main menu. ");
    char z = getch();
    if (z == 13) {
        menu();
    }
}