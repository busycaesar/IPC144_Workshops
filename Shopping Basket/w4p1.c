/*
*****************************************************************************
						  Workshop - #4 (P1)
Full Name  : Dev Jigishkumar Shah
Student ID#: 131623217
Email      : djshah11@myseneca.ca
Section    : IPC 144 NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int no_of_times, i = 1;
	char iteration_c;
	printf("+----------------------+\n");
	printf("Loop application STARTED\n");
	printf("+----------------------+\n\n");
	do
	{
		printf("D = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &iteration_c, &no_of_times);
		if ((iteration_c == 'D' || iteration_c == 'W' || iteration_c == 'F') && (no_of_times >= 3 && no_of_times <= 20)) {
			switch (iteration_c)
			{
			case 'D':
				printf("DO-WHILE: ");
				do {
					no_of_times--;
					printf("D");
				} while (no_of_times > 0);
				printf("\n\n");
				break;
			case 'W':
				printf("WHILE   : ");
				while (no_of_times > 0)
				{
					no_of_times--;
					printf("W");
				}
				printf("\n\n");
				break;
			default:
				printf("FOR     : ");
				for (no_of_times = no_of_times; no_of_times > 0; no_of_times--)
				{
					printf("F");
				}
				printf("\n\n");
				break;
			}
		}
		else if (iteration_c == 'Q')
		{
			if (no_of_times == 0)
			{
				i = no_of_times;
				printf("\n+--------------------+\nLoop application ENDED\n+--------------------+\n\n");
			}
			else
			{
				printf("ERROR: To quit, the number of iterations should be 0!\n\n");
			}
		}
		else if ((iteration_c != 'D' && iteration_c != 'W' && iteration_c != 'F' && iteration_c != 'Q') || (no_of_times < 3 || no_of_times > 20))
		{
			if ((iteration_c != 'D' && iteration_c != 'W' && iteration_c != 'F' && iteration_c != 'Q') && (no_of_times < 3 || no_of_times > 20))
			{
				printf("ERROR: Invalid entered value(s)!\n\n");
			}
			else if ((no_of_times < 3 || no_of_times > 20))
			{
				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
			}
			else
			{
				printf("ERROR: Invalid entered value(s)!\n\n");
			}
		}
	} while (i);
	return 0;
}
S