# C - NANDOM BANK

In this project, I learned about using structs in C `typedef struct account`and
`account_t`, i also learnt how to manipulate struct members with functions etc.
and above all it helped me experience practical appications of the little knowledge i have using the C language

## Header File :file_folder:

- [account.h](./account.h): Header file containing definitions and
  prototypes for all types and functions written in the project.

| File          | Definition/Prototype                       |
| ------------- | ------------------------------------------ |
| `openAcct.c`  | `account_t *openAcct(account_t *newacct);` |
| `moneyMove.c` | `double deposite(double cash);`            |
| `moneyMove.c` | `double withdraw(double cash);`            |
| `system.c`    | `void printMain(account_t acct);`          |
| `system.c`    | `void loader(void);`                       |
| `account.h`   | `typedef account_t account`                |

## compilation

To run this code clone the repo or copy all files to your machine and place in one folder
then run `gcc *.c -o bank` and `./bank`

## NOTE:

If you are not running a windows machine change all instances of `system("cls");` to `system("clr");`
