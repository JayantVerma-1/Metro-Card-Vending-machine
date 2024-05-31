#include <iostream>
#include <iomanip>

using namespace std;

class MetroCard //Class to represent the metro card
{
private:
    double balance;

public:
    MetroCard() : balance(0) {}

    // Method to recharge the metro card
    void recharge(double amount)
    {
        balance += amount;
        cout << "Recharge successful. New balance: $" << fixed << setprecision(2) << balance << endl;
    }

    // Method to display current balance
    void displayBalance()
    {
        cout << "Current balance: Rs" << fixed << setprecision(2) << balance << endl;
    }
};

// VendingMachine class to handle the recharge process
class VendingMachine
{
public:
    // Method to display recharge options
    void displayOptions()
    {
        cout << "Metro Card Recharge" << endl;
        cout << "1. Rs50" << endl;
        cout << "2. Rs100" << endl;
        cout << "3. Rs200" << endl;
        cout << "4. Rs500" << endl;
        cout << "5. Cancel" << endl;
    }

    // Method to recharge the metro card based on user choice
    void rechargeCard(MetroCard &card, int choice)
    {
        double amount = 0;
        switch (choice)
        {
        case 1:
            amount = 50.0;
            break;
        case 2:
            amount = 100.0;
            break;
        case 3:
            amount = 200.0;
            break;
        case 4:
            amount = 500.0;
            break;
        default:
            cout << "Invalid choice. Transaction cancelled." << endl;
            return;
        }
        card.recharge(amount);
    }
};

int main()
{
    MetroCard card;
    VendingMachine vendingMachine;
    int choice;

    while (true)
    {
        cout << "Welcome to Metro Card Recharge Vending Machine" << endl;
        vendingMachine.displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            vendingMachine.rechargeCard(card, choice);
        }
        else if (choice == 5)
        {
            cout << "Transaction cancelled." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        card.displayBalance();

        char proceed;
        cout << "Do you want to perform another transaction? (Y/N): ";
        cin >> proceed;
        if (proceed != 'Y' && proceed != 'y')
        {
            cout << "Thank you for using Metro Card Recharge Vending Machine." << endl;
            break;
        }
    }

    return 0;
}
