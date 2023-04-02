#include "account.h"
void printMain(account_t acct);
void loader(void);
int main(void)
{
        // play on variables
        int yesno, count, k, h, b, g = 0;
        
        double cash;
        int depositeCount = 1;
        int withdrawalCount = 0;
        int currentAcct;
        int index = 0;
        int selections;
        char init[3];

        account_t mainAcct;
        loader();
        printf("welcome to NANDOM'S bank\nplease follow all instructions in the program accordingly");
        printf("\n\n");
        printf("PLEASE MAKE SURE TO REMEMBER YOUR ACCOUNT NUMBER, INITIALS AND PASSWORD FOR TRANSACTIONS\n");
        printf("YOU CAN ALSO TAKE A LOOK AT YOUR ACCOUNT INFOR FROM THE PROGRAM\n");
        printf("once again welcome to NANDOM'S bank and happy transacting\n");
        printf("press any number to go back: ");
        scanf("%d", &yesno);

        loader();
        printf("welcome\n");
        // INITIALIZE FIRST ACCOUNT WITH THE OPENACCT FUNCTION
        mainAcct = *openAcct(&mainAcct);
        // SET ITS CURRENT INDEX 
        // THE INDEX VARIABLE STORES THE INDEX OF A STRUCT IN THE ARRAY
        mainAcct.accountIndex = index;
        index++;

        // DECLARATION OF AN ARRAY OF ACCOUNT STRUCTS
        // THIS ARRAY IS FOR THE MULTIPLE ACCOUNTS A USER MIGHT WANT TO OPEN
        account_t acctArr[5];
        // SETS FIRST ELEMENT OF THE ARRAY TO MAINACCT
        acctArr[mainAcct.accountIndex] = mainAcct;
        acctArr[mainAcct.accountIndex].withdrawals[0] = 0;
        currentAcct = acctArr[mainAcct.accountIndex].accountIndex;

        do
        {
                // DO..WHILE LOOP

                loader();
                // PRINT MENU
                printMain(acctArr[currentAcct]);
                // THE CURRENT ACCOUNT WILL BE THE CURRENT LOGGED IN ACCOUNT
                // THE CURRENT ACCOUNT VARIABLE STORES THE INDEX OF A STRUCT IN THE ARRAY
                printf("current balance:  $%.2lf:  ", acctArr[currentAcct].balance);
                // GET USER CHOICE OF ACTION
                scanf("%d", &selections);
                if (selections == 1)
                {
                        // CREATE NEW ACCOUNT
                        loader();
                        account_t acct1;
                        // SETS SECOND ELEMENT OF THE ARRAY TO ACCT1
                        acct1 = *openAcct(&acct1);
                        acctArr[index] = acct1;

                        acctArr[index].accountIndex = index;
                        // SET CURRENT ACCOUNT TO THE INDEX / ACCOUNTINDEX OF THE NEW ACCOUNT
                        currentAcct = index;
                        index++;

                }
                else if (selections == 2)
                {
                        // DEPOSIT CASH
                        loader();
                        printf("how much would you like to deposite: ");
                        // ADD THE DEPOSITED CASH TO THE DEPOSIT ARRAY OF THE CURRENT STRUCT ACCOUNT
                        acctArr[currentAcct].deposites[acctArr[currentAcct].depositCount] = deposite(cash);
                        // ADD THE DEPOSITED CASH TO THE CURRENT BALANCE
                        acctArr[currentAcct].balance += acctArr[currentAcct].deposites[acctArr[currentAcct].depositCount];
                        // THE DEPOSITCOUNT STORES THE NUMBER OF ELEMENTS IN THE DEPOSIT ARRAY OF THE CURRENT ACCT
                        acctArr[currentAcct].depositCount++;
                }
                else if (selections == 3)
                {
                        // WITHDRAWAL
                        loader();
                        printf("how much would you like to withdraw: ");
                        cash = withdraw(cash);
                        // CHECK THE CASH
                        if (cash <= acctArr[currentAcct].balance)
                        {
                                // ADD THE WITHDRAWN CASH TO THE WITHDRAWAL ARRAY OF THE CURRENT STRUCT ACCOUNT
                                acctArr[currentAcct].withdrawals[acctArr[currentAcct].withdrawalCount] = cash;
                                // SUBTRACT THE WITHDRAWN CASH TO THE CURRENT BALANCE
                                acctArr[currentAcct].balance -= cash;
                                // THE WITHDRAWALCOUNT STORES THE NUMBER OF ELEMENTS IN THE WITHDRAWAL ARRAY OF THE CURRENT ACCT
                                acctArr[currentAcct].withdrawalCount++;
                        }
                        else
                        {
                                loader();
                                printf("you dont have enough for this transaction your\nyour balance is $%.2lf\n", acctArr[currentAcct].balance);
                                Sleep(3500);
                        }
                }
                else if (selections == 4)
                {
                        // TRANSFER CASH
                        do
                        {
                                loader();
                                printf("enter account number: ");
                                scanf("%d", &b);

                                // LOOP THROUGH THE ACOOUNTS ARRAY
                                for (k = 0; k < sizeof(acctArr)/sizeof(acctArr[0]); k++)
                                {
                                        // FOR EACH ITERATION
                                        // CHECK IF THE ACCOUNT NUMBER IS EQUAL TO B AND IF THE CURRENT LOGGED IN ACCOUNT NUMBER IS NOT EQUAL TO B 
                                        if (acctArr[k].accountNumber == b && acctArr[currentAcct].accountNumber != b)
                                        {
                                                h = 0;
                                                break;
                                        }
                                        else
                                                h = 5;
                                        
                                }
                                if (h != 0)
                                {
                                        loader();
                                       printf("no account match");
                                       printf("would you like to try again..\n(0)no (1)yes: \n");
                                       
                                       do
                                       {
                                                scanf("%d", &g);
                                                // IF G IS NOT 1 OR 0 KEEP LOOPING
                                       }while (g != 1 && g != 0);
                                }
                                if (h != 10)
                                {
                                        loader();
                                        printf("cannot send cash to yourself\n");
                                }
                                
                        
                        } while (g == 1);

                        if (h == 0)
                        {
                                loader();
                                printf("how much would you like to transfer: \n");
                                scanf("%d", &cash);
                                // COMPARE THE AMOUNT THE USER WANTS TO TRANSFER TO THE CURRENT BALANCE
                                if(yesno <= acctArr[currentAcct].balance)
                                {
                                        acctArr[currentAcct].withdrawals[acctArr[currentAcct].withdrawalCount] = cash;
                                        // ADD THE WITHDRAWN CASH TO THE WITHDRAWAL ARRAY OF THE CURRENT STRUCT ACCOUNT
                                        acctArr[currentAcct].balance -= cash;
                                        // SUBTRACT THE WITHDRAWN CASH TO THE CURRENT BALANCE
                                        acctArr[currentAcct].withdrawalCount++;
                                        // THE WITHDRAWALCOUNT STORES THE NUMBER OF ELEMENTS IN THE WITHDRAWAL ARRAY OF THE CURRENT ACCT
                                        acctArr[k].deposites[acctArr[k].depositCount] = cash;
                                        // ADD THE DEPOSITED CASH TO THE DEPOSIT ARRAY OF THE CURRENT STRUCT ACCOUNT
                                        acctArr[k].balance += cash;
                                        acctArr[k].depositCount++;
                                        loader();
                                        printf("\n\n\n\ntransfer of $%.2lf to %s %s was succesful\n", cash, acctArr[k].fisrtName, acctArr[k].lastName);
                                }
                                else
                                {
                                        loader();
                                        printf("you dont have enough money in your account for this transaction\n");
                                        Sleep(3500);
                                }
                        }
                        
                   

                        
                }
                else if (selections == 5)
                {
                        // PRINT OUT ACCOUNT INFORMATION
                        loader();
                        for (k = 0; k < 50; k++)
                        {
                                printf("-");
                        }
                        printf("\n");
                        printf("Name %s %s\n", acctArr[currentAcct].fisrtName, acctArr[currentAcct].lastName);
                        printf("Account No %d\n", acctArr[currentAcct].accountNumber);
                        printf("Account Balance:  $%.2lf\n", acctArr[currentAcct].balance);
                        printf("Account opened on %s\n", acctArr[currentAcct].openingDate);
                        printf("press any number to go back: ");
                        scanf("%d", &yesno);
                }
                else if (selections == 6)
                {
                        // PRINT OUT ALL TRANSACTIONS
                        loader();
                        printf("\n");
                        printf("-------------DEPOSITS--------------\n");
                        // LOOP THROUG THE CURRENT ACCOUNT DEPOSITS ARRAY AND PRINT OUT ALL DEPOSITS
                        for (k = 0; k < acctArr[currentAcct].depositCount; k++)
                        {
                                printf("TODAY\n");
                                printf(" $%.2lf was deposited to your account\n", acctArr[currentAcct].deposites[k]);
                                printf("\n");
                        }
                        printf("\n");
                        printf("-----------WHITHDRAWALS-------------\n");
                        // LOOP THROUG THE CURRENT ACCOUNT WITHDRAWAL ARRAY AND PRINT OUT ALL WITHDRAWALS
                        if (acctArr[currentAcct].withdrawals[0] > 0)
                        {
                                for (k = 0; k < acctArr[currentAcct].withdrawalCount; k++)
                                {
                                        printf("TODAY\n");
                                        printf(" $%.2lf was withdrawn from your account\n", acctArr[currentAcct].withdrawals[k]);
                                        printf("\n");
                                }
                        }
                        else
                        {
                                printf("\n");
                                printf("No Withdrawals Have Been Made Yet.\n");
                                printf("\n");
                        }
                        printf("TOTAL BALANCE:  $%.2lf\n", acctArr[currentAcct].balance);
                        printf("press any number to go back: ");
                        scanf("%d", &yesno);
                }
                else if (selections ==  7)
                {
                        loader();
                        system("cls");
                        printf("LOGIN\n");
                        printf("enter the initials of the account you would like to log into\n");
                        printf("eg. andrew james would be = aj\n");
                        printf("ACCOUNT INITIALS: ");
                        scanf("%s", &init);
                        printf("PIN: ");
                        scanf("%d", &yesno);
                        for (k = 0; k < 5; k++)
                        {
                                // COMPARE INIT TO THE INITIALS
                                if (strcmp(acctArr[k].initials, init) == 0)
                                {
                                        // SWITCH THE CURRENT ACCOUNT
                                        if (acctArr[k].pin == yesno)
                                                currentAcct = acctArr[k].accountIndex;
                                }
                                        
                        }

                        if (strcmp(acctArr[currentAcct].initials, init) != 0 )
                        {
                                loader();
                                printf("No Account Initials Match In Our Database\ncheck and try again\n");
                                Sleep(3500);
                        }
                        else if (acctArr[currentAcct].pin != yesno)
                        {
                                loader();
                                printf("Wrong Pin\ncheck and try again\n");
                                Sleep(3500);
                        }                        
                }
                else if (selections == 8)
                {
                        // CLOSE ACCOUNT
                        loader();
                        printf("enter account initials you want to close: ");
                        scanf("%s", &init);
                        printf("enter your pin: ");
                        scanf("%d", &yesno);

                        for (k = 0; k < 5; k++)
                        {
                                if (strcmp(acctArr[k].initials, init) == 0)
                                {
                                        if (acctArr[currentAcct].pin == yesno)
                                        {
                                                acctArr[k].pin =  0;
                                                acctArr[k].accountNumber =  0;
                                                break;
                                        }

                                }
                                        
                        }

                        if (strcmp(acctArr[k].initials, init) != 0 )
                        {
                                loader();
                                printf("No Account Initials Match In Our Database\ncheck and try again\n");
                                Sleep(3500);
                        }
                        else if (acctArr[currentAcct].pin != yesno)
                        {
                                loader();
                                printf("Wrong Pin\ncheck and try again\n");
                                Sleep(3500);
                        }      
                }

         // WHILE SELECTIONS IS NOT 9 KEEP LOOPING
        } while (selections != 9);
        
        return (0);
}

void printMain(account_t acct)
{
        int i;
        system("cls");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

        printf("------------------------------------------\n");
        printf("|            |MAIN MENU|                 |\n");
        printf("| %s                                |\n", acct.fisrtName);
        printf("|                                        |\n");
        printf("| 1. Open New Account                    |\n");
        printf("| 2. Deposit Money                       |\n");
        printf("| 3. Withdraw Money                      |\n");
        printf("| 4. Transfer Money                      |\n");
        printf("| 5. Account Details                     |\n");
        printf("| 6. Transaction Details                 |\n");
        printf("| 7. Switch Accounts                     |\n");
        printf("| 8. Close Account                       |\n");
        printf("| 9. Exit                                |\n");
        printf("|                                        |\n");
        printf("------------------------------------------\n");
}


void loader(void)
{
          // 0 - black background,
        // A - Green Foreground
        system("color 0A");
        
        // Initialize char for printing
        // loading bar
        char a = 177, b = 219;
        
        printf("\n\n\n\n");
        // printf("\n\n\n\n\t\t\t\t\t" + "Loading...\n\n");
        printf("\t\t\t\t\t");
        
        // Print initial loading bar
        for (int i = 0; i < 26; i++)
                printf("%c", a);
        
        // Set the cursor again starting
        // point of loading bar
        printf("\r");
        printf("\t\t\t\t\t");
        
        // Print loading bar progress
        for (int i = 0; i < 26; i++) {
                printf("%c", b);
        
                // Sleep for 1 second
                Sleep(50);
        }
                system("cls");
}