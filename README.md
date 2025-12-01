Loan EMI Calculator & Eligibility Checker

| Member                 | Roll No (Optional) | Contribution                                                           |
| ---------------------- | ------------------ | ---------------------------------------------------------------------- |
| **Ashish Kumar Rawat** | —                  | EMI calculation logic (`emi.c`, `emi.h`)                               |
| **Sachin Vishvakarma** | —                  | Eligibility logic & 10× income rule (`eligibility.c`, `eligibility.h`) |
| **Atharva**            | —                  | Amortization schedule module (`amortization.c`, `amortization.h`)      |
| **Ujjawal Chauhan**    | —                  | Main menu, user input handling, integration (`main.c`)                 |

Project Overview
This project is a modular C application which calculates:
Monthly EMI (Equated Monthly Installment)
Total Interest payable
Total Payment
Detailed Amortization Schedule
Loan Eligibility using rule:
----
monthly_income >= 10 × (existing_emis + new_emi)
----
The project is divided into four modules to enable professional and independent team contribution using GitHub.

loan-emi-project/
│
├── main.c
├── emi.c
├── emi.h
├── amortization.c
├── amortization.h
├── eligibility.c
├── eligibility.h
└── README.md

How to Compile & Run

Compile all modules
gcc main.c emi.c amortization.c eligibility.c -o loan_emi_app -lm

Run the program
./loan_emi_app
Learning Outcomes

Modular programming in C

Splitting large projects into reusable components
Working with multiple .c & .h files
Using Git & GitHub for team collaboration
Understanding EMI algorithms & amortization
Applying real-world financial rules
