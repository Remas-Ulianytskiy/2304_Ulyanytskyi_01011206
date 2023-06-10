#include <iostream>

using namespace std;

double get_user_value();
double profit_calculation(double amount, double interest, int time, double tax);


int main()
{    
    int time;
    double deposit_amount, interest_rate, profit, tax_rate;
    const double default_tax_rate = 0.805;

    cout << "Enter the deposit amount in UAH: ";
    deposit_amount = get_user_value();

    cout << "Enter the interest rate: ";
    interest_rate = get_user_value();

    cout << "Enter the time in months: ";
    time = get_user_value();

    cout << "Enter the tax coefficient (enter 0 for default value 0.805): ";
    tax_rate = get_user_value();

    if (tax_rate <= 0) {
        tax_rate = default_tax_rate;
    }        

    profit = profit_calculation(deposit_amount, interest_rate, time, tax_rate);
    cout << "Deposit profit is: " << profit << " UAH";

    return 0;
}

double get_user_value() {
    double value;
    cin >> value;
    return value;
}

double profit_calculation(double amount, double interest, int time, double tax) {
    return amount * interest / 100 * time / 12 * tax;
}