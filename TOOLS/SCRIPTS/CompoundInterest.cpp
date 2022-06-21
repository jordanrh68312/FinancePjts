#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    double interestRate = .03;
    int principal = 8500;
    int compoundRate = 12;
    double total = 0.0;
    double PMT = 595.8;// 7150/12
    for (int time=0;time<=30;time++)
    {
        //Total Compound interest from principal + Future value of a series
        //Total [P(1+r/n^nt)]+[PMT X (((1+r/n)^(nt)-1/(r/n))]
        double previousYearTotal;
        total>0 ? previousYearTotal = total : previousYearTotal=0;
        // cout<<"previousYearTotal"<< previousYearTotal;
        double futureValueTotal = PMT * ((pow((1+interestRate/compoundRate),(compoundRate*time))-1)/(interestRate/compoundRate));
        double compoundInterestTotal = 8500 * (pow((1+interestRate/compoundRate),(compoundRate*time)));
        total = compoundInterestTotal + futureValueTotal;

        double yearlyInterestEarned = total-(previousYearTotal+PMT*12);
        double monthlyInterestEarned = (total-(previousYearTotal+PMT*12))/12;
        // cout<<"futureValueTotal "<<futureValueTotal<<"\n";
        // cout<<"compoundInterestTotal "<<compoundInterestTotal<<"\n";
        if (time == 0){
            cout<<"After "<<time<<" year(s) - "<<total <<"\n";
        }
        else{
            cout<<"After "<<time<<" year(s) - "<<total<<" Yearly interest Earned - "<<yearlyInterestEarned <<" Per Month "<<monthlyInterestEarned <<"\n";
        }
    }

    return 0;
}