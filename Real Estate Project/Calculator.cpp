#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>

class realEstate
{
private:
    string address;
    long long buyingPrice;
    int rent;
    double onePercent;
    long moneyInvested;
    

public:
    realEstate() {address = "None", buyingPrice = 0, rent = 0, onePercent = 0.00;}
    realEstate(string a, long long bp, int r)
    {
        address = a;
        buyingPrice = bp;
        rent = r;
    }
    string getAddress() { return address; }
    long getBuyingPrice() { return buyingPrice; }
    int getRent() { return rent; }
    void onePercentRule();
    string onePercentRule(long bp, int r)
    {
        buyingPrice = bp;
        rent = r;
        double onePercentNumber = 0.01;
        double onePercent = buyingPrice * onePercentNumber;
        if(onePercent > rent)
            return "No";
        return "Yes";
    }

    double cashOnCashReturn(int cashFlowMonthly, int buyingPrice, double downPaymentP, double closingCost, int repairs) {
        int fullMonth = 12;
        int yearlyCashFlow = cashFlowMonthly * fullMonth;
        double downPaymentPercentage = downPaymentP/100;
        int downPaymentCashInvested = downPaymentPercentage * buyingPrice;
        long closingCostTotal = closingCost * buyingPrice;
        int cashInvestment = downPaymentCashInvested + repairs + closingCostTotal;
        double cashOnCash = yearlyCashFlow / (double)(cashInvestment)* 100;
        cout << fixed << setprecision(2);
        return cashOnCash;
    }

    void setAddress(string x) {
        address = x;
    }
    void setBuyingPrice(long y) {
        buyingPrice = y;
    }
    void setRent(int z) {
        rent = z;
    }
};

int main()
{   
    string address;
    int buyingPrice;
    int rent;
    int cashFlowMonthly;
    int downPayment;
    double closingCostPercent = 0.05;
    int repairCost;

    // Mortgage Calculator Variables
    // double annualInterestRate;
    // double loanAmount;
    // double monthlyInterestRate;
    // double numberOfPayments;
    // double totalPayBack;
    // double monthlyPayment;

    cout << "Address: ";
    getline(cin,address);
    cout << "Buying Price: ";
    cin >> buyingPrice;
    cout << "Down Payment Percentage: ";
    cin >> downPayment;
    std::cout << "Repair Cost: ";
    std::cin >> repairCost;
    cout << "Rent Monthly: ";
    cin >> rent;
    std::cout << "Cashflow Monthly: ";
    std::cin >> cashFlowMonthly;

    realEstate firstHome;
    firstHome.setAddress(address);
    firstHome.setBuyingPrice(buyingPrice);
    firstHome.setRent(rent);
    
    std::cout <<"\n";
    std::cout << "================================================" << std::endl;
    std::cout << "Real Estate Calculator Created By Austin Nguyen" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "Address: " << firstHome.getAddress() << std::endl;
    std::cout << "\n";
    std::cout << "Buying Price: " << firstHome.getBuyingPrice() << std::endl;
    std::cout << "\n";
    std::cout << "Rent: " << firstHome.getRent() << std::endl;
    std::cout << "\n";
    std::cout << "Does It Pass One Percent Rule? " << firstHome.onePercentRule(buyingPrice,rent) << std::endl;
    std::cout << "\n";
    std::cout << "Cash On Cash Return: " << firstHome.cashOnCashReturn(cashFlowMonthly,buyingPrice,downPayment,closingCostPercent,repairCost) << + "%" << std::endl;
    std::cout << "\n";
    std::cout << "================================================" << std::endl;
    std::cin.clear();
    


}