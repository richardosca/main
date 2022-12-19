
#include <stdio.h>


/* program defines */
#define TRUE 1				/* boolean true */
#define FALSE 0				/* boolean false */
#define ERRORS 1			/* errors found */
#define NOERRORS 0			/* no errors found */
#define TEMP_MIN -20.0  	/* min. temperature for table*/
#define TEMP_MAX 280.0  	/* max. temperature for table*/
#define VALID_INPUT_MIN 1	/* min. number acceptable input */
#define VALID_INPUT_MAX 9 	/* min. number acceptable input */


/* function prototypes */
float convertToCelsius(float fahr);
float convertToFahr(float celsius);
int isValidInput(int input);




int main(int argc, char *argv[])
{
	/* Declare variables and initialize */
	int step = 0;
	float temp = 0;
	float fahr = 0;
	float celsius = 0;

	/* Prompt the user to enter step */
	printf("Please enter the the conversion step:\n");
	scanf("%d",&step);


	if(isValidInput(step) == TRUE){

		printf("\nFahrenheit\tCelsius\t\tFahrenheit\tCelsius\n");
		printf("-----------------------------------------------------------\n");

		temp = TEMP_MIN;
		while(temp < TEMP_MAX){

			fahr = convertToFahr(temp);
			celsius = convertToCelsius(temp);

			printf("%8.1f\t%6.1f\t%15.1f\t%14.1f\n",temp,celsius,temp,fahr);

			temp += step;
		}
	}else{
		printf("\nInvalid input, make sure you are entering a single digit number 1 - 9\n");
	}

	return NOERRORS;
}


/***************************************************
 Purpose	: Convert from fahrenheit to celsius.
***************************************************/
float convertToCelsius(float fahr){
	return (((fahr - 32) * 5) / 9);
}


/***************************************************
 Purpose	: Convert from celsius to fahrenheit.
***************************************************/
float convertToFahr(float celsius){
	return (((celsius * 9) / 5) + 32);
}




/***************************************************
 Purpose	: Convert from celsius to fahrenheit.
***************************************************/
int isValidInput(int input){
	if((input >= VALID_INPUT_MIN) && (input <= VALID_INPUT_MAX)){
		return TRUE;
	}else {
		return FALSE;
	}
}
