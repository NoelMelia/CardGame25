#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*This is the time header file, you must include this when you are using random numbers*/
#include <string.h>

#define CARDS 52
#define TYPE 13
#define DRAW 5
#define SORT 4
#define ONE 1

struct player_t
{

	int playerCard[DRAW];
	int trumpCard[ONE];
	int playerScore[ONE];

}player[6];
char rand_int(char num);
void options();
void draw_a_card();
void pickcard();
void openingFile();


int main()
{
	srand((unsigned)time(NULL));
	options();
	return 0;
}

char rand_int(char num)
{
	int number;
	number = rand() % num;
	if (number == 1)
	{

	}
	number = rand() % num;
	return number; /*Returns a number from 0 to N-1*/
}

void draw_a_card() /*void because we aren't returning a value*/
{
	int r = 0;

	int play = 0;


	//Creating a new txt file to store info
	FILE *cardgame;
	cardgame = fopen("NewGame.txt", "w");
	if (cardgame == NULL)
	{
		printf("Error opening file!\n");//Checking to see if file is empty
		exit(1);
	}

	printf("Enter how many players in game(2-6)?\n");
	scanf("%d", &play);
	if (play <= 6 && play >= 2)
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < play; i++)
		{
			printf("Player %d\n", i + 1);
			for (int x = 0; x < 5; x++)
			{

				player[i].playerCard[r] = rand_int(CARDS); /*Receives a number back from 0 to 12*/

				switch (player[i].playerCard[r] % 13)
				{
				case 0:
					printf(" A");
					break;
				case 1:
					printf(" 2");
					break;
				case 2:
					printf(" 3");
					break;
				case 3:
					printf(" 4");
					break;
				case 4:
					printf(" 5");
					break;
				case 5:
					printf(" 6");
					break;
				case 6:
					printf(" 7");
					break;
				case 7:
					printf(" 8");
					break;
				case 8:
					printf(" 9");
					break;
				case 9:
					printf(" 10");
					break;
				case 10:
					printf(" J");
					break;
				case 11:
					printf(" Q");
					break;
				case 12:
					printf(" K");
					break;
				default:
					break;
				}

				switch (player[i].playerCard[r] % 4)
				{
				case 0:
					printf("S ");
					break;
				case 1:
					printf("D ");
					break;
				case 2:
					printf("C ");
					break;
				case 3:
					printf("H ");
					break;
				default:
					break;
				}

				fprintf(cardgame, "%d ", player[i].playerCard[r]);
			}
			player[i].playerScore[r] = 0;
			printf("Player Score = %d\n", player[i].playerScore[r]);
			fprintf(cardgame, "  %d\n", player[i].playerScore[r]);
			printf("\n");

			fprintf(cardgame, "\n");
			printf("\n");
		}

		for (int x = 0; x < 1; x++)
		{
			printf("\nTrump Card ");
			player[x].trumpCard[r] = rand_int(CARDS); /*Receives a number back from 0 to 12*/
			switch (player[x].trumpCard[r] % 13)
			{
			case 0:
				printf(" A");
				break;
			case 1:
				printf(" 2");
				break;
			case 2:
				printf(" 3");
				break;
			case 3:
				printf(" 4");
				break;
			case 4:
				printf(" 5");
				break;
			case 5:
				printf(" 6");
				break;
			case 6:
				printf(" 7");
				break;
			case 7:
				printf(" 8");
				break;
			case 8:
				printf(" 9");
				break;
			case 9:
				printf(" 10");
				break;
			case 10:
				printf(" J");
				break;
			case 11:
				printf(" Q");
				break;
			case 12:
				printf(" K");
				break;
			default:
				break;
			}

			switch (player[x].trumpCard[r] % 4)
			{
			case 0:
				printf("S ");
				break;
			case 1:
				printf("C ");
				break;
			case 2:
				printf("D ");
				break;
			case 3:
				printf("H ");
				break;
			default:
				break;
			}

			//printf("%d",player[x].playerCard[r]);

			fprintf(cardgame, "\nTrump Card %d \n", player[x].trumpCard[r]);


			/*printf("\n\nPlease pick between players to begin?");
			scanf("%d", player[x]);*/

			//for (int i = 0; i <= player[x]; i++)
			//{

			//}
			//if (player[x] == '0')
			//{

			//}

		}
		fclose(cardgame);


	}
	else
	{
		printf("Please Try again to enter");

	}

}

void openingFile()
{
	char c[1000];
	FILE *fptr;
	if ((fptr = fopen("NewGame.txt", "r")) == NULL)
	{
		printf("Error! opening file");
		// Program exits if file pointer returns NULL.
		exit(1);
	}
	else {
		printf("Game is Loading");
		fscanf(fptr, "%[^\n]", c);

		printf("Data from the file:\n%s", c);

		// reads text until newline 
	}




	fclose(fptr);
}

//void pickcard()
//{
//	if(player[])
//}



void options()
{
	int card = 0;

	int options = 0;

	printf("\nSelect to Options\n1 for New Game\n2 for Load Game\n3 for Save Game\n0 for Exit\n");
	scanf("%d", &options);
	while (options != 0)
	{
		switch (options)
		{
		case 1:
			printf("Welcome to a New Game\n");
			draw_a_card();

			break;
		case 2:
			printf("Welcome to Loaded Game\n");
			openingFile();
			break;
		case 3:
			printf("Your game will be Saved\n");

			break;
		case 0:
			printf("Thank You for Playing 25\n");
			break;

		default:
			printf("Please Selection a Correct Option\n");
			break;
		}
		printf("\n\nSelect Options\n1 to New Game\n2 for Load Game\n3 for Save Game\n0 for Exit\n");
		scanf("%d", &options);
	}
}



