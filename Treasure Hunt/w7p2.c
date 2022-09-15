/*
*****************************************************************************
						  Workshop - #7 (P1)
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

#define maxPathLength 70 //This is the maximum path length of the program.
#define minPathLength 10//This is the minimum path length of the program.
#define maxLife 10 //This defines that the maximum life the player can have. 
#define minLife 1 //This defines that the minimum life the player can have. 
#define maxMoves 15 //This defines the maximum moves which a player can have.
#define minMoves 3 //This defines the minimum moves which a player can have.
#define sets 5 //This defines the sets of bombs and treasures

int main(void)
{
	int m = 0, temp = 1, tempForDo = 1, i, j = 1; //temp = temperory variable which is declared to help in iteration constructs. i,j = to use while using for loop.
	struct PlayerInfo //This structure is created to save the information of a any player.
	{
		int totalLives, totalTreasures, pastPositions[maxPathLength], treasuresCollected; //maxLives = the lives which the player can have for the game. totalTreasures = total treasures found during the game. pastPositions = it gives the history of all the past positions entered by the player. treasuresCollected = treasures collected by the player.
		char player, movesHistory[maxPathLength]; //This is use to store the symbol which represents the player. movesHistory = to record to moves moved by the player. 
	};
	struct GameInfo //This structure is created to create the game
	{
		int movesAllowed, pathLength, bombs[maxPathLength], treasure[maxPathLength]; //maxMoves = maximum number of moves which a player can have. pathLength = number of positions that a game path will have for the game. bombs = series of 1's and 0's to represent the places where the bombs are burried. treasure = series of 1's and 0's to represent the places where the treasures are burried.
	};
	printf("================================\n         Treasure Hunt!\n================================\n\n");
	printf("PLAYER Configuration\n--------------------\n");
	printf("Enter a single character to represent the player: ");
	struct PlayerInfo playerSetUp; //This utilizes the structure PlayerInfo with the name playerSetUp.
	scanf(" %c", &playerSetUp.player); //This asks the user for the value of variable player and stores it in the playerSetUp variable.
	do //This is used so that untill the user enters the value between 1 and 10, the system will keep asking the same question
	{
		printf("Set the number of lives: ");
		scanf(" %d", &playerSetUp.totalLives); //This asks the user for the maximum number of lives the player can have and stores it in the playerSetUp variable.
		if ((playerSetUp.totalLives >= minLife) && (playerSetUp.totalLives <= maxLife)) //This checks if the value entered by the user is between 1 and maximumlife or not.
		{
			temp = 0; //If the value entered by the user is in defined range, then this variable's value is changed to 0 so that it does not enter the loop again.
			printf("Player configuration set-up is complete\n\n");
		}
		else
		{
			printf("     Must be between %d and %d!\n", minLife, maxLife); //This prints the warning if the player enters the invalid range of input.
		}
	} while (temp); //This checks the value of variable temp. If its 1, the program will enter the loop again.
	printf("GAME Configuration\n------------------\n");
	struct GameInfo gameSetUp; //This utilizes the structure GameInfo with the name gameSetUp.
	temp = 1; //So that the same variable can be reused.
	do //This is used so that untill the user enters the value in valid range, the system will keep asking the same question
	{
		printf("Set the path length (a multiple of 5 between %d-%d): ", minPathLength, maxPathLength);
		scanf(" %d", &gameSetUp.pathLength); //This asks the user for the path length of the game and stores it in the gameSetUp variable.
		if ((gameSetUp.pathLength >= minPathLength) && (gameSetUp.pathLength <= maxPathLength) && (gameSetUp.pathLength % sets == 0)) //This makes sure that the entered path length is between the valid range and a multiple of 5.
		{
			temp = 0; //If the value entered by the user is in defined range, then this variable's value is changed to 0 so that it does not enter the loop again.
		}
		else
		{
			printf("     Must be a multiple of 5 and between %d-%d!!!\n", minPathLength, maxPathLength); //This prints the warning if the player enters the invalid range of input.
		}
	} while (temp); //This checks the value of variable temp. If its 1, the program will enter the loop again.
	temp = 1; //So that the same variable can be reused.
	do //This is used so that untill the user enters the value in valid range, the system will keep asking the same question
	{
		printf("Set the limit for number of moves allowed: ");
		scanf(" %d", &gameSetUp.movesAllowed); //This asks the user for the total number of moves allowed and save the value in the gameSetUp variable
		if ((gameSetUp.movesAllowed >= minMoves) && (gameSetUp.movesAllowed <= maxMoves)) //This will make sure that the value entered by the user is in valid range.
		{
			temp = 0; //If the value entered by the user is in defined range, then this variable's value is changed to 0 so that it does not enter the loop again.
		}
		else
		{
			printf("    Value must be between %d and %d\n", minMoves, maxMoves); //This prints the warning if the player enters the invalid range of input.
		}
	} while (temp); //This checks the value of variable temp. If its 1, the program will enter the loop again.
	printf("\nBOMB Placement\n--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", sets, gameSetUp.pathLength);
	for (i = 0; i < gameSetUp.pathLength; i += sets) //This will print specific range in the bracket.
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + sets);
		for (j = j + i; j <= (sets + i); j++) //This will ask for specific number of entry.
		{
			scanf("%d", &gameSetUp.bombs[j]); //This will scan the places where the user wants to fit the bombs.
		}
		j = 1;
	}
	printf("BOMB placement set");
	printf("\n\nTREASURE Placement\n------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", sets, gameSetUp.pathLength);
	for (i = 0; i < gameSetUp.pathLength; i += sets) //This will print specific range in the bracket.
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + sets);
		for (j = j + i; j <= (sets + i); j++) //This will ask for specific number of entry. i is added to j so that the next time the for loop of j is implimented, the value of j will start from the place where the storage of array was ended.
		{
			scanf("%d", &gameSetUp.treasure[j]); //This will scan the places where the user wants to fit the treasure.
		}
		j = 1; //The j is reinitiallized to 0 so that the next time j loop is implimented, the value of j will start from the place where the storage of array was ended.
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\nTREASURE HUNT Configuration Settings\n------------------------------------\n");
	printf("Player:\n   Symbol     : %c\n   Lives      : %d\n   Treasure   : [ready for gameplay]\n   History    : [ready for gameplay]\n\n", playerSetUp.player, playerSetUp.totalLives);
	printf("Game:\n   Path Length: %d\n   Bombs      : ", gameSetUp.pathLength);
	for (i = 1; i <= gameSetUp.pathLength; i++) //This will help to print all the contents of the array bombs in gameSetUp.
	{
		printf("%d", gameSetUp.bombs[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 1; i <= gameSetUp.pathLength; i++) //This will help to print all the contents of the array treasures in gameSetUp.
	{
		printf("%d", gameSetUp.treasure[i]);
	}
	printf("\n\n====================================\n~ Get ready to play TREASURE HUNT! ~\n====================================\n");
	playerSetUp.treasuresCollected = 0;
	for (i = 1; i <= gameSetUp.pathLength; i++) //This will initial all the positions as undiscovered.
	{
		playerSetUp.movesHistory[i] = '-';
	}
	do
	{
		while (m == 1)
		{
			do
			{
				printf("  ");
			} while (m == 0);
			for (i = 1; i <= j; i++) //This will show the last location of the player.
			{
				if (j == i)
				{
					printf("%c", playerSetUp.player);

				}
				else
				{
					printf(" ");
				}
			}
			m = 0;
		}
		printf("\n  ");
		for (i = 1; i <= gameSetUp.pathLength; i++) //This will show the status of the location. ('-' = Undiscovered Location; '!' = Bombs; '$' = Treasure; '&' = Both Bomb and Treasure)
		{
			printf("%c", playerSetUp.movesHistory[i]);
		}
		printf("\n  ");
		for (i = 1; i <= gameSetUp.pathLength; i++) //This will print position/location ruler (Major).
		{
			if (i % 10 == 0) //Only the tens digit will be printed.
			{
				printf("%d", i / 10);
			}
			else
			{
				printf("|"); //The unit digits will be substituted by '|'.
			}
		}
		printf("\n  ");
		for (i = 1; i <= gameSetUp.pathLength; i++) //This will print position/location ruler (Minor).
		{
			if (i > 9) //This will only print the unit digit
			{
				tempForDo = i / 10;
				printf("%d", i - (tempForDo * 10));
			}
			else
			{
				printf("%d", i);
			}
		}
		tempForDo = 1;
		printf("\n+---------------------------------------------------+\n  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n+---------------------------------------------------+\n", playerSetUp.totalLives, playerSetUp.treasuresCollected, gameSetUp.movesAllowed); //This represents the total lives, treasures and moves remaining.
		temp = 1; //So that the same variable can be reused.
		if ((gameSetUp.movesAllowed != 0) && (playerSetUp.totalLives != 0)) //This will only allow to enter if the player still have lives and moves.
		{
			do
			{
				printf("Next Move [1-%d]: ", gameSetUp.pathLength);
				scanf("%d", &j); //This will ask the player for the next move.
				m = 1;
				if (j > gameSetUp.pathLength || j < 1)
				{
					printf("  Out of Range!!!\n");
				}
				else
				{
					temp = 0; //So that the loop can be exited.
				}
			} while (temp);
			if (playerSetUp.movesHistory[j] != '-') //This makes sure that the player has never been to this location before.
			{
				printf("\n===============> Dope! You've been here before!\n\n");
			}
			else if (gameSetUp.bombs[j] == 1 && gameSetUp.treasure[j] == 1) //This will check if the position contains both the bomb and the treasure.
			{
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				playerSetUp.movesHistory[j] = '&'; //This will add '&' to all the location which the player discovered and where there is both treasure and bomb.
				gameSetUp.movesAllowed--;
				playerSetUp.totalLives--;
				playerSetUp.treasuresCollected++;
			}
			else if (gameSetUp.bombs[j] == 1) //This will check it the position contains bomb.
			{
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
				playerSetUp.movesHistory[j] = '!'; //This will add '&' to all the location which the player discovered and where there is both treasure and bomb.
				gameSetUp.movesAllowed--;
				playerSetUp.totalLives--;
			}
			else if (gameSetUp.treasure[j] == 1) //This will check it the position contains treasure.
			{
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
				playerSetUp.movesHistory[j] = '$'; //This will add '&' to all the location which the player discovered and where there is both treasure and bomb.
				gameSetUp.movesAllowed--;
				playerSetUp.treasuresCollected++;
			}
			else
			{
				printf("\n===============> [.] ...Nothing found here... [.]\n\n");
				playerSetUp.movesHistory[j] = '.'; //This will add '.' to all the location which the player discovered and where there is nothing.
				gameSetUp.movesAllowed--;
			}
			if (playerSetUp.totalLives == 0) //This warn the player that he/she does not have an more life.
			{
				printf("No more LIVES remaining!\n\n");
			}
			else if (gameSetUp.movesAllowed == 0)
			{
				printf("No more MOVES remaining!\n\n"); //This warn the player that he/she does not have an more life.
			}
		}
		else
		{
			printf("\n##################\n#   Game over!   #\n##################");
			tempForDo = 0;
		}

	} while (tempForDo);
	printf("\n\nYou should play again and try to beat your score!\n");
	return 0;
}