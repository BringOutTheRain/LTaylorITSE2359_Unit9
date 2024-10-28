#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <exception>
#include <string>

class InsufficientFunds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient funds for this withdrawal.";
    }
};

class NegativeDeposit : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Deposit amount cannot be negative.";
    }
};

class BankAccount {
private:
    double balance;
    std::string accountNumber;

public:
    BankAccount(std::string accNo, double initialBalance)
        : accountNumber(accNo), balance(initialBalance) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();
        }
        balance -= amount;
        std::cout << "Successfully withdrew: $" << amount << std::endl;
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw NegativeDeposit();
        }
        balance += amount;
        std::cout << "Successfully deposited: $" << amount << std::endl;
    }

    double getBalance() const {
        return balance;
    }
};

#endif
