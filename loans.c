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


float Calculate_Interest(struct loan account, uint8_t account_number ,uint16_t number_of_days)
{
//  float total = (account[account_number].principle *
//		 (account[account_number].rate / 365) ) * number_of_days;
  float total =0;
  return total;
}


uint16_t Calculate_Payments(struct loan account, uint8_t account_number, float payment)
{
  int number_of_payments = 0;
  float principle = account[account_number].principle;
  float rate = account[account_number].rate;
  float interest = account[account_number].interest;
  float account_ballance = principle + interest;
  
  while(account_ballance > 0)
    {
      interest = Calculate_Interest(account_number, 30);
      
      number_of_payments++;
    }


  
  return number_of_payments;
}
