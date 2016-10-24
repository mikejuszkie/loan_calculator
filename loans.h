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


//DEBUG token
#ifndef DEBUG_ON
   #define DEBUG_ON 1
#endif

#ifndef DEBUG_OFF
   #define DEBUG_OFF 0
#endif

#ifndef DEBUG_LEVEL
  #define DEBUG_LEVEL 1
#endif


// define constant for checking
// if file is included
 #define LOANS_H_DEF


// Constant deffinitions

// Set the maximum number of
// accounts for the programm
 #ifndef MAX_NUMBER_OF_ACCOUNTS
  #define MAX_NUMBER_OF_ACCOUNTS 10
 #endif

// Sets the max number of characters
// used in an account's name
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
   float monthly_payment;
   int payments;
   float total_paid;
 };

// function prototype for
// calculating interest
 #ifndef CALCULATE_INTEREST_DEF
  float Calculate_Interest(struct loan *account,
			   uint8_t account_number,
			   uint8_t number_of_days);
  #define CALCULATE_INTEREST_DEF
 #endif


// function prototype for
// calculating number of payments 
 #ifndef CALCULATE_PAYMENTS_DEF
  uint16_t Calculate_Payments(struct loan *account,
			      uint8_t account_number,
			      float payment);
  #define CALCULATE_PAYMENTS_DEF
 #endif

// function proto type to display
// a table of the accounts
 #ifndef DISPLAY_TABLE_DEF
  void Display_Table(struct loan *account);
  #define DISPLAY_TABLE_DEF
 #endif


#endif
