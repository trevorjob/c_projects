#ifndef ACCOUNT_H
#define ACCOUNT_H
#define MAXNUM 15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>

typedef struct account
{
        char fisrtName[20];
        char lastName[20];
        int accountNumber;
        double deposites[MAXNUM];
        double withdrawals[MAXNUM];
        int depositCount;
        int withdrawalCount;
        double balance;
        int pin;
        char openingDate[30];
        int accountIndex;
        char initials[3];
}account_t;
// account_t newacct;
account_t *openAcct(account_t *newacct);
double deposite(double cash);
double withdraw(double cash);
// int countDigits(dig);
#endif