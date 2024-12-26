#include "banking.h"

void add() {
    char c;
    struct record rec;
    FILE *f;
    //ab = append binary
    f = fopen("record.bin", "ab");
    int i = 0, x;
    // first we evaluate body and check condition
    do {

        system("CLS");
        gotoxy(24, 4);
        printf("\t\t\tCUSTOMER ACCOUNT REGISTRATION");
        gotoxy(36, 8);
        printf("[1] . Enter Your Name           : ");
        scanf(" %[^\n]", rec.name);
        gotoxy(36, 9);
        printf("[2] . Enter Your Account Number : ");
        scanf(" %d", &rec.account);

        gotoxy(36, 10);
        printf("[3] . Enter Your Phone Number   : ");
        scanf(" %[^\n]", rec.phone);
        gotoxy(36, 11);
        printf("[4] . Enter Your Address        : ");
        scanf(" %[^\n]", rec.address);
        gotoxy(36, 12);
        printf("[5] . Enter Your E-mail         : ");
        scanf(" %[^\n]", rec.email);
        gotoxy(36, 13);
        printf("[6] . Enter Your Citizenship No.: ");
        scanf(" %[^\n]", rec.citiz);
        gotoxy(36, 14);
        printf("[7] . Enter Amount To Deposit   : $");
        scanf(" %lf", &rec.blnc);
        for (r = 0; r < 10; r++) {
            rec.UserID[r] = rand() % 10;
            // rand() is used to generate random digits between 0 and 99 .
        }
        //fwrite() = for writing binary data
        //This helps to write contents in a structure variable in the file and stores it in the variable rec.
        fwrite(&rec, sizeof(rec), 1, f);
        //for 1-writing one block of data, and each block is of size sizeof(rec)
        gotoxy(38, 17);
        printf("CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL");
        i++;
        gotoxy(36, 19);
        printf("Do You Want To Add Another Record ? (Y/N) : ");
        scanf(" %c", &c);
    }
    while (c=='Y'|| c=='y');
    fclose(f);
    gotoxy(40, 22);
    printf("Press any key to return back to main menu. ");
    char z = getch();
    if (z == 13) {
        // ASCII value of ENTER is 13.
        menu();
    }

}

//module to check whether the entered account is in the database or not
int chkacc(int a) {
    FILE *f;
    f = fopen("record.bin", "rb");
    //check whether we have reached end of file or not
    while (!feof(f)) {
        // feof means loop terminate upto end of file
        fread(&rec, sizeof(rec), 1, f);

        if (a == rec.account) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

// module for editing details.
void edit() {
    FILE *x, *y;
    int a, c;
// colon i.e ":" acts as id for goto function
re:
    gotoxy(48, 4);
    printf(" EDIT CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Enter Your Account Number To Edit : ");
    scanf("%d", &a);
    if (chkacc(a) == 1){
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        while (fread(&rec, sizeof(rec), 1, x)) {
            if (rec.account != a)
                fwrite(&rec, sizeof(rec), 1, y);
            else if (rec.account == a) {
                gotoxy(52, 21);
                printf("Account Number Matched.");
                gotoxy(51, 10);
                printf("Enter Your Details");
                gotoxy(31, 12);
                printf("[1] . Enter Your Name           : ");
                scanf(" %[^\n]", rec.name);
                gotoxy(31, 13);
                printf("[2] . Enter Your Account Number : ");
                scanf(" %d", &rec.account);
                gotoxy(31, 14);
                printf("[3] . Enter Your Phone Number   : ");

                scanf(" %[^\n]", rec.phone);
                gotoxy(31, 15);
                printf("[4] . Enter Your Address        : ");
                scanf(" %[^\n]", rec.address);
                gotoxy(31, 16);
                printf("[5] . Enter Your E-mail         : ");
                scanf(" %[^\n]", rec.email);
                gotoxy(31, 17);
                printf("[6] . Enter Your Citizenship No : ");
                scanf(" %[^\n]", rec.citiz);
                fwrite(&rec, sizeof(rec), 1, y);

            }
        }
        fclose(x);
        fclose(y);
    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(52, 21);
        printf("Account Doesn't Exist. ");
        goto re;
    }
    remove("record.bin");
    rename("new.bin","record.bin");
    gotoxy(45, 21);
    printf("CUSTOMER ACCOUNT  IS UPDATE SUCCESSFULL");
    gotoxy(42, 24);
    printf("Press any key to return back to main menu.");
    getch();
    menu();
}


void del() {
    FILE *x, *y;
    int a, c;
re:
    gotoxy(48, 4);
    printf("DELETE THE CUSTOMER ACCOUNT");
    gotoxy(41, 9);
    printf("Enter Your Account Number To Delete : ");
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        x = fopen("record.bin", "rb");
        y = fopen("new.bin", "wb");
        while (fread(&rec, sizeof(rec), 1, x)) {
            if (rec.account != a)
                fwrite(&rec, sizeof(rec), 1, y);
        }

        fclose(x);
        fclose(y);
        x = fopen("record.bin", "wb");
        y = fopen("new.bin", "rb");
        while (fread(&rec, sizeof(rec), 1, y))
            fwrite(&rec, sizeof(rec), 1, x);
        fclose(x);
        fclose(y);
    } else if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(51, 15);
        printf("Account Doesn't Exist");

        goto re;
    }
    gotoxy(44, 15);
    printf("CUSTOMER ACCOUNT DELETED SUCCESSFULLY");
    gotoxy(42, 18);
    printf("Press any key to return back to main menu. ");
    getch();
    menu();
}

//module for searching account ( 2 types by number and name )
void search() {
    system("cls");
    int a;
    gotoxy(55, 4);
    printf(" SEARCH MENU ");
    gotoxy(49, 10);
    printf("[1] . Search By Account ");
    gotoxy(49, 12);
    printf("[2] . Search By Name ");
    gotoxy(47, 17);
    printf("Enter Your Choice [1-2] : ");
    scanf("%d", &a);
    system("cls");
    if (a == 1) {
        search_acc();
    } else if (a == 2) {
        search_name();
    } else
        menu();
}

// search by search_account number.
void search_acc() {
    FILE *f;
    int a, x;
re:

    gotoxy(48, 4);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Enter Your Account Number To Search : ");
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f = fopen("record.bin", "rb");
        while (fread(&rec, sizeof(rec), 1, f)) {
            if (rec.account == a) {
                gotoxy(52, 21);
                printf("Account Number Matched. User is Active.");
                gotoxy(45, 10);
                printf("Detail Information of %s", strupr(rec.name));

                // strupr-convert a string to uppercase.
                gotoxy(37, 12);
                printf("[1] . Account Number : %d", rec.account);
                gotoxy(37, 13);
                printf("[2] . Name           : %s", rec.name);
                gotoxy(37, 14);
                printf("[3] . UserID         : ");
                for (r = 0; r < 10; r++) {
                    printf("%d", rec.UserID[r]);
                }
                gotoxy(37, 15);
                printf("[4] . Phone Number   : %s", rec.phone);
                gotoxy(37, 16);
                printf("[5] . Address        : %s", rec.address);
                gotoxy(37, 17);
                printf("[6] . E-mail         : %s", rec.email);
                gotoxy(37, 18);
                printf("[7] . Citizenship No : %s", rec.citiz);
                gotoxy(37, 19);
                printf("[8] . Current Balance: $%.2lf", rec.blnc);
                break;
            }
        }
        fclose(f);
    }
    if(chkacc(a) == 0){
        system("CLS");
        gotoxy(52, 21);
        printf("Account Doesn't Exist. User is Inactive. ");
        goto re;
    }

    gotoxy(42, 24);
    printf("Press [ENTER] to return back to main menu. ");
    char z = getch();
    if (z == 13)

        menu();
    else
        search();
}

//for search by search_name. 
void search_name() {
    int i = 0, b, x;
    char nam[30];
    gotoxy(48, 4);
    printf(" SEARCH CUSTOMER ACCOUNT ");
    gotoxy(43, 7);
    printf("Enter Your Full Name To Search : ");
    scanf(" %[^\n]", nam);

    FILE *f;
    f = fopen("record.bin", "rb");
    while (fread(&rec, sizeof(rec), 1, f)) {
        b = 0;
        strupr(rec.name);
        strupr(nam);
        if (strcmp(rec.name, nam) == 0) {
            gotoxy(52, 21);
            printf("Account Number Matched. User is Active.");
            gotoxy(45, 10);
            printf("Detail Information of %s", rec.name);
            gotoxy(37, 12);
            printf("[1] . Account Number : %d", rec.account);
            gotoxy(37, 13);
            printf("[2] . Name           : %s", rec.name);
            gotoxy(37, 14);
            printf("[3] . UserID         : ");
            for (r = 0; r < 10; r++) {
                printf("%d", rec.UserID[r]);
            }
            gotoxy(37, 15);
            printf("[4] . Phone Number   : %s", rec.phone);
            gotoxy(37, 16);
            printf("[5] . Address        : %s", rec.address);
            gotoxy(37, 17);
            printf("[6] . E-mail         : %s", rec.email);
            gotoxy(37, 18);
            printf("[7] . Citizenship No : %s", rec.citiz);
            gotoxy(37, 19);
            printf("[8] . Current Balance: $%.2lf", rec.blnc);
            break;
        } else
            b = 1;
    }
    fclose(f);

    if (b == 1) {
        system("cls");
        gotoxy(52, 21);
        printf("Accozunt Doesn't Exist. User is Inactive.");
        search_name();
    }
    gotoxy(42, 24);
    printf("Press [ENTER] to return back to main menu. ");
    char z = getch();
    if (z == 13)
        menu();
    else
        search();
}
