#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;


/*
This little program displays mortgages and interest rates relationship to
a monthly expense.
*/


int hoa = 20;
int propertyTaxes = 1500;
int homeownerInsurance = 500;
int newHomePointPurchase = 20000;
double additionalCosts = hoa + (propertyTaxes+homeownerInsurance)/12;
int numOfMortgages = 2; //should not exceed 5!

int monthlyGrossIncome = 3923*2;
int monthlyNetIncome = monthlyGrossIncome* .66;

double calculatedMortage(double interestRate, int monthly)
{
    double r = (interestRate /100) / 12;
    double n = 360;
    double numerator = r*(pow(1+r,n));
    double denominator = (pow(1+r,n)-1);
    double mortgage = monthly /(numerator/denominator);
    return mortgage;

}
void recommendation()
{
    double IdealMonthlyPayment = monthlyNetIncome * .25;
    cout<<"Dave Ramsey suggests a monthly payment of 25% of my monthly net income($"<<IdealMonthlyPayment<<")\n";

    IdealMonthlyPayment = monthlyGrossIncome * .28;
    cout<<"The less conservative masses suggest 28% of Gross monthly income ($"<<IdealMonthlyPayment<<")\n";

}

int main() {
    recommendation();
    int monthly = 1450;
    for(double i =2.5;i<6;i=i+.5)
    {
        double mortgage = calculatedMortage(i,monthly);
        cout<<"To get a "<<monthly + additionalCosts <<" monthly at interest rate "<< i<<" you need a "<<mortgage<<"\n";
    }
    
    system("pause");
    return 0;
}
