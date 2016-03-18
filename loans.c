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


float Calculate_Interest(struct loan *account,
			 uint8_t account_number,
			 uint16_t number_of_days)
{
  float total = (account[account_number].principle *
		 ( (account[account_number].rate / 100 )/ 365) ) * number_of_days;
  // printf("interest $%10.2f ", total);
  
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

      // Uncomment lines below for debug
      //printf("Payments: %4d", account[account_number].payments);
      //printf("\tPrinciple: %10.2f\n", account[account_number].principle);

    }

 
  
  return account[account_number].payments;
}

