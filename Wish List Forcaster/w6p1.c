/*
*****************************************************************************
						  Workshop - #6 (P1)
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

#define maxItem 10

int main(void)
{
	int wishListIteams, priority[maxItem], i, temp = 1;
	double sum = 0, income, itemCost[maxItem];
	char finance[maxItem];
	const double min = 500.00, max = 400000.00, minValue = 100.00;
	printf("+--------------------------+\n+   Wish List Forecaster   |\n+--------------------------+\n\n");
	do
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);
		if ((income >= min) && (income <= max))
		{
			temp = 0;
			printf("\n");
		}
		else if (income < min)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (income > max)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
	} while (temp);
	temp = 1;
	do
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &wishListIteams);
		if ((wishListIteams > 0) && (wishListIteams <= maxItem))
		{
			temp = 0;
			printf("\n");
		}
		else
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}
	} while (temp);


	for (i = 0; i < wishListIteams; i++)
	{
		printf("Item-%d Details:\n", i + 1);
		do
		{
			printf("   Item cost: $");
			scanf(" %lf", &itemCost[i]);
			if (itemCost[i] < minValue)
			{
				temp = 1;
				printf("      ERROR: Cost must be at least $100.00\n");
			}
			else
			{
				temp = 0;
			}
		} while (temp);
		temp = 1;
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &priority[i]);
			if ((priority[i] > 0) && (priority[i] <= 3))
			{
				temp = 0;
			}
			else
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				temp = 1;
			}
		} while (temp);
		temp = 1;
		do
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);
			if (finance[i] == 'y' || finance[i] == 'n')
			{
				temp = 0;
				printf("\n");
			}
			else
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				temp = 1;
			}
		} while (temp);
	}
	printf("Item Priority Financed        Cost\n---- -------- -------- -----------\n");

	for (i = 0; i < wishListIteams; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], itemCost[i]);
		sum = sum + itemCost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", sum);
	printf("Best of luck in all your future endeavours!\n\n");
	return 0;
}