Loan EMI Calculator & Eligibility Checker

| Member                 | Roll No (Optional) | Contribution                                                           |
| ---------------------- | ------------------ | ---------------------------------------------------------------------- |
| **Ashish Kumar Rawat** | —                  | EMI calculation logic (`emi.c`, `emi.h`)                               |
| **Sachin Vishvakarma** | 25LBCS3295         | Eligibility logic & 10× income rule (`eligibility.c`, `eligibility.h`) |
| **Atharva**            | _                  | Amortization schedule module (`amortization.c`, `amortization.h`)      |
| **Ujjawal Chauhan**    | 25LBCS3292         | Main menu, user input handling, integration (`main.c`)                 |

<br>

## 📌 Project Overview <br>
This project is a modular C application that performs: <br><br>

✔ Monthly EMI calculation <br>
✔ Total interest payable <br>
✔ Total payment <br>
✔ Full amortization schedule <br>
✔ Loan eligibility check using: <br>

`monthly_income >= 10 × (existing_emis + new_emi)` <br><br>

The project is divided into four modules for clean teamwork and GitHub collaboration.<br><br>

---

## 📁 Project Structure <br>al rules
loan-emi-project/
│
├── main.c<br>
├── emi.c<br>
├── emi.h<br>
├── amortization.c<br>
├── amortization.h<br>
├── eligibility.c<br>
├── eligibility.h<br>
└── README.md<br>

<br>

---

## ✔ Module Descriptions <br>

### **main.c** <br>
- Menu system <br>
- User input handling <br>
- Integration of all modules <br><br>

### **emi.c / emi.h** <br>
- EMI calculation using standard financial formula <br>
- EMI summary printing <br><br>

### **amortization.c / amortization.h** <br>
- Month-wise EMI breakup: <br>
  - Opening balance <br>
  - Interest <br>
  - Principal <br>
  - Closing balance <br><br>

### **eligibility.c / eligibility.h** <br>
- Implements 10× income rule for loan approval <br>
- Provides suggestions when not eligible <br><br>

---

## 🚀 How to Compile & Run <br>

### **Compile:** <br>

```bash
gcc main.c emi.c amortization.c eligibility.c -o loan_emi_app -lm

Run:
./loan_emi_app

