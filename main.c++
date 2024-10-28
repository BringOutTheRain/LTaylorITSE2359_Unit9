#include <iostream>
#include "bank_account.h"

void processWithdrawal(BankAccount& account, double amount) {
    account.withdraw(amount);
}

int main() {
    try {
        BankAccount myAccount("12345", 100.0);

        std::cout << "Initial balance: $" << myAccount.getBalance() << std::endl;

        myAccount.deposit(50);
        processWithdrawal(myAccount, 200);

    } catch (const InsufficientFunds& e) {
        std::cout << e.what() << std::endl;
    } catch (const NegativeDeposit& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "An unexpected error occurred." << std::endl;
    }

    std::cout << "Program completed." << std::endl;
    return 0;
}
