# Simple Banking Management System

A simple banking management system written in C, which allows users to perform basic banking operations like creating accounts, updating details, balance inquiries, deposits, and withdrawals.

## Features

- **Account Creation:** Ability to add new customer accounts to the system.
- **Account Search:** Search customer accounts by account number or name.
- **Balance Inquiry:** Check the current balance of an account.
- **Cash Deposit:** Deposit money into a customer account.
- **Cash Withdrawal:** Withdraw money from a customer account.
- **Account Update:** Update details of customer accounts like name, address, phone, etc.
- **Account Deletion:** Ability to delete accounts from the system.
- **Admin Features:** Admin functionalities for managing accounts.

## Algorithm

### Steps in the Banking System

1. **Account Creation**
   - The system prompts the user for necessary details like name, account number, address, phone number, email, and citizenship number.
   - User information is saved to a binary file (`record.bin`).

2. **Searching Accounts**
   - The user can search for an account by either account number or customer name.
   - If the account is found, details of the customer are displayed.

3. **Deposit & Withdrawal**
   - Users can deposit or withdraw money from their accounts.
   - If a withdrawal amount exceeds the balance, the system will notify the user of insufficient funds.

4. **Update and Delete Accounts**
   - Customer details like address, phone number, and email can be updated.
   - Customers can also be deleted from the system.

### Functions:
- **deposit():** Adds money to the selected account.
- **withdrawl():** Subtracts money from the selected account.
- **chkblnc():** Displays the current account balance.
- **search():** Allows searching by account number or name.
- **update():** Updates an existing account with new details.
- **del():** Deletes an existing customer account.

---

## How to Use

1. **Running the Program**
   - After compiling and running the code, the program will present a main menu.
   - You can choose different options such as account operations, transactions, or searching for an account.

2. **Available Operations**
   - **Account Creation**: Select option to create a new account.
   - **Search**: Search for customer details by account number or name.
   - **Deposit**: Deposit a specified amount into an account.
   - **Withdraw**: Withdraw a specified amount from an account (ensures sufficient funds).
   - **Account Update**: Modify existing customer details.
   - **Account Deletion**: Remove a customer account from the system.
   - **Transaction Inquiry**: Check your current balance.

3. **Example**
   - Upon choosing the **Create New Account** option, the user is prompted for details like name, address, phone, and email. Once the details are entered, they are saved to the binary file.
   - For checking balance, after entering the account number, it displays the current balance if the account exists.

---

## Passwords 

> If you implement user authentication, the program can require users to enter a password to access their account. 
For **Administration** username-**ab** and password-**ab**
for **Customer** username-**user** and password-**user**

---

## Challenges

1. **Data Integrity**: Ensuring that data integrity is maintained when handling binary files (ensuring no data loss occurs in account information when performing operations).
2. **Error Handling**: Proper error handling for user input, file operations, and balance checks.
3. **Multi-threading**: The system can be enhanced by handling simultaneous requests for a more scalable system.
4. **File Locking**: Adding file locking mechanisms to prevent simultaneous file access, ensuring data consistency.

---

## Future Enhancements

1. **Encryption of Account Data**: To ensure that sensitive user data, such as account balances and personal details, are encrypted before storing them in files.
2. **Graphical User Interface (GUI)**: Transition to a GUI framework for better user interaction.
3. **Networking**: Incorporate a network layer allowing the system to run across multiple machines.
4. **User Authentication**: Implement a secure login mechanism with hashed passwords.
5. **Database Support**: Use a SQL/NoSQL database instead of flat files for data management to support higher scalability.

---

banking_system_project/
│
├── banking.h              # Header file with structures and prototypes
├── main.c                 # Main program that includes menu logic
├── file_operations.c      # File management functions
├── account_operations.c   # Account-related operations
├── transaction_operations.c # Transaction-related functions
└── Makefile               # Makefile to handle compilation (optional)

Here we give mutiple files to understand easily and Also give a complete file of full code


---


## Author

This project was created by **Anant Bhardwaj**, a developer passionate about building simple yet efficient systems.

For any queries or improvements, feel free to contact via email.

---

## License

This project is open source and available under the **MIT License**.


