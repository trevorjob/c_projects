#include "account.h"

int countDigits(int dig);
account_t *openAcct(account_t *newacct)
{
        // CREATE ACCOUNT
        // struct members
        char firstName[20];
        char lastName[20];
        int accountNumber;
        double deposites;
        double balance;
        int pin;
        char openingDate;
        int count = 0;
        char a[3];
        // ALLOCATE SPACE FOR NEW STRUCTURE
        newacct = malloc(sizeof(struct account));

        // GETTING USER INFORMATION
        printf("your firstName: ");
        scanf("%s",&firstName);
        printf("your lastName: ");
        scanf("%s",&lastName);
        strcpy(newacct->fisrtName, firstName);
        strcpy(newacct->lastName, lastName);

         a[0] = firstName[0];
         a[1] = lastName[0];
         a[2] = '\0';
        strcpy(newacct->initials,a);
        // GENERATE NUMBER FOR ACCOUNT NUMBER
        srand(time(0));
        accountNumber = (rand() % 100) + 100;
        newacct->accountNumber = accountNumber;

        printf("your account number is %d\n", newacct->accountNumber);

        do
        {
                system("cls");
                printf("your initias: %s\n", newacct->initials);
                printf("your name: %s %s\n", newacct->fisrtName, newacct->lastName);
                // GET PIN
                printf("your account number is %d\n", newacct->accountNumber);
                if (count > 0)
                        printf("pin must be 3 digits: ");
                else
                        printf("create pin\npin must be 2 digits: ");
                scanf("%d", &pin);
                count++;
                // if(!isdigit(pin))
                //         exit(1);
                // WHILE PIN IS GREATER OR LESS THAN 2 REPEAT
        } while(countDigits(pin) != 2);
        
        newacct->pin = pin;

        printf("your pin is %d\n", newacct->pin);

        // MAKE FIRST DEPOSIT
        printf("make a deposit: ");
        scanf("%lf", &deposites);

        newacct->deposites[0] = deposites;
        newacct->balance = deposites;
        newacct->depositCount = 1;
        newacct->withdrawalCount = 0;
        
        // GET DATE AND TIME OF ACCOUNT OPENING
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strcpy(newacct->openingDate, asctime(tm));

        // RETURN ACCOUNT BACK
        return (newacct);
}


int countDigits(int dig)
{
        // THIS COUNTD THE INDIVIDUAL DIGITS OF A NUMBER AND RETURNS THE LENGTH
        int count = 0;
        while (dig != 0)
        {
                dig = dig/10;
                count++;
        }
        return count;
}

