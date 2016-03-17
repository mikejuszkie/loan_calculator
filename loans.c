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
  printf("interest $%10.2f ", total);
  
  return total;
}


uint16_t Calculate_Payments(struct loan* account,
			    uint8_t account_number,
			    float payment)
{
  
  int number_of_payments = 0;
  int counter = 0;

  while(account[account_number].principle > 0)
    {
      counter++;
      account[account_number].interest = Calculate_Interest(account, account_number, 30);
      account[account_number].principle = account[account_number].principle + (account[account_number].interest - payment);
      number_of_payments++;
      printf("Payments: %4d", number_of_payments);
      printf("\tPrinciple: %10.2f\n", account[account_number].principle);
      if(account[account_number].interest >= payment)
	{
	  printf("payment does not meet minimum payment requerments");
	  break;
	}
    }

 
  
  return number_of_payments;
}

