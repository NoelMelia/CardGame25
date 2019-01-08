#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*This is the time header file, you must include this when you are using random numbers*/


#define CARDS 52
#define TYPE 13
#define DRAW 5
#define SORT 4
#define ONE 1
#define TWENTYFIVE 25
#define FIVE 5


struct player_t
{
	int playerCard[DRAW];
	int trumpCard[ONE];
	int playerScore[ONE];

}player[6];//struct player with up to 6 players

char suits[SORT] = { 'S','D','C','H' };

char ranks[TYPE] = { 'A','2','3','4','5','6','7','8','9','10','J','Q','K' };


char rand_int(char num);
void options();
void draw_a_card();
//void pickcard();
void openingFile();
int remove(int deck[]);



void main()
{

	srand((unsigned)time(NULL));//random the number
	options();//calling the function
	
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
	int r = 0;//variables
	int play = 0;

	//Creating a new txt file to store info
	FILE *cardgame;
	cardgame = fopen("NewGame.txt", "w");//creating a txt file NewGame and it has a write previse
	if (cardgame == NULL)//checking to see if txt file is empty
	{
		printf("Error opening file!\n");//Checking to see if file is empty
		exit(1);
	}//if

	printf("Enter how many players in game(2-6)?\n");//asking user how many players
	scanf("%d", &play);
	if (play <= 6 && play >= 2)
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < play; i++)//generating loop for dealing cards for each player
		{
			player[i].playerScore[r] = 0;//struct of player score
			printf("Player %d\n", i + 1);
			for (int x = 0; x < DRAW; x++)//dealing 5 cards
			{
				
				player[i].playerCard[r] =rand_int(CARDS); //Generating a number for the random number and storing in the sttruct position for the player card

				switch (player[i].playerCard[r] % 13)//to convert each card number to a card rank
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
				}//switch

				switch (player[i].playerCard[r] % 4)//to convert each card number to a card rank
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
				}//switch

				fprintf(cardgame, "%d ", player[i].playerCard[r]);//printing card out to the txt file in number format
			}//for card
			
			printf("Player Score = %d\n", player[i].playerScore[r]);//printing out score to screen and txt file
			fprintf(cardgame,"  %d\n", player[i].playerScore[r]);
			printf("\n");

			fprintf(cardgame, "\n");
			printf("\n");
		}//for play

		for (int x = 0; x < 1; x++)
		{
			printf("\nTrump Card ");
			player[x].trumpCard[r] = rand_int(CARDS);//store card in trumpcard struct in player
			switch (player[x].trumpCard[r] % 13)//converting the trump card to a rank
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

			switch (player[x].trumpCard[r] % 4)//convert the number to a suit
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
			}//switch
			
			//printf("%d",player[x].playerCard[r]);

			fprintf(cardgame, "\nTrump Card %d \n",  player[x].trumpCard[r]);//Generating a number for the random number and storing in the sttruct position for the trunmp card

			
			/*printf("\n\nPlease pick between players to begin?");//started tom try and get the user to pick the pklayer to begin game
			scanf("%d", player[x]);*/

			//for (int i = 0; i <= player[x]; i++)
			//{

			//}
			//if (player[x] == '0')
			//{

			//}

		}//for
		fclose(cardgame);//close of the txt file		
	}//if
	else
	{
		printf("Please Try again to enter");
	}//else
	
}

void openingFile()
{
	char c[CARDS];
	int change;
	FILE *fptr;
	if ((fptr = fopen("NewGame.txt", "r")) == NULL)
	{
		printf("Error! opening file");
		// Program exits if file pointer returns NULL.
		exit(1);
	}//if
	else 
	{
		printf("Game is Loading\n");
		change = fscanf(fptr, "%[^\n]", c);

			printf("Data from the file:\n%s\n", c);

	
			

		
		// reads text until newline 
	}//else
	fclose(fptr);
}//openingfile

//void pickcard()
//{
//	if(player[])
//}

void options()
{
	int options = 0;

	printf("\nSelect to Options\n1 for New Game\n2 for Load Game\n3 for Save Game\n0 for Exit\n");//getting the user to select a number of options
	scanf("%d", &options);
	while (options != 0)
	{
		switch (options)
		{
		case 1://New Game
			printf("Welcome to a New Game\n");
			draw_a_card();

			break;
		case 2://Loaded Game
			printf("Welcome to Loaded Game\n");
			openingFile();
			break;
		case 3://Save Game
			printf("Your game will be Saved\n");

			break;
		case 0://Exit
			printf("Thank You for Playing 25\n");
			break;

		default://If correct number wasnt selected
			printf("Please Selection a Correct Option!!!!!\n");
			break;
		}
		printf("\n\nSelect Options\n1 to New Game\n2 for Load Game\n3 for Save Game\n0 for Exit\n");
		scanf("%d", &options);
	}//while
}//options

int remove(int deck[])//Started a method to remove card from hand
{
	int point, c;

	for (c = 0; c < DRAW; c++)
	{
		printf("Card No %d : %d \n", c + 1, deck[c]);

	}
	return 0;
}


