#include "banking.h"  // Include the header file

// Declare the customer record as global (as per your provided code)
struct customer rec;
#include "banking.h"

// Example menu function (assuming it's inside main.c or another file)
void menu() {
    int choice;
    printf("Welcome to the Banking System\n");
    printf("1. Account Operations\n");
    printf("2. Transaction Operations\n");
    printf("3. About\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Call account management operations (update, del, search)
            break;
        case 2:
            // Call transaction operations (deposit, withdrawl, chkblnc)
            break;
        case 3:
            about();  // Example: display about the system
            break;
        case 4:
            exit(0);  // Exit the program
        default:
            printf("Invalid choice.\n");
            menu();  // Recursively call menu for invalid input
    }
}

int main() {
    menu();
    return 0;
}
