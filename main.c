/*************************
 * Loan Calculator
 * Michael Juszkiewicz  
 * main.c
 *
 *************************/


// include standard libs
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <inttypes.h>

// include custom headders
#include "loans.h"

// initialize gloabal variables
float g_total_principle = 0;
float g_total_interest = 0;
float g_account_total = 0;
int g_number_of_accounts = 0;
float g_monthly_payment = 0;



int main()
{

  /*  
    do{
    printf("Please enter the number of accounts. (0 < n <= %d) :", MAX_ACCOUNTS);
    scanf("%d", &g_number_of_accounts);
    
    if (g_number_of_accounts <= 0 && g_number_of_accounts > MAX_ACCOUNTS)
      {
        printf("\nSorry, Invalid input. Please try again.\n");
        continue;
      }
  }while(g_number_of_accounts <= 0 && g_number_of_accounts > MAX_ACCOUNTS);
  
  */
  
  
  
  struct loan account [MAX_NUMBER_OF_ACCOUNTS];
  
  //printf("number of accounts : %d\n", g_number_of_accounts);
  
  
  for(int i =0 ; i <= MAX_NUMBER_OF_ACCOUNTS - 1; i++)
    {
      printf("Eneter a name for account %d :\n", i);
      
      
      if ( scanf("%s", &account[i].name) == *"/r" )
          break;
      
      printf("Eneter inital loan ammount for account %d :\n", i);
      scanf("%f", &account[i].ammount);

      printf("Eneter interest rate for account %d :\n", i);
      scanf("%f", &account[i].rate);
      g_number_of_accounts++;
      
    }

  printf("\n\n\n\tAccount Name\t\tInital Value\t\tInterest Rate\n");
  printf("\t---------------------------------------------------------------\n");
  
  for(int i = 0 ; i <= g_number_of_accounts - 1; i++)
    {
      printf("\t%10s\t\t$%10.2f\t\t%10.2f\%\n", account[i].name,
                account[i].ammount, account[i].rate);
    }

  printf("\nPlease enter your monthly controbution :");
  scanf("%f", g_monthly_payment);
  
//  uint16_t total_payments = Calculate_Payments(0, g_monthly_payment);
  
  //printf("\ntotal number of payments: %d \n", total_payments);
  
  return 0;
}
