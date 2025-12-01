/*
  emi.c
  Handles:
    - calculate_emi
    - show_emi_details (also calls amortization schedule)
*/

#include <stdio.h>
#include <math.h>
#include "emi.h"
#include "amortization.h"

/*
  calculate_emi:
    principal        -> loan amount
    annual_rate_percent -> annual interest rate in percent
    months           -> loan tenure in months

  EMI formula:
    r = monthly_rate = annual_rate_percent / 12 / 100
    EMI = P * r * (1+r)^n / ((1+r)^n - 1)
*/
double calculate_emi(double principal, double annual_rate_percent, int months) {
    if (months <= 0 || principal <= 0) return 0.0;
    double r = annual_rate_percent / 12.0 / 100.0;
    if (r == 0.0) {
        // Zero interest simple division
        return principal / months;
    } else {
        double pow_val = pow(1 + r, months);
        double emi = principal * r * pow_val / (pow_val - 1);
        return emi;
    }
}

/*
  show_emi_details:
    - prints basic EMI details
    - prints borrower name
    - prints amortization schedule
*/
void show_emi_details(double principal, double annual_rate_percent, int months, const char *borrower_name) {
    if (months <= 0 || principal <= 0) {
        printf("\nInvalid principal or tenure. Cannot calculate EMI.\n");
        return;
    }

    double emi = calculate_emi(principal, annual_rate_percent, months);
    double total_payment = emi * months;
    double total_interest = total_payment - principal;

    printf("\n--- EMI Details ---\n");
    printf("Borrower Name: %s\n", borrower_name);
    printf("Loan Amount (Principal): %.2lf\n", principal);
    printf("Annual Interest Rate: %.2lf %%\n", annual_rate_percent);
    printf("Tenure: %d months (%.2lf years)\n", months, months / 12.0);
    printf("EMI (monthly): %.2lf\n", emi);
    printf("Total Payment (EMI * months): %.2lf\n", total_payment);
    printf("Total Interest Paid: %.2lf\n", total_interest);
    printf("-------------------\n");

    // Also show amortization schedule
    print_amortization_schedule(principal, annual_rate_percent, months, emi);
}