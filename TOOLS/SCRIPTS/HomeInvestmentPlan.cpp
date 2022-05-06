#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;


/*
This little program is to help me organize my thoughts.
I recently decided to buy a lot of stock while the market was slightly lower than usual.
Although this is a good practice. It was a bit premature. If I earned about $26,000 more than I do now, no problem!

If I were to do it over again I would have 1st finished building up the buffer and 2nd stashed all my income towards
paying off one of the mortgages. 

In general there is nothing wrong with buying stocks when they are lower, but I think I didn't approach this with the right
perspective. **I think 3 is our magic number of mortgages especially if we can buy them for the right price.**
Until I have 3 mortgages out I should be preparing to get the 3.

As an aside on a macro level the govt just pumped 4-7 trillion dollars into the economy. Stocks are totally inflated. Housing prices are
probably as well but it is not doomed to go down until things actually reflect there true value. 
I had recently listened to 401k millionaires and they told me to maximize my contributions. 
Although that is still true, by building my buffer, then paying off my debt, my business would be more stable, 
I will be more prepared for the next real estate investment and there I will be able to leverage that money now
as opposed to waiting until I am 59. 

I do think it will still be good to buy when markets crash, but I should get the 3rd house first and do my best to improve my situation
by paying down my debt.
*/
double interestRate = 5.11; //pull from API.
double r = (interestRate /100) / 12;
double n = 360;
double numerator = r*(pow(1+r,n));
double denominator = (pow(1+r,n)-1);
int mortgage = 300000;
int hoa = 20;
int propertyTaxes = 1500;
int homeownerInsurance = 500;
int newHomePointPurchase = 20000;
double additionalCosts = hoa + (propertyTaxes+homeownerInsurance)/12;
int numOfMortgages = 2; //should not exceed 5!

int monthlyGrossIncome = 3520*2;
int monthlyNetIncome = monthlyGrossIncome* .8;

double calculatedMonthlyPayment()
{
//Monthly Mortgage Payment = Principal loan*(r(1+r)^n/(1+r)^n-1)
//monthly interest rate r
//number of payments over the loan's lifetime n (360 for 30 yr)
    double monthly = mortgage*(numerator/denominator);
    cout<<"mortgage monthly payment is: "<<monthly<<"\n";
    cout<<"Monthly payment is: "<<monthly+additionalCosts<<"\n";
    return monthly + additionalCosts;
}
void idealMortgage()
{
    double idealMortgage = 0.0;
    double IdealMonthlyPayment = monthlyNetIncome * .25;
    cout<<"Dave Ramsey suggests a monthly payment of 25% of my monthly net income($"<<IdealMonthlyPayment<<")\n";
    idealMortgage = (IdealMonthlyPayment - additionalCosts)*denominator/numerator;
    cout<<"In today's market He would suggest a mortgage of $"<<idealMortgage<<"\n";

    IdealMonthlyPayment = monthlyGrossIncome * .28;
    cout<<"The less conservative Google masses suggest 28% of Gross monthly income ($"<<IdealMonthlyPayment<<")\n";
    idealMortgage = (IdealMonthlyPayment - additionalCosts)*denominator/numerator;
    cout<<"In today's market that is a mortgage of $"<<idealMortgage<<"\n";
}

bool isAHouseAffordable()
{
	bool isAffordable = true;
    double monthly = calculatedMonthlyPayment();
    cout<<"Total monthly bill will be: "<<monthly<<"\n";
    double mGIpercent =  monthly/monthlyGrossIncome*100;
    double mNIpercent =  monthly/monthlyNetIncome*100;
    cout<<"That is "<<mGIpercent<<"% of my gross income\n";
    cout<<"That is "<<mNIpercent<<"% of my net income\n";
    if(mGIpercent>28)
    {
        cout<<"You should not buy it\n";
        isAffordable = false;
    }
    if(mNIpercent>28)
    {
        cout<<"You can afford it, but it is not a steal\n";
        isAffordable = true;
    }
    idealMortgage();

    return isAffordable;
}



void investRothIRA()// - no longer
{
    //can i contribute from my taxed bank 
    //account? yes
}

void investTraditionalIRA()
{
    //can i contribute from my taxed bank 
    //account? If I can this is the preferred and investRothIRA 
    //will nolonger be a primary choice
    cout << "Can I invest from my bank?\n"; //Yes

}

void invest401k()
{
    //min company match
    cout << "Contribute at least min company match\n";
    cout << "If you want to lower your income invest in 401k fully\n";
}

void payDownMortgages()
{
    //when all 5 mortgages are used up or
    //it is not affordable - define affordable -need
    // and not required
}

void saveForBiggerPurchases()
{
    //foreclosure
}

void purchaseTaxLiens()
{
    //How long prior to February tax auction?
    //Attend auction and apply for interest
    cout << "How far are you from February?\n";
    
    //According to the 
}

int main() {


    cout << "**Home Investment Algorithm**\n";
    cout << "Do you have a completed buffer of 50?\n";
    cout << "Do you have 6 month food storage?\n\n\n";
    invest401k();

    cout << "Assuming you do, let's see today's mortgage interest rate\n";
    cout << "Today's interest rate is: "<< interestRate <<" \n";
    cout << "You already have "<< numOfMortgages<< " mortgages to pay off\n";

    if (numOfMortgages >= 4)
    {
        cout << "Pay off your mortgages you CRAZY!!\n";
    }
    else
    {
        bool buyit = isAHouseAffordable();
        if (buyit)
        {
            cout << "Sounds like we should start Shopping!!\n";
        }
        else
        {
            cout << "\nMaybe we need some alternative investments!!\n";
        }
    }
    
    system("pause");
    return 0;
}