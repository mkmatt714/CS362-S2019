#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HAND 500
#define MAX_DECK 500
 
int compareInt(int a, int b) {
  if (a > b)
    return 1;
  if (a < b)
    return -1;
  return 0;
}

void testAdventurerCard(int handPos, struct gameState *state) {
	
	printf("Whose Turn %i\n", state->whoseTurn);
	printf("Deck Count %i\n", state->deckCount[state->whoseTurn]);
	printf("Discard Count %i\n", state->discardCount[state->whoseTurn]);
	printf("Played Count %i\n", state->playedCardCount);
	printf("Hand Count %i\n", state->handCount[state->whoseTurn]);
	printf("Adventurer Card %i\n", state->hand[state->whoseTurn][handPos]);
	
	
	// Imputs : struct gameState state, int handPos
	struct gameState preState;
	memcpy (&preState, state, sizeof(struct gameState));
	
	int currentPlayer;
	int results;
	
	results = adventurerCardEffect(handPos, state);
	
	
	// Running Test 1: 
	// Adventurer adds 2 Treasure cards and then is discarded with all cards drawn looking for Treasure
	// Checks to see if post state has two treasure cards more than pre (+3 , -1)
	// Checks to see if post state discarded all cards
	
	currentPlayer = state->whoseTurn;
	
	int iPre;
	int iPost;
	
	int predrawntreasure = 0;
	int postdrawntreasure = 0;
	
	for (iPre = 0; iPre < MAX_HAND; iPre++)
	{
		if (preState.hand[currentPlayer][iPre] == copper || preState.hand[currentPlayer][iPre] == silver || preState.hand[currentPlayer][iPre] == gold)
		{
			predrawntreasure++;
		}
	}
	
	for (iPost = 0; iPost < MAX_HAND; iPost++)
	{
		if (state->hand[currentPlayer][iPost] == copper || state->hand[currentPlayer][iPost] == silver || state->hand[currentPlayer][iPost] == gold)
		{
			postdrawntreasure++;
		}
	}
	
	
	printf("Pre Treasure %i\n", predrawntreasure);
	printf("Post Treasure %i\n", postdrawntreasure);
	
	
	if (compareInt(postdrawntreasure, predrawntreasure + 2) == 0)
        printf("adventurerCardEffect(): PASS with two added treasure cards\n");
    else
        printf("adventurerCardEffect(): FAIL with two added treasure cards\n");
	
	
	
	// Running Test 2: 
	// Checks to see if card is still in the hand position
	
	
    if (compareInt(state->hand[currentPlayer][handPos], state->hand[currentPlayer][handPos]) != 0)
        printf("adventurerCardEffect(): PASS with removed cards\n");
    else
        printf("adventurerCardEffect(): FAIL with removed cards\n");
}



int main(int argc, char *argv[])
{
	printf("Start Random Test 3: Adventurer\n");
	
	// Imputs : struct gameState state, int cardPos
	//int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           //sea_hag, tribute, smithy};
		   
	
	int handPos;
	
	int randomPlayer;
	
	int iterations;
	
	int i;
	
	int i2;
	
	int i3;
	
    struct gameState myState;

		   
		   
	///////
		   
	
	
	SelectStream(2);
	PutSeed(3);
	
	int treasure;
	int iPost;
	
	for(iterations = 0; iterations < 2000; iterations++)
	{
		for(i = 0; i < sizeof(struct gameState); i++)
		{
			((char*)&myState)[i] = floor(Random() * 256);
		}
		randomPlayer = floor(Random() * 4);
		myState.deckCount[randomPlayer] = floor(Random() * 155);
		myState.discardCount[randomPlayer] = floor(Random() * 155);
		myState.handCount[randomPlayer] = floor(Random() * 155);
		myState.playedCardCount = floor(Random() * 155);
		myState.whoseTurn = randomPlayer;
		for(i2 = 0; i2 < MAX_HAND; i2++)
		{
			myState.hand[randomPlayer][i2] = floor(Random() * 27);
		}
		for(i3 = 0; i3 < MAX_DECK; i3++)
		{
			myState.deck[randomPlayer][i3] = floor(Random() * 27);
		}
		
		
		
		// for (iPost = 0; iPost < MAX_HAND; iPost++)
		// {
			// if (myState.hand[randomPlayer][iPost] == copper || myState.hand[randomPlayer][iPost] == silver || myState.hand[randomPlayer][iPost] == gold)
			// {
				// treasure++;
			// }
		// }
		
		handPos = floor(Random() * 10);
		myState.hand[randomPlayer][handPos] = adventurer;
		
		
		
		
		
		testAdventurerCard(handPos, &myState);
	}
	
	
    return 0;
}