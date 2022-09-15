/*
*****************************************************************************
						  Workshop - #4 (P2)
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
	int apples_needed = 0, oranges_needed, pears_needed, tomatoes_needed, cabbages_needed, apples_picked, oranges_picked, pears_picked, tomatoes_picked, cabbages_picked, temp = 0, again = 0;
	do
	{
		printf("Grocery Shopping\n================\n");
		do {
			printf("How many APPLES do you need? : ");
			scanf("%d", &apples_needed);
			if (apples_needed < 0)
			{
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (apples_needed < 0);
		printf("\n");
		do {
			printf("How many ORANGES do you need? : ");
			scanf("%d", &oranges_needed);
			if (oranges_needed < 0)
			{
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (oranges_needed < 0);
		printf("\n");
		do {
			printf("How many PEARS do you need? : ");
			scanf("%d", &pears_needed);
			if (pears_needed < 0)
			{
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (pears_needed < 0);
		printf("\n");
		do {
			printf("How many TOMATOES do you need? : ");
			scanf("%d", &tomatoes_needed);
			if (tomatoes_needed < 0)
			{
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (tomatoes_needed < 0);
		printf("\n");
		do {
			printf("How many CABBAGES do you need? : ");
			scanf("%d", &cabbages_needed);
			if (cabbages_needed < 0)
			{
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (cabbages_needed < 0);
		printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");
		if (apples_needed > 0)
		{
			do
			{
				printf("Pick some APPLES... how many did you pick? : ");
				scanf("%d", &apples_picked);
				if (apples_picked > apples_needed)
				{
					printf("You picked too many... only %d more APPLE(S) are needed.\n", apples_needed);
				}
				else if (apples_picked < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (apples_picked < apples_needed)
				{
					printf("Looks like we still need some APPLES...\n");
					temp = apples_needed - apples_picked;
					apples_needed = temp;
					apples_picked = 0;
				}
				else if ((apples_picked = apples_needed))
				{
					printf("Great, that's the apples done!\n\n");
				}
			} while (apples_needed != apples_picked);
		}
		if (oranges_needed > 0)
		{
			do
			{
				printf("Pick some ORANGES... how many did you pick? : ");
				scanf("%d", &oranges_picked);
				if (oranges_picked > oranges_needed)
				{
					printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges_needed);
				}
				else if (oranges_picked < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (oranges_picked < oranges_needed)
				{
					printf("Looks like we still need some ORANGES...\n");
					temp = oranges_needed - oranges_picked;
					oranges_needed = temp;
					oranges_picked = 0;
				}
				else if ((oranges_picked = oranges_needed))
				{
					printf("Great, that's the oranges done!\n\n");
				}
			} while (oranges_needed != oranges_picked);
		}
		if (pears_needed > 0)
		{
			do
			{
				printf("Pick some PEARS... how many did you pick? : ");
				scanf("%d", &pears_picked);
				if (pears_picked > pears_needed)
				{
					printf("You picked too many... only %d more PEAR(S) are needed.\n", pears_needed);
				}
				else if (pears_picked < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (pears_picked < pears_needed)
				{
					printf("Looks like we still need some PEARS...\n");
					temp = pears_needed - pears_picked;
					pears_needed = temp;
					pears_picked = 0;
				}
				else if ((pears_picked = pears_needed))
				{
					printf("Great, that's the pears done!\n\n");
				}
			} while (pears_needed != pears_picked);
		}
		if (tomatoes_needed > 0)
		{
			do
			{
				printf("Pick some TOMATOES... how many did you pick? : ");
				scanf("%d", &tomatoes_picked);
				if (tomatoes_picked > tomatoes_needed)
				{
					printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes_needed);
				}
				else if (tomatoes_picked < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (tomatoes_picked < tomatoes_needed)
				{
					printf("Looks like we still need some TOMATOES...\n");
					temp = tomatoes_needed - tomatoes_picked;
					tomatoes_needed = temp;
					tomatoes_picked = 0;
				}
				else if ((tomatoes_picked = tomatoes_needed))
				{
					printf("Great, that's the tomatoes done!\n\n");
				}
			} while (tomatoes_needed != tomatoes_picked);
		}
		if (cabbages_needed > 0)
		{
			do
			{
				printf("Pick some CABBAGES... how many did you pick? : ");
				scanf("%d", &cabbages_picked);
				if (cabbages_picked > cabbages_needed)
				{
					printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages_needed);
				}
				else if (cabbages_picked < 1)
				{
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (cabbages_picked < cabbages_needed)
				{
					printf("Looks like we still need some CABBAGES...\n");
					temp = cabbages_needed - cabbages_picked;
					cabbages_needed = temp;
					cabbages_picked = 0;
				}
				else if ((cabbages_picked = cabbages_needed))
				{
					printf("Great, that's the cabbages done!\n\n");
				}
			} while (cabbages_needed != cabbages_picked);
		}
		printf("All the items are picked!\n\nDo another shopping? (0=NO): ");
		scanf("%d", &again);
		printf("\n");
	} while ((again != 0));
	printf("Your tasks are done for today - enjoy your free time!\n\n");
	return 0;
}