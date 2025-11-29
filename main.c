/*
  main.c
  Project: Loan Interest / EMI Calculator & Eligibility Checker
  Description:
    - Menu-driven program
    - Uses:
        emi.c / emi.h              -> EMI calculation + EMI details
        amortization.c / .h        -> Amortization schedule
        eligibility.c / .h         -> Eligibility check (10x rule)
*/

#include <stdio.h>
#include "emi.h"
#include "eligibility.h"

int main() {
    int choice;
    do {
        printf("\n=== Loan EMI Calculator & Eligibility Checker ===\n");
        printf("1. Calculate EMI and Interest\n");
        printf("2. Check Loan Eligibility\n");
        printf("3. Calculate EMI + Check Eligibility (Combined)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (choice == 1) {
            double principal, annual_rate;
            int years_or_months, months;
            int mode;
            char borrower_name[100];

            printf("\n-- EMI Calculator --\n");
            printf("Enter borrower name: ");
            // leading space skips leftover newline
            scanf(" %99[^\n]", borrower_name);

            printf("Enter principal amount: ");
            scanf("%lf", &principal);
            printf("Enter annual interest rate: ");
            scanf("%lf", &annual_rate);

            printf("Choose tenure input mode: 1 for years, 2 for months: ");
            scanf("%d", &mode);
            if (mode == 1) {
                printf("Enter tenure in years: ");
                scanf("%d", &years_or_months);
                months = years_or_months * 12;
            } else if (mode == 2) {
                printf("Enter tenure in months: ");
                scanf("%d", &months);
            } else {
                printf("Invalid tenure mode. Please select 1 or 2.\n");
                continue;
            }

            show_emi_details(principal, annual_rate, months, borrower_name);
        }
        else if (choice == 2) {
            double monthly_income, existing_emis, principal, annual_rate;
            int months, mode, years_or_months;
            double new_emi;
            int eligible;
            char borrower_name[100];

            printf("\n-- Eligibility Checker --\n");
            printf("Enter borrower name: ");
            scanf(" %99[^\n]", borrower_name);

            printf("Enter your monthly income (net): ");
            scanf("%lf", &monthly_income);

            printf("Enter total existing EMIs per month (if none enter 0): ");
            scanf("%lf", &existing_emis);

            printf("To check eligibility for a specific loan, enter loan details.\n");
            printf("Enter principal amount: ");
            scanf("%lf", &principal);
            printf("Enter annual interest rate: ");
            scanf("%lf", &annual_rate);

            printf("Choose tenure input mode: 1 for years, 2 for months: ");
            scanf("%d", &mode);
            if (mode == 1) {
                printf("Enter tenure in years: ");
                scanf("%d", &years_or_months);
                months = years_or_months * 12;
            } else if (mode == 2) {
                printf("Enter tenure in months: ");
                scanf("%d", &months);
            } else {
                printf("Invalid tenure mode. Please select 1 or 2.\n");
                continue;
            }

            new_emi = calculate_emi(principal, annual_rate, months);
            printf("\nBorrower: %s\n", borrower_name);
            printf("Calculated EMI for this loan = %.2lf per month\n", new_emi);

            eligible = check_eligibility(monthly_income, existing_emis, new_emi);

            double total_emi = existing_emis + new_emi;
            double required_income = 10.0 * total_emi;

            if (eligible) {
                printf("Result: Eligible.\n");
            } else {
                printf("Result: Not Eligible.\n");
                printf("Total EMI (existing + new): %.2lf\n", total_emi);
                printf("Required minimum income under 10x rule: %.2lf\n", required_income);
                printf("Your income: %.2lf\n", monthly_income);
                printf("You may reduce loan amount, reduce existing EMIs, or increase income to qualify.\n");
            }
        }
        else if (choice == 3) {
            double monthly_income, existing_emis, principal, annual_rate;
            int months, mode, years_or_months;
            double new_emi;
            int eligible;
            char borrower_name[100];

            printf("\n-- EMI + Eligibility (Combined) --\n");
            printf("Enter borrower name: ");
            scanf(" %99[^\n]", borrower_name);

            printf("Enter principal amount: ");
            scanf("%lf", &principal);
            printf("Enter annual interest rate (percent): ");
            scanf("%lf", &annual_rate);
            printf("Choose tenure input mode: 1 for years, 2 for months: ");
            scanf("%d", &mode);
            if (mode == 1) {
                printf("Enter tenure in years: ");
                scanf("%d", &years_or_months);
                months = years_or_months * 12;
            } else if (mode == 2) {
                printf("Enter tenure in months: ");
                scanf("%d", &months);
            } else {
                printf("Invalid tenure mode. Please select 1 or 2.\n");
                continue;
            }

            new_emi = calculate_emi(principal, annual_rate, months);
            printf("\nCalculated EMI = %.2lf per month\n", new_emi);
            show_emi_details(principal, annual_rate, months, borrower_name);

            printf("\nNow check eligibility.\n");
            printf("Enter your monthly income (net): ");
            scanf("%lf", &monthly_income);
            printf("Enter total existing EMIs per month (if none enter 0): ");
            scanf("%lf", &existing_emis);

            eligible = check_eligibility(monthly_income, existing_emis, new_emi);

            double factor = 10.0;
            double total_emi = existing_emis + new_emi;
            double max_total_emi = monthly_income / factor;
            double max_additional = max_total_emi - existing_emis;

            if (eligible) {
                printf("Result: Eligible.\n");
            } else {
                printf("Result: Not Eligible.\n");
                printf("Total EMI (existing + new): %.2lf\n", total_emi);
                printf("Under 10x rule, required income for this EMI = %.2lf\n", total_emi * factor);
                printf("Your income: %.2lf\n", monthly_income);

                if (max_additional > 0) {
                    printf("Maximum total EMI you can afford under 10x rule = %.2lf per month\n", max_total_emi);
                    printf("Maximum additional EMI (after existing EMIs) = %.2lf per month\n", max_additional);
                } else {
                    printf("You currently have no spare EMI capacity under 10x rule.\n");
                    printf("Consider reducing existing EMIs or increasing income.\n");
                }
            }
        }
        else if (choice == 0) {
            printf("Goodbye!\n");
        }
        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
