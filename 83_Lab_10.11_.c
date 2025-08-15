// Add interest to Account passed by address.

#include <stdio.h>

// Define Account structure
struct Account {
    int accountNo;
    char holderName[50];
    float balance;
};

// Function to add interest (pass by address)
void addInterest(struct Account *acc, float rate) {
    acc->balance += acc->balance * (rate / 100.0f);
}

int main() {
    struct Account acc;

    // Input account details
    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc.holderName);

    printf("Enter Current Balance: ");
    scanf("%f", &acc.balance);

    // Input interest rate
    float interestRate;
    printf("\nEnter Interest Rate (%%): ");
    scanf("%f", &interestRate);

    // Add interest
    addInterest(&acc, interestRate);

    // Display updated account
    printf("\n--- Updated Account ---\n");
    printf("Account No: %d\n", acc.accountNo);
    printf("Holder Name: %s\n", acc.holderName);
    printf("Balance after Interest: ₹%.2f\n", acc.balance);

    return 0;
}
