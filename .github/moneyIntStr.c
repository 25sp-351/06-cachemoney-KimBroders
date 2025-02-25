#include <string.h> // strcpy_s, strcat_s, strlen
#include "moneyIntStr.h"

stringPtr provider = moneyIntStr;

/* Converts an integer of cents into a string of dollars and cents. Max input is 9999999.
** returns a pointer to a static buffer that will be overwritten on the next call to moneyIntStr
** also not re-entrant so don't call from multiple threads
*/
char* moneyIntStr(unsigned int moneyCents) { 
	const char* numStrTable[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty-one", "twenty-two", "twenty-three", "twenty-four",
		"twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty", "thirty-one", "thirty-two", "thirty-three", "thirty-four",
		"thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty", "forty-one", "forty-two", "forty-three", "forty-four",
		"forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty", "fifty-one", "fifty-two", "fifty-three", "fifty-four",
		"fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine", "sixty", "sixty-one", "sixty-two", "sixty-three", "sixty-four",
		"sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine", "seventy", "seventy-one", "seventy-two", "seventy-three", "seventy-four",
		"seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine", "eighty", "eighty-one", "eighty-two", "eighty-three", "eighty-four",
		"eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine", "ninety", "ninety-one", "ninety-two", "ninety-three", "ninety-four",
		"ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine"};
    
    const int centsPerDollar = 100;
    const int centsPerHundredDollars = 10000;
    const int centsPerThousandDollars = 100000;
	static char moneyStr[100];

	moneyStr[0]='\0';
	
	unsigned int thousandDollars = moneyCents / centsPerThousandDollars;
	moneyCents -= thousandDollars * centsPerThousandDollars;
	
	unsigned int hundredDollars = moneyCents / centsPerHundredDollars;
	moneyCents -= hundredDollars * (centsPerHundredDollars);
	
	unsigned int dollars = moneyCents / centsPerDollar;
	unsigned int cents = moneyCents % centsPerDollar;
	
	if (thousandDollars > 0) {
		strcat_s(moneyStr, sizeof(moneyStr), numStrTable[thousandDollars]);
		strcat_s(moneyStr, sizeof(moneyStr), " thousand ");
	}
	if (hundredDollars > 0) {
		strcat_s(moneyStr, sizeof(moneyStr), numStrTable[hundredDollars]);
		strcat_s(moneyStr, sizeof(moneyStr), " hundred ");
	}
	if (dollars > 0) {
		strcat_s(moneyStr, sizeof(moneyStr), numStrTable[dollars]);
		strcat_s(moneyStr, sizeof(moneyStr), " ");
	}

	if (moneyStr[0] != '\0') { // checks if total dollars is nonzero via the string
		strcat_s(moneyStr, sizeof(moneyStr), "dollar");
		
		if (thousandDollars > 0 || hundredDollars > 0 || dollars > 1)
			strcat_s(moneyStr, sizeof(moneyStr), "s");
	}
	
	if (cents > 0) {
		if (moneyStr[0] != '\0') // checks if total dollars is nonzero via the string
			strcat_s(moneyStr, sizeof(moneyStr), " and ");
		
		strcat_s(moneyStr, sizeof(moneyStr), numStrTable[cents]);
		strcat_s(moneyStr, sizeof(moneyStr), " cent");
		
		if (cents > 1)
			strcat_s(moneyStr, sizeof(moneyStr), "s");
	}
	
	if (moneyStr[0] == '\0') // Don't want to accidentally print a blank string
		strcat_s(moneyStr, sizeof(moneyStr), "zero dollars");
	
	return moneyStr; // option 1: return a pointer to a static buffer
}