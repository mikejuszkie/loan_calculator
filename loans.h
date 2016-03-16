/*************************
 * Loacn Calculator
 * Michael Juszkiewicz
 * loans.h
 *
 ************************/


// include standard libs 
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <inttypes.h>


// check to see if the headder
// has been already included
#ifndef LOANS_H_DEF

// Constant deffinitions

// Set the maximum number of
// accounts for the programm
#ifndef MAX_NUMBER_OF_ACCOUNTS
  #define MAX_NUMBER_OF_ACCOUNTS 10
 #endif
//  
#ifndef MAX_ACCOUNT_NAME_LENGTH
  #define MAX_ACCOUNT_NAME_LENGTH 10
 #endif
// initialize structure
// for number of accounts
 
 struct loan {
   char name [MAX_ACCOUNT_NAME_LENGTH];
   float ammount;
   float rate;
   float interest;
   float principle;
   float ballance;
 };

// function prototype for
// calculating interest
 #ifndef CALCULATE_INTEREST_DEF
  float Calculate_Interest(struct loan* account,
			   uint8_t account_number,
			   uint16_t number_of_days);
  #define CALCULATE_INTEREST_DEF
 #endif

 #ifndef CALCULATE_PAYMENTS_DEF
  uint16_t Calculate_Payments(struct loan* account,
			      uint8_t account_number,
			      float payment);
  #define CALCULATE_PAYMENTS_DEF
 #endif

  
 #ifndef DISPLAY_TABLE_DEF
  void Display_Table();
  #define DISPLAY_TABLE_DEF
 #endif



// define constant for checking
// if file is included
 #define LOANS_H_DEF

#endif
