// emi.h
#ifndef EMI_H
#define EMI_H

double calculate_emi(double principal, double annual_rate_percent, int months);
void show_emi_details(double principal, double annual_rate_percent, int months, const char *borrower_name);

#endif