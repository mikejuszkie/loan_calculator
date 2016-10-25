/*************************
 * Loan Calculator
 * Michael Juszkiewicz  
 * loans.c
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


// TODO: add feature bug-4
// create function for debug printout


// TODO: add feature bug-7
// implement real date to calculate intrest.
// compinsate for the change in days per month

// Function : calulate the interest contributed over a number of days.
// inputs   : struvture, loan ID, number of days between payments
float Calculate_Interest(struct loan *account,
			 uint8_t account_number,
			 uint8_t number_of_days)
{

// intrest is only applied to the principle ammount daily
  float total = (account[account_number].principle *
		 ( (account[account_number].rate / 100 )/ 365) ) * number_of_days;

// DEBUG pint statment that prints out the ammount of intrest calulated.
  #if defined(DEBUG) && DEBUG_LEVEL > 1 
    printf("\t\tinterest $%10.2f \n", total);
  #endif  

  return total;
}


// Function : calculate the total number of payments it takes to pay off the loan
// inputs   : structure, loan ID, the monthly payment to that account.
// output   : Number of payments to pay off the loan.
uint16_t Calculate_Payments(struct loan* account,
			    uint8_t account_number,
			    float payment)
{

// Zero out the number of payments before calculation
  account[account_number].payments = 0;

// loop checks simulats monthly payments untill the loan has been paid in full    
  while(account[account_number].principle > 0)
    {

      account[account_number].interest = Calculate_Interest(account, account_number, 30);
      account[account_number].principle = account[account_number].principle +
	(account[account_number].interest - payment);
      account[account_number].payments++;

// DEBUG print statement for every payment
      #if defined(DEBUG) && DEBUG_LEVEL > 0 
        printf("Payments: %4d", account[account_number].payments);
        printf("\tPrinciple: %10.2f\n", account[account_number].principle);
      #endif
    }

// submit for the output the number of payments it took to pay loan in full. 
  return account[account_number].payments;
}

