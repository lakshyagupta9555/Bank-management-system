#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
struct Account {
    int accountNumber;
    char name[100];
    float balance;
};

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void menu();

// Global variables
struct Account accounts[100];  // Array to store up to 100 accounts
int totalAccounts = 0;

int main() {
    menu();
    return 0;
}

// Function to display the menu
void menu() {
    int choice;
    while (1) {
        printf("\n==== Bank Management System ====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Thank you for using the Bank Management System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to create a new account
void createAccount() {
    printf("\n==== Create New Account ====\n");
    printf("Enter account number: ");
    scanf("%d", &accounts[totalAccounts].accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", accounts[totalAccounts].name);
    accounts[totalAccounts].balance = 0.0f;  // New accounts start with a zero balance
    totalAccounts++;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void depositMoney() {
    int accNo;
    float amount;
    printf("\n==== Deposit Money ====\n");
    printf("Enter account number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accNo;
    float amount;
    printf("\n==== Withdraw Money ====\n");
    printf("Enter account number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! Current balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to check the balance of an account
void checkBalance() {
    int accNo;
    printf("\n==== Check Balance ====\n");
    printf("Enter account number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNo) {
            printf("Account holder: %s\n", accounts[i].name);
            printf("Current balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}
