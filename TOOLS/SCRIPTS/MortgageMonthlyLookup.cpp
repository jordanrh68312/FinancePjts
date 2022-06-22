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


double calculatedMonthlyPayment(double interestRate, int mortgage)
{
    double r = (interestRate /100) / 12;
    double n = 360;
    double numerator = r*(pow(1+r,n));
    double denominator = (pow(1+r,n)-1);
    double monthly = mortgage*(numerator/denominator);
    return monthly + additionalCosts;
}

void recommendation()
{
    cout<<"Dave Ramsey suggests a monthly payment of 25% of my monthly net income\n";
    cout<<"The less conservative masses suggest 28% of Gross monthly income \n";

}

int main() {
    recommendation();
    for(double i =2.5;i<6.5;i=i+.5)
    {
        for(int m=240000;m<330000;m=m+20000)
        {
            double monthly = calculatedMonthlyPayment(i,m);
            cout<<"Mortgage "<<m <<"interest rate "<< i<<" you pay a "<<monthly<<"\n";
        }
        cout<<"\n-----\n";
    }
    
    system("pause");
    return 0;
}
