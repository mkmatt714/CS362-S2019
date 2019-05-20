#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int compareInt(int a, int b) {
  if (a > b)
    return 1;
  if (a < b)
    return -1;
  return 0;
}

void testSmithyCard(struct gameState *state, int handPos) {
	
	printf("Whose Turn %i\n", state->whoseTurn);
	printf("Deck Count %i\n", state->deckCount[state->whoseTurn]);
	printf("Discard Count %i\n", state->discardCount[state->whoseTurn]);
	printf("Played Count %i\n", state->playedCardCount);
	printf("Hand Count %i\n", state->handCount[state->whoseTurn]);
	printf("Smithy Card %i\n", state->hand[state->whoseTurn][handPos]);
	
	
	
	
	
	
	
	
	// Imputs : struct gameState state, int handPos
	struct gameState preState;
	memcpy (&preState, state, sizeof(struct gameState));
	
	int currentPlayer;
	int results;
	
	results = smithyCardEffect(state, handPos);
	
	
	// Running Test 1: 
	// Smithy adds 3 cards and then is discarded
	// Checks to see if post state has two cards more than pre (+3 , -1)
	
	currentPlayer = state->whoseTurn;
	
	printf("Hand Count After Discard %i\n", state->handCount[state->whoseTurn]);
	printf("Played Count After Discard %i\n", state->playedCardCount);
	
	if (compareInt(state->handCount[currentPlayer], preState.handCount[currentPlayer] + 2) == 0)
        printf("smithyCardEffect(): PASS with two added cards\n");
    else
        printf("smithyCardEffect(): FAIL with two added cards\n");
	
	
	
	// Running Test 2: 
	// Checks to see if card is still in the hand position
	
	
    if (compareInt(state->hand[currentPlayer][handPos], preState.hand[currentPlayer][handPos]) != 0)
        printf("smithyCardEffect(): PASS with removed card\n");
    else
        printf("smithyCardEffect(): FAIL with removed card\n");
}



int main(int argc, char *argv[])
{
	printf("Start Random Test 1: Smithy\n");
	
	// Imputs : struct gameState state, int cardPos
	//int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           //sea_hag, tribute, smithy};
		   
	int handPos;
	
	int randomPlayer;
	
	int iterations;
	
	int i;
	
    struct gameState myState;
	
	SelectStream(2);
	PutSeed(3);
	
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
		handPos = floor(Random() * 10);
		myState.hand[randomPlayer][handPos] = smithy;
		testSmithyCard(&myState, handPos);
	}
	
	
    return 0;
}
