#include "account.h"

double deposite(double cash)
{
        scanf("%lf", &cash);
        printf("your account has been credited with %.2lf\n", cash);
        return (cash);
}

double withdraw(double cash)
{
        scanf("%lf", &cash);
        return (cash);
}