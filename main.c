/*************************
 * Loan Calculator
 * Michael Juszkiewicz  
 * main.c
 *
 *************************/

// include standard libs
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

// include custom headders
#include "loans.h"


// initialize global variables
uint8_t g_number_of_accounts = 0;

struct loan account [MAX_NUMBER_OF_ACCOUNTS];

int main()
{

#ifdef DEBUG
	printf("\n\n########### debug build ##############\n\n\n");
#endif


// for loop to start the initial input variables for each loan
// MAX_NUMBER_OF_ACCOUNTS sets the total number of accounts
// that is alowable.
  for(int i =0 ; i < MAX_NUMBER_OF_ACCOUNTS ; i++)
    {
      printf("Enter a name for account %d (enter \"done\" to finish):\n", i);
      scanf("%s", account[i].name);


// This breaks the loop when the user enters "Done"
      if ( !strcmp(account[i].name, "done"))
	  break;

// TODO: BUG-2
// Print out of large numbers result in incorrect printout.
// Subition of a string for float variables results in multiple submissions.
// one might say that people would not borrow that much money.
      printf("Enter inital loan ammount for account %s :\n", account[i].name);
      scanf("%f", &account[i].ammount);
      account[i].principle = account[i].ammount;

      printf("Enter interest rate for account %s :\n", account[i].name);
      scanf("%f", &account[i].rate);
      g_number_of_accounts++;

    }
  printf("\n\n\n\t%-20s| %-15s| %-12s\n", "Account Name",
	 "Inital Ammount","Interest Rate" );
  printf("\t-----------------------------------------------------\n");

  for(int i = 0 ; i < g_number_of_accounts ; i++)
    {
      printf("\t%-20s| $%13.2f | %7.2f%%\n", account[i].name,
                account[i].ammount, account[i].rate);
    }


// TODO: add feature BUG-6
// Add ability to choose for each loan the term agreement 
// or the monthly payments as input.

// loop to collect and calculate monthly payment information
  for(int i = 0 ; i < g_number_of_accounts ; i++)
    {
      printf("\nPlease enter your monthly contribution to %s:", account[i].name);
      scanf("%f", &account[i].monthly_payment);

// force the user to re-enter a value for the monthly payments if that value is to small
      while(account[i].monthly_payment <= 1.25*(30*((account[i].ammount*(account[i].rate/100))/365)))
	{
	  printf("Payment amount is insuficient. Please try again.\n");
	  printf("\nPlease enter your monthly contribution to %s:", account[i].name);
	  scanf("%f", &account[i].monthly_payment);
	}

      Calculate_Payments(account , i , account[i].monthly_payment);

      account[i].total_paid = ( (float)account[i].monthly_payment * 
			account[i].payments ) + account[i].principle;

      #if defined(DEBUG) && DEBUG_LEVEL > 0
         printf("Total cost of %s : $%10.2f \n", account[i].name, account[i].total_paid);
      #endif
    }

// Print out final table of calculations 
  printf("\n%-20s| %-14s| %-14s| %-17s| %-19s| %-20s\n","Account","Loan Ammount",
	 "Interest Rate", "Monthly Payments", "Number of Payments", "Total Paid Back");
  printf("-----------------------------------------------------------");
  printf("---------------------------------------------------\n");

  for(int i = 0 ; i < g_number_of_accounts ; i++)
    {

      printf("%-20s| $%12.2f |%11.2f%%   | $%15.2f |%12d        | $%14.2f\n",
	     account[i].name,account[i].ammount, account[i].rate,
	     account[i].monthly_payment,account[i].payments,
	     account[i].total_paid );

    }


  return 0;
}
