#include <stdio.h>
#include <stdlib.h>

struct BankAccount {
    char account_number[20];
    char account_holder[50];
    double balance;
};

typedef struct BankAccount BankAccount;

void createAccount(BankAccount *account, const char *account_number, const char *account_holder, double initial_balance) {
    snprintf(account->account_number, sizeof(account->account_number), "%s", account_number);
    snprintf(account->account_holder, sizeof(account->account_holder), "%s", account_holder);
    account->balance = initial_balance;
}

int deposit(BankAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        return 1;
    }
    return 0;
}

int withdraw(BankAccount *account, double amount) {
    if (amount > 0 && account->balance >= amount) {
        account->balance -= amount;
        return 1;
    }
    return 0;
}

double checkBalance(BankAccount *account) {
    return account->balance;
}

typedef struct SavingsAccount {
    BankAccount account;
    double interest_rate;
} SavingsAccount;

void createSavingsAccount(SavingsAccount *account, const char *account_number, const char *account_holder, double initial_balance, double interest_rate) {
    createAccount(&account->account, account_number, account_holder, initial_balance);
    account->interest_rate = interest_rate;
}

double calculateInterest(SavingsAccount *account) {
    double interest = account->account.balance * account->interest_rate;
    account->account.balance += interest;
    return interest;
}

int main() {
    
    SavingsAccount savings_account;
    createSavingsAccount(&savings_account, "12345", "John Doe", 1000.0, 0.03);

    
    deposit(&savings_account.account, 500.0);
    withdraw(&savings_account.account, 200.0);

   
    double interest = calculateInterest(&savings_account);
    printf("Interest Earned: $%.2lf\n", interest);

   
    double balance = checkBalance(&savings_account.account);
    printf("Current Balance: $%.2lf\n", balance);

    return 0;
}
