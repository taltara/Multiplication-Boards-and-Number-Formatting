#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/// function declerations:

void printDynamicBoard(int MaxMult, int choice);
void printFormattedIntergers(char* format, char* numbers);

// instructions were to create one function, then in notes it says to break down the problem to a few functions.
// so I made 1 function for question 2 that is clearly seperated to steps (ie several functions) to be sure.

void printFormattedIntergers(char* format, char* numbers) {

	// extracting the actual decimal value of the numbers in 'numbers' (First Function)

	int phyStore = 1;
	int store = 0;
	int current = 0;
	int indexer = 0;
	int summer = 0;

	// storing said values in a dynamicly made array for safekeeping
	int *nums;
	nums = (int *)calloc(phyStore, sizeof(int));
	printf("%d\n", nums[store]);
	for (int i = 0; numbers[i] != '\0'; i++) {

		if (numbers[i] != ' ') {

			if (numbers[i - 1] == ' ' || (i == 0 && numbers[i] != ' ')) indexer = i;

			if (numbers[i + 1] == ' ' || numbers[i + 1] == '\0') {
				printf("%d\n", indexer);
				for (int j = i; j >= indexer; j--) {

					summer += (((int)(numbers[j] - 48)) * pow(10, current));
					current += 1;
					printf("%d\n", summer);
					
				}

				//printf("%d\n", summer);
				nums[store] = summer;
				current = 0;
				
				store += 1;
				summer = 0;
				

				if ((store == phyStore) && (numbers[i + 1] != '\0')) {
					
					phyStore *= 2;
					nums = (int *)realloc(nums, phyStore * sizeof(int));
				}
				
			}
			
		}

	}

	//-----------------------------------------------------------------------------------------------------------------------------------
	// printing and placing correctly formatted values from 'format' (Second Function)
	
	int place = 0;
	int p = 0;
	int charPlace = 0;
	int temp = 0;
	int romanTemp = 0;
	int tempVal = 0;
	int counter = 0;

						// 2-D array for correct roman letter placement with value
						// 1000,900,500, 400,  100,  90, 80,  70,   60,  50,  40, 30,  20,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1
	char romanC[4][23] = { 'M', 'C', 'D', 'C', 'C', 'X', 'L', 'L', 'L', 'L', 'X', 'X', 'X', 'X', 'I', 'V', 'V', 'V', 'V', 'I', 'I', 'I', 'I',
						   ' ', 'M', ' ', 'D', ' ', 'C', 'X', 'X', 'X', ' ', 'L', 'X', 'X', ' ', 'X', 'I', 'I', 'I', ' ', 'V', 'I', 'I', ' ',
						   ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'I', 'I', ' ', ' ', ' ', 'I', ' ', ' ',
						   ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' '
	};
						// corresponding values for correct subtraction and advancment in next correct roman letter placement
	int  romanI[23] = { 1000, 900, 500, 400, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	char tempStore[100];
	for (int f = 0; f < 100; f++) tempStore[f] = '0';

	for (int t = 0; format[t] != '\0'; t++) {


		if (format[t] == '%') {

			switch (format[t + 1]) {

				// decimal (V)
			case 'd':

				tempVal = nums[place];
				printf("%d", tempVal);
				
				break;
				//-----------------------------------------------------------------------------------------------------------------------------------
				// hexadecimal (V)
			case 'x':

				tempVal = nums[place];
				for (; tempVal != 0 ;) {

					temp = tempVal % 16;

					if		(temp < 10)		tempStore[charPlace] = (char)(48 + temp);
					else if (temp >= 10)	tempStore[charPlace] = (char)(55 + temp);
			
					tempVal = tempVal / 16;
					if (tempVal != 0) charPlace += 1;
				}
				
				for (int i = charPlace; i >= 0; i--) {

					printf("%c", tempStore[i]);
				}
				
				charPlace = 0;

				break;
				//-----------------------------------------------------------------------------------------------------------------------------------
				// octal (V)
			case 'o':

				tempVal = nums[place];
				for (; tempVal != 0;) {

					temp = tempVal % 8;

					tempStore[charPlace] = (char)(48 + temp);

					tempVal = tempVal / 8;
					if (tempVal != 0) charPlace += 1;
				}

				for (int i = charPlace; i >= 0; i--) {

					printf("%c", tempStore[i]);
				}

				charPlace = 0;

				break;
				//-----------------------------------------------------------------------------------------------------------------------------------
				// binary (V)
			case 'b':

				tempVal = nums[place];
				for (; tempVal != 0;) {

					temp = tempVal % 2;

					tempStore[charPlace] = (char)(48 + temp);

					tempVal = tempVal / 2;
					if (tempVal != 0) charPlace += 1;
				}

				for (int i = charPlace; i >= 0; i--) {

					printf("%c", tempStore[i]);
				}

				charPlace = 0;

				break;
				//-----------------------------------------------------------------------------------------------------------------------------------
				// roman (V)
			case 'r':
				
				tempVal = nums[place];
				

				while (tempVal != 0) {

					while (tempVal - romanI[temp] >= 0) {
						
						if (temp >= 5) {
							
							romanTemp = 14;
							while (romanTemp < 23) {

								if ((tempVal - (romanI[temp] + romanI[romanTemp])) >= 0) {

									//printf("\n1.temp %d || romanTemp %d || tempVal %d\n ", temp, romanTemp, tempVal);
									for (p = 0; p < 4; p++) {
										if (romanC[p][temp] != ' ') printf("%c", romanC[p][temp]);
										else;
									}

									tempVal -= (romanI[temp]);

									//printf("\t");
									//printf("\n2.temp %d || romanTemp %d || tempVal %d\n ", temp, romanTemp, tempVal);
									for (p = 0; p < 4; p++) {
										if (romanC[p][romanTemp] != ' ') printf("%c", romanC[p][romanTemp]);
										else;
									}

									tempVal -= (romanI[romanTemp]);
									//printf("\t");
									//tempVal -= (romanI[temp] + romanI[romanTemp]);

								}//printf("\n3.temp %d || romanTemp %d || tempVal %d\n ", temp, romanTemp, tempVal);

								if (tempVal == 0) break;
								romanTemp += 1;

							}
						}
						//printf("\n4.temp %d || romanTemp %d || tempVal %d \n", temp, romanTemp, tempVal);
						if ((tempVal - romanI[temp] >= 0) && (tempVal != 0)) {
							//printf("%d", romanI[temp]);
							for (p = 0; p < 4; p++) {
								if (romanC[p][temp] != ' ') printf("%c", romanC[p][temp]);
								else;
							}
							tempVal -= romanI[temp];
							//printf("\t");
							//printf("%d", tempVal);
						}

						
					}
					
					temp += 1;
				}
				
				break;
			}


			t += 1;
			place += 1;
			tempVal = 0;
			temp = 0;
		}
		else {

			printf("%c", format[t]);
		}

		for (int f = 0; f < 100; f++) tempStore[f] = '0';
	}

	free(nums);
}


// print function for dynamicly determined board
void printDynamicBoard(int MaxMult, int choice) {

	if (choice == 1) MaxMult = 10;
	printf("\n\n");

	int count0 = 0;
	int count1 = 1;
	
	
	for (int limiter = (MaxMult * MaxMult); limiter != 0; limiter = limiter / 10) count1 += 1;

	for (int i = 1; i <= MaxMult; i++) {
		for (int j = 1; j <= MaxMult; j++) {

			for (int times = j * i; times != 0; times = times / 10) count0 += 1;

			for (int space = (count1 - count0); space > 0; space--) printf(" ");

			printf("%d", j * i);
			
			if (j == MaxMult) printf("\n");

			count0 = 0;
		}
	}

}

/// main
int main() {

	int start = 0;

	puts("Hello, & Welcome to Targil #1.");
	puts("What would you like to test?");

	while (start != 1 && start != 2) {

		printf("------------------------------\n");
		printf("| 1) Multiplication Boards   |\n");
		printf("| 2) Formatted Printing      |\n");
		printf("------------------------------\n");

		scanf_s("%d", &start);
		if (start != 1 && start != 2)
			printf("\n%d is an illigal starter. Please start again:\n", start);
	}

	// 1 Multiplication Boards
	if (start == 1) {

		int size = 0;
		int choice = 0;
		int MaxMult = 0;

		printf("What would you like to do? \n");
		printf("------------------------------\n");
		printf("| 1) Create 10x10 Board      |\n");
		printf("| 2) Create Custom Board     |\n");
		printf("------------------------------\n");

		scanf_s("%d", &choice);
		while (choice != 1 && choice != 2 && choice != 3) {

			printf("\n%d is an illigal choice. Please choose again:", choice);
			scanf_s("%d", &choice);
		}

		if		(choice == 1) printDynamicBoard(MaxMult, choice);
		else if (choice == 2) {

			printf("Please enter desired board size: ");
			scanf_s("%d", &MaxMult);

			while (MaxMult <= 0) {

				printf("\n%d is illigal. Please re-enter a valid size:", MaxMult);
				scanf_s("%d", &MaxMult);
			}
			printDynamicBoard(MaxMult, choice);
		}
	}// 2 Formatted Printing
	else if (start == 2) {

		int i = 0;

		char format[200];
		//char numbers[200];
		
		// reference: "Dec: %d Hex: %x Octa: %o Roman %r";
		printf("Please Enter Format (enter '/' when done):\n");

		while (1 == 1) {

			scanf_s("%c", &format[i]);
			if (format[i] == '/') break;
			
			i += 1;
		}
		format[i] = '\0';


		//for (int j = 0; format[j] != '\0'; j++) printf("%c", format[j]);
		//printf("\n");
		//i = 0;

		// reference: " 123 10 16 2321";
		//printf("Please Enter Numbers (enter '/' when done):\n");

		//while (1 == 1) {

		//	scanf_s("%c", &numbers[i]);
		//	if (numbers[i] == '/') break;

		//	i += 1;
		//}
		//numbers[i] = '\0';

		//for (int j = 0; numbers[j] != '\0'; j++) printf("%c", numbers[j]);
		//printf("\n");
		char numbers[100] = " 123 10 16 2321";

		printFormattedIntergers(format, numbers);
	}

	return (0);
}