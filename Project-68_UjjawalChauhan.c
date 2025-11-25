// list of header file
#include <stdio.h>
#include <string.h>
#include <math.h>

// structure of borrower using typedef
typedef struct Borrower {
    char name[50];
    float loan_amount;
    float interest_rate;
    int tenure;         
    float income;       
    float emi;
    int eligible;       
} bor;
float calculateEMI(float principal, float annualRate, int months) 
{
    float r = annualRate / (12 * 100);  // monthly interest (decimal)
    float emi;
    if (r == 0) {
        // No interest case
        emi = principal / months;
    } else {
        // EMI formula:
        // EMI = [P * r * (1 + r)^n] / [(1 + r)^n - 1]
        float powVal = pow(1 + r, months);
        emi = (principal * r * powVal) / (powVal - 1);
    }
    return emi;
}
void printSchedule(float principal, float annualRate, int months, float emi) 
{
    float r = annualRate / (12 * 100);
    float currentBalance = principal;
    float interestPart, principalPart;
    int i;

    printf("\nAmortization Schedule:\n");
    printf("Month\tEMI\t\tInterest\tPrincipal\tBalance\n");

    for (i = 1; i <= months; i++) {
        interestPart = currentBalance * r;
        principalPart = emi - interestPart;

        // Last month adjustment to avoid small rounding errors
        if (i == months) {
            principalPart = currentBalance;
            emi = interestPart + principalPart;
        }

        currentBalance = currentBalance - principalPart;

        if (currentBalance < 0) {
            currentBalance = 0;
        }

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
               i, emi, interestPart, principalPart, currentBalance);
    }
}



int main()
{
    int n,i;
    printf("==== Loan Eligibility and EMI Calculator ====\n");
    printf("Enter number of loan applications: ");
    scanf("%d",&n);
    bor apps[n];
    for (i = 0; i < n; i++) 
    {
        printf("\n--- Enter details for Borrower %d ---\n", i + 1);

        printf("Name of Borrower: ");
        scanf(" %[^\n]",apps[i].name);

        printf("Loan Amount: ");
        scanf("%f", &apps[i].loan_amount);

        printf("Annual Interest Rate (in %%): ");
        scanf("%f", &apps[i].interest_rate);

        printf("Loan Tenure (in months): ");
        scanf("%d", &apps[i].tenure);

        printf("Monthly Income: ");
        scanf("%f", &apps[i].income);

        if (apps[i].loan_amount <= 10 * apps[i].income) {
            apps[i].eligible = 1;
        } else {
            apps[i].eligible = 0;
        }

        if (apps[i].eligible) 
        {
            apps[i].emi = calculateEMI(apps[i].loan_amount,apps[i].interest_rate,apps[i].tenure);
        } 
        else 
        {
            apps[i].emi = 0;
        }
    
    }
    for (i = 0; i < n; i++) {
        printf("\n==========================================\n");
        printf("Borrower %d: %s\n", i + 1, apps[i].name);
        printf("Loan Amount          : %.2f\n", apps[i].loan_amount);
        printf("Interest Rate        : %.2f%%\n", apps[i].interest_rate);
        printf("Tenure (months)      : %d\n", apps[i].tenure);
        printf("Monthly Income       : %.2f\n", apps[i].income);

        if (apps[i].eligible) {
            float totalAmount = apps[i].emi * apps[i].tenure;
            float totalInterest = totalAmount - apps[i].loan_amount;

            printf("Eligibility          : ELIGIBLE\n");
            printf("Monthly EMI          : %.2f\n", apps[i].emi);
            printf("Total Amount Payable : %.2f\n", totalAmount);
            printf("Total Interest       : %.2f\n", totalInterest);

            // print amortization schedule
            printSchedule(apps[i].loan_amount,
                          apps[i].interest_rate,
                          apps[i].tenure,
                          apps[i].emi);
        } else {
            printf("Eligibility          : NOT ELIGIBLE\n");
            printf("Reason: Loan amount is more than 10 times monthly income.\n");
        }
    }

    return 0;

}