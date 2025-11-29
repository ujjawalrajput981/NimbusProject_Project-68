/*
  eligibility.c
  Handles:
    - check_eligibility using 10x rule:
      monthly_income >= 10 * (existing_emis + new_emi)
*/

#include "eligibility.h"

/*
  check_eligibility:
    monthly_income -> net monthly income
    existing_emis  -> sum of existing EMIs per month
    new_emi        -> EMI of the new loan

  Rule:
    Eligible only if:
      monthly_income >= 10 * (existing_emis + new_emi)
*/
int check_eligibility(double monthly_income, double existing_emis, double new_emi) {
    if (monthly_income <= 0) return 0;

    double total_emi = existing_emis + new_emi;
    double required_income = 10.0 * total_emi;

    return (monthly_income >= required_income) ? 1 : 0;
}