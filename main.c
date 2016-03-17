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
float g_total_principle = 0.00;
float g_total_interest = 0.00;
float g_account_total = 0.00;
int g_number_of_accounts = 0;
float g_monthly_payment = 0.00;

int length;

struct loan account [MAX_NUMBER_OF_ACCOUNTS];

int main()
{
  for(int i =0 ; i <= MAX_NUMBER_OF_ACCOUNTS - 1; i++)
    {
      printf("Eneter a name for account %d (enter \"done\" to finish):\n", i);
      scanf("%s", account[i].name);
            
      if ( *account[i].name == *"done" )
	  break;

      
      printf("Eneter inital loan ammount for account %d :\n", i);
      scanf("%f", &account[i].ammount);
      account[i].principle = account[i].ammount;
      
      printf("Eneter interest rate for account %d :\n", i);
      scanf("%f", &account[i].rate);
      g_number_of_accounts++;
      
    }
  printf("\n\n\n\t%-20s|%-20s|%-20s\n", "Account Name",
	 "Inital Ammount","Interest Rate" );
  printf("\t---------------------------------------------------------------\n");
  
  for(int i = 0 ; i <= g_number_of_accounts - 1; i++)
    {
      printf("\t%-20s|$%19.2f|%20.2f%%\n", account[i].name,
                account[i].ammount, account[i].rate);
    }

  printf("\nPlease enter your monthly controbution :");
  scanf("%f", &g_monthly_payment);

  Calculate_Payments(account, 0, g_monthly_payment);
  

  return 0;
}
