#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*This is the time header file, you must include this when you are using random numbers*/
#include <string.h>

#define CARDS 52
#define TYPE 13
#define DRAW 5
#define SORT 4
#define TRUMP 1

struct player_t
{

	int playerCard[DRAW];
	int trumpCard[TRUMP];

}player[6];
void createDeck();
void options();
void draw_a_card(int num[]);


int main()
{
	int deck[CARDS];
	draw_a_card(deck);
	return 0;
}

void createDeck()
{
	int card[CARDS]; // the 'card' array represents all of the cards
	int i = 0, deck_cards;
	// initialization
	for (i = 0; i < CARDS; i++)
		card[i] = i;
	// 'deck_cards' is the limit of the deck, it separates the 
	// cards still inside the deck from the extracted ones
	deck_cards = CARDS;

	// random extraction of five cards
	for (i = 0; i < 52; i++)
	{
		// r is the newly extracted card index
		int r = rand() % deck_cards;

		// the trick is here: we move the choosen card at the current deck
		// limit and decrease the deck size by one.
		// this is accomplished swapping card[r] with card[deck_cards-1]
		int temp = card[r];
		card[r] = card[deck_cards - 1];
		card[deck_cards - 1] = temp;

		deck_cards--;
	}
	// now let't print out the random choosen cards
	//printf("\nShuffled Deck\n");

	for (i = 0; i < 1; i++)
	{
		printf("%d ", card[deck_cards + i] + 1);

	}
}

void draw_a_card(int num[]) /*void because we aren't returning a value*/
{
	char r = 0, s = 0;
	int play = 0;
	FILE *cardgame;
	cardgame = fopen("NewGame.txt", "a");
	if (cardgame == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	printf("Enter how many players in game(2-6)?\n");
	scanf("%d", &play);
	while (play <= 6 && play >= 2)
	{
		//srand(time(NULL));
		for (int i = 0; i < play; i++)
		{

			for (int x = 0; x < 5; x++)
			{
				createDeck();
			}
		}
	}
	fclose(cardgame);
}

void options()
{
	int options;
	printf("Select to Options\n1 for New Game\n2 for Load Game\n3 for Save Game\n0 for Exit\n");
	scanf("%d", &options);
	while (options != 0) {


		switch (options) {
		case 1:
			printf("Welcome to a New Game\n");

			break;
		case 2:
			printf("Welcome to Loaded Game\n");
			break;
		case 3:
			printf("Your has been Saved\n");
			break;
		case 0:
			printf("Thank You for Playing 25\n");
			break;

		default:
			break;
		}
		printf("Select to Options\n1 for New Game\n2 for Load Game\n3 for Save Game\n0 for Exit\n");
		scanf("Choose on [%d]", &options);
	}
}