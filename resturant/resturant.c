#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  /* variable declarations */
  int i;
  char name[20];
  char menu[][20] = {"fried rice", "spaghetti", "pounded yam", "pepper soup", "nkwobi"}; 
  int options[5] = {0,1,2,3,4};
  int optionSelect, buyAgain = 0;
  double prices[5] = {10, 8, 25, 15, 30};
  double payment;

  /* get customers name */
  printf("welcome to NANDOM'S resturant\n");
  printf("what is your name : ");
  fgets(name, 20, stdin);
  
  /* transform name to uppercase */
  for ( i = 0; name[i]; i++)
  {
    name[i] = toupper(name[i]);
  }
  
    
  /* get customers order */
  printf("welcome %s\nThank you for visiting us today\n", name);
  printf("what can we offer you ?\n"); 
  printf("we have:\n");

  /*do..while loop*/
  do
  {  
    /* loop through the menu array and print out all elements */
    for (i = 0; i < sizeof(menu)/sizeof(menu[0]); i++)
    {
      printf("(%d) ", options[i]);
      printf("%s\n", menu[i]);
    }

    /* get customers order */
    scanf("%d",&optionSelect);
    printf("%s very nice choice\n", menu[optionSelect]);

    /* show order price */
    printf("that would be $%.2lf\n", prices[optionSelect]);

    /* get payment */
    printf("oya give me my money: ");
    scanf("%lf",&payment);

    /* compare payment */ 
    if (payment >= prices[optionSelect])
    {
      /*if the payment is greater or equal to price of meal*/
      printf("your change is $%.2lf\n", payment - prices[optionSelect]);
      printf("thank you once again %s0for coming to our establishment\nhave a wonderful day\n\n\n", name);

      /* ask if customer wants to eat again and save answer in variable*/
      printf("would you like to eat again ?\n (0) no\n (1) yes\n\n");
      scanf("%d",&buyAgain);
    } else if (payment < prices[optionSelect]) {
      /*if the payment is less than price of meal*/
      printf("you are owing $%.2lf\n\nABEG GIVE ME MY MONEY IF YOU NO WAN DIE\n",prices[optionSelect] - payment);
      printf("THANK GOD I REMEMBER YOUR NAME SEF : %s\nOYA GETOUT\n",name);
      buyAgain = 0;
    } 
  } while (buyAgain == 1);

  return (0);
}
