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


// TODO: add feature
// create function for debug printout


// TODO: optimize 
// Remove number of days and account number
float Calculate_Interest(struct loan *account,
			 uint8_t account_number,
			 uint8_t number_of_days)
{
  float total = (account[account_number].principle *
		 ( (account[account_number].rate / 100 )/ 365) ) * number_of_days;

  #ifdef DEBUG_LEVEL 
    printf("interest $%10.2f \n", total);
  #endif  

  return total;
}


uint16_t Calculate_Payments(struct loan* account,
			    uint8_t account_number,
			    float payment)
{
  
  account[account_number].payments = 0;
  

  
  while(account[account_number].principle > 0)
    {

      account[account_number].interest = Calculate_Interest(account, account_number, 30);
      account[account_number].principle = account[account_number].principle +
	(account[account_number].interest - payment);
      account[account_number].payments++;

      #if defined(DEBUG_level) && DEBUG_LEVEL >0 
        printf("Payments: %4d", account[account_number].payments);
        printf("\tPrinciple: %10.2f\n", account[account_number].principle);
      #endif

    }

 
  
  return account[account_number].payments;
}

