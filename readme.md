# 💳 Simple Bank Management System in C

A basic console-based bank management system for learning C programming.  
It supports account creation, viewing, deposit, and withdrawal using simple file I/O.

---

## 📁 Project Structure

```
bank-management/
├── src/
│   ├── main.c              # Entry point, menu logic
│   ├── account.c           # Account operations
│   ├── transaction.c       # Deposit/Withdraw logic
├── include/
│   ├── account.h           # Account function declarations
│   └── transaction.h       # Transaction declarations
├── data/
│   └── accounts.txt        # Stores account data
```

---

## 🛠️ How to Compile (Windows / PowerShell)

1. Open PowerShell in the project root folder.
2. Run the following commands:

```powershell
# Create data folder and accounts file if not exists
New-Item -Path .\data -ItemType Directory
New-Item -Path .\data\accounts.txt -ItemType File

# Compile all C source files
gcc src\main.c src\account.c src\transaction.c -Iinclude -o bank.exe
```

3. Run the program:

```powershell
./bank
```

---

## ✅ Features

- Create Account (with support for full name)
- Deposit Money
- Withdraw Money
- View Account Details
- Data stored in `accounts.txt` file

---

## 📌 Notes

- Use `fgets()` instead of `scanf()` for names to support spaces.
- File operations are plain text-based — good for learning file I/O.
- Each account entry is stored as:
  ```
  <account_number> <name> <balance>
  ```

---

## 🙌 Want to Improve It?

- Add password/PIN authentication
- Support transaction history
- Encrypt stored data
- Add UI with ncurses

---

Made with ❤️ for C programming practice.
