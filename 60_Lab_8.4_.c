// Account with Dynamic Balance.
/*
struct Account {
long accNo;
char holder[50];
double *balance;
char type[15];
};
Simulate deposit using pointer to balance.*/

#include <stdio.h>
#include <stdlib.h>

struct Account {
    long accNo;
    char holder[50];
    double *balance;   // Dynamically allocated
    char type[15];
};

// Function to simulate deposit
void deposit(struct Account *acc, double amount) {
    if (acc->balance != NULL) {
        *(acc->balance) += amount;
        printf("Deposited %.2lf successfully.\n", amount);
    } else {
        printf("Balance pointer is NULL.\n");
    }
}

int main() {
    struct Account acc;

    // Input account details
    printf("Enter Account Number: ");
    scanf("%ld", &acc.accNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc.holder);

    printf("Enter Account Type: ");
    scanf(" %[^\n]", acc.type);

    // Allocate memory for balance
    acc.balance = (double*)malloc(sizeof(double));
    if (acc.balance == NULL) {
        printf("Memory allocation failed for balance.\n");
        return 1;
    }

    printf("Enter Initial Balance: ");
    scanf("%lf", acc.balance);

    // Simulate deposit
    double depositAmount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &depositAmount);
    deposit(&acc, depositAmount);

    // Display updated account info
    printf("\n--- Account Summary ---\n");
    printf("Account No: %ld\n", acc.accNo);
    printf("Holder: %s\n", acc.holder);
    printf("Type: %s\n", acc.type);
    printf("Balance: %.2lf\n", *(acc.balance));

    // Free allocated memory
    free(acc.balance);

    return 0;
}
