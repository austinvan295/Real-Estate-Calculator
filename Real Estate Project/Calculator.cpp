#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

class realEstate {
private:
    string address;
    long long buyingPrice;
    int rent;
    double onePercent;
    long moneyInvested;
    int cashFlowMonthly;
    

public:
    realEstate() {address = "None", buyingPrice = 0, rent = 0, onePercent = 0.00;} // Empty Constructor
    realEstate(string a, long long bp, int r) { // Overloaded Constructor
        address = a;
        buyingPrice = bp;
        rent = r;
    }
    string getAddress() { return address; }
    long getBuyingPrice() { return buyingPrice; }
    int getRent() { return rent; }
    int getCashFlow() {return cashFlowMonthly;}
    void onePercentRule();
    string onePercentRule(long bp, int r) {
        buyingPrice = bp;
        rent = r;
        double onePercentNumber = 0.01;
        double onePercent = buyingPrice * onePercentNumber;
        if(onePercent > rent)
            return "No";
        return "Yes";
    }

    double cashOnCashReturn(int cashFlowMonthly, int buyingPrice, double downPaymentP, double closingCostPercentage, int repairs, double closingCost) {
        int fullMonth = 12;
        int yearlyCashFlow = cashFlowMonthly * fullMonth;
        double downPaymentPercentage = downPaymentP/100;
        int downPaymentCashInvested = downPaymentPercentage * buyingPrice;
        long closingCostTotal = closingCostPercentage * buyingPrice + closingCost;
        int cashInvestment = downPaymentCashInvested + repairs + closingCostTotal + closingCost;
        double cashOnCash = yearlyCashFlow / (double)(cashInvestment) * 100;
        cout << fixed << setprecision(1);
        return cashOnCash;
    }

    double capRate(double cashFlowMonthly, double buyingPrice) {
        int cashFlowYearly = cashFlowMonthly * 12;
        double capR = cashFlowYearly / (double)(buyingPrice)* 100;
        cout << setprecision(1);
        return capR;
    }

    string worthInvesting(int capRate) {
        if(capRate >= 15)
            return "Yes";
        return "No";
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

    void setCashFlowMonthly(int a) {
        cashFlowMonthly = a;
    }

};

int main() {   
    string address;
    int buyingPrice; // The Price The Home Was Bought At
    int rent; // Rent Monthly
    int cashFlowMonthly; // Cashflow Monthly
    int downPayment; // Down Payment 
    double closingCostPercent = 0.05; // Change this because closing cost varies between transactions ranging from 3 - 6 % depending on your realtor
    int repairCost;
    int closingCost;



    double annualInterestRate; // Yearly Interest Rate
    double loanAmount; // The Amount Of The Loan
    double monthlyInterestRate; // Interest Rate Amount Monthly
    double numberofPayments; // The Amount Of Payments
    double totalYearsToRepay; // Years Needed To Payback
    double propertyTax; // Propertytax Monthly
    int homeOwnersInsurance; // Home Owners Insurance Monthly
    int hoa; // Home Owners Asosciation Monthly
    char ans; // Check to see if they would like to calculate Mortgage

    cout << "Calculate Mortgage? (Y/N): "; // If ans is N or n, it moves on to the Real Estate Calculator
    cin >> ans;

    if(ans == 'y' || ans == 'Y') {

    cout << "Enter the amount of the loan: ";
    cin >> loanAmount;

    cout << "Enter annual interest rate in decimal term: ";
    cin >> annualInterestRate;

    cout << "Enter the length of the loan in years: ";
    cin >> totalYearsToRepay;

    cout << "Property Tax (Monthly): ";
    cin >> propertyTax;

    cout <<"Home Owners Insurance (Monthly): ";
    cin >> homeOwnersInsurance;

    cout << "HOA (Monthly): ";
    cin >> hoa;

    loanAmount = loanAmount;

    cout << "loanAmount: $" << setprecision(2) << loanAmount << endl;

    annualInterestRate = annualInterestRate / 100;

    cout << "annualInterestRate: $" << setprecision(2) << annualInterestRate * 100 << "%" << endl;

    cout << "totalYearsToRepay: " << setprecision(0) << totalYearsToRepay << endl;

    monthlyInterestRate=annualInterestRate / 12; // Converts monthly interest rate to a percentage out of 100

    totalYearsToRepay = totalYearsToRepay; 

    numberofPayments = totalYearsToRepay* 12;

    double powerFactor = std::pow(1.0 + monthlyInterestRate, numberofPayments);
    double monthlyPayment = (loanAmount * monthlyInterestRate * powerFactor) / (powerFactor - 1.0) + (hoa + homeOwnersInsurance + propertyTax) ;

    cout << "Monthly Payment: $" << setprecision(2) << fixed << monthlyPayment << endl;
    cout << "\n";


    cin.ignore();
    cin.clear();
    }  
    char ansTwo;
    cout << "\n";
    cout << "Real Estate Analysis? (Y/N): ";
    cin >> ansTwo;

    if(ansTwo == 'Y' || ansTwo == 'y') {
    cin.ignore();
    cin.clear();

    cout << "\n";
    cout << "Address: ";
    getline(cin,address);
    cout << "Buying Price: ";
    cin >> buyingPrice;
    cout << "Down Payment Percentage: ";
    cin >> downPayment;
    cout << "Repair Cost: ";
    cin >> repairCost;
    cout <<"Closing Cost: ";
    cin >> closingCost;
    cout << "Rent Monthly: ";
    cin >> rent;
    cout << "Cashflow Monthly: ";
    cin >> cashFlowMonthly;

    realEstate firstHome;
    firstHome.setAddress(address);
    firstHome.setBuyingPrice(buyingPrice);
    firstHome.setRent(rent);
    int capRate = firstHome.capRate(cashFlowMonthly,buyingPrice);
    firstHome.setCashFlowMonthly(cashFlowMonthly);
    
    cout << fixed << setprecision(1) << endl;
    ofstream my_file("Houses.txt",std::ios::app);
    my_file << "Address: " << firstHome.getAddress() << endl;
    my_file << "Buying Price: " << firstHome.getBuyingPrice() << endl;
    my_file << "Rent: " << firstHome.getRent() << endl;
    my_file << "Cash Flow Monthly: " << firstHome.getCashFlow() << endl;
    my_file << "Does It Pass One Percent Rule: " << firstHome.onePercentRule(buyingPrice,rent) << endl;
    my_file << "Cash On Cash Return: " << firstHome.cashOnCashReturn(cashFlowMonthly, buyingPrice, downPayment, closingCostPercent, repairCost, closingCost) << "%" << endl;
    my_file << "Worth Investing: " << firstHome.worthInvesting(capRate);
    my_file << "\n";
    my_file << "Cap Rate: " << firstHome.capRate(cashFlowMonthly, buyingPrice) << "%" << endl; // Make Sure Not To Include Mortgage Payment ( We Are Assuming You Pay All Cash)
    my_file << "\n";

    cout <<"\n";
    cout << "================================================" << std::endl;
    cout << "Real Estate Calculator Created By Austin Nguyen" << std::endl;
    cout << "================================================" << std::endl;
    cout << "Address: " << firstHome.getAddress() << std::endl;
    cout << "\n";
    cout << "Buying Price: $" << firstHome.getBuyingPrice() << std::endl;
    cout << "\n";
    cout << "Rent: $" << firstHome.getRent() << std::endl;
    cout << "\n";
    cout << "Cashflow Monthly: $" << firstHome.getCashFlow() << std::endl;
    cout << "\n";
    cout << "Does It Pass One Percent Rule? " << firstHome.onePercentRule(buyingPrice,rent) << std::endl;
    cout << "\n";
    cout << "Cash On Cash Return: " << firstHome.cashOnCashReturn(cashFlowMonthly,buyingPrice,downPayment,closingCostPercent,repairCost,closingCost) << + "%" << std::endl;
    cout << "\n";
    if(firstHome.cashOnCashReturn(cashFlowMonthly,buyingPrice,downPayment,closingCostPercent,repairCost,closingCost) >= 15) {
        cout << "Based off the analysis this property is worth investing in!" << std::endl;
    } else {
        cout <<"Based off the analysis this property is NOT worth investing" << std::endl;
    }
    cout << "\n";
    cout << "Cap Rate: " << firstHome.capRate(cashFlowMonthly,buyingPrice) << "%" << endl; // Make Sure To Not Include Mortgage Payment
    
    cout << "================================================" << std::endl;
    }
}
