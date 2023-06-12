#include <iostream>
#include <string>

using namespace std;

const double DEFAULT_TAX_RATE = 0.805;

double get_user_value() {
    double value;
    cin >> value;
    return value;
}

double profit_calculation(double amount, double interest, int time, double tax = DEFAULT_TAX_RATE) {
    return amount * interest / 100 * time / 12 * tax;
}

void print_msg(string msg, short mod = 0, double res = 0) {
    switch (mod)
    {
    case 0:
        cout << msg;
        break;
    case 1:
        cout << msg << res;
        break;
    default:
        break;
    }
}

int main()
{    
    int time;
    double deposit_amount, interest_rate, profit, tax_rate;

    string msg_deposit = "Enter the deposit amount in UAH: ";
    string msg_interest = "Enter the interest rate: ";
    string msg_time = "Enter the time in months: ";
    string msg_tax = "Enter the tax coefficient(enter 0 for default value " + to_string(DEFAULT_TAX_RATE) + "): ";
    string msg_result = "Deposit profit in UAH is: ";
    string msg_error = "Error";

    print_msg(msg_deposit);
    deposit_amount = get_user_value();

    print_msg(msg_interest);
    interest_rate = get_user_value();

    print_msg(msg_time);
    time = get_user_value();

    print_msg(msg_tax);
    tax_rate = get_user_value();

    if (tax_rate <= 0) {
        profit = profit_calculation(deposit_amount, interest_rate, time);
        print_msg(msg_result, 1, profit);
    }
    else if (tax_rate > 0)
    {
        profit = profit_calculation(deposit_amount, interest_rate, time, tax_rate);
        print_msg(msg_result, 1, profit);
    }
    else {
        print_msg(msg_error);
    }

    return 0;
}