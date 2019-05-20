#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>




int compareInt(int a, int b) {
  if (a > b)
    return 1;
  if (a < b)
    return -1;
  return 0;
}



void testAdventurer() {
	
	// Testing should make sure that two coin cards are added to the hand
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
    struct gameState* myState1;
	struct gameState* myState2;
	
	
	myState1 = newGame();
	myState2 = newGame();
	
	
	initializeGame(4, k, 3, myState1);
	initializeGame(4, k, 3, myState2);
	
	
	int intTempHand[500];
	int i;
	
	// Test 1: Player 1 - 
	int intTest1Player = 1;
	int intInitialAdventurerCount = 0;
	int intInitialCoinCount = 0;
	
	myState1->hand[intTest1Player][0] = adventurer;
	myState1->hand[intTest1Player][1] = copper;
	myState1->hand[intTest1Player][2] = copper;
	myState1->hand[intTest1Player][3] = copper;
	
	myState1->deck[intTest1Player][0] = copper;
	myState1->deck[intTest1Player][1] = smithy;
	myState1->deck[intTest1Player][2] = copper;
	
	myState1->handCount[intTest1Player] = 500;
	myState1->deckCount[intTest1Player] = 3;
	
	
	for (i=0; i < myState1->handCount[intTest1Player]; i++)
	{
		if (myState1->hand[intTest1Player][i] == adventurer)
		{
			intInitialAdventurerCount++;
		}
	}
	
	
	for (i=0; i < myState1->handCount[intTest1Player]; i++)
	{
		if (myState1->hand[intTest1Player][i] == copper || myState1->hand[intTest1Player][i] == silver || myState1->hand[intTest1Player][i] == gold)
		{
			intInitialCoinCount++;
		}
	}
	
	
	// Run Test 1
	int intAdventurerCount = 0;
	int intCoinCount = 0;
	
	int* intBonus;
	
	cardEffect(adventurer, 0, 0, 0, myState1, 0, intBonus);
	//callAdventurer(myState1, intTest1Player, &intTempHand);
	
	for (i=0; i < myState1->handCount[intTest1Player]; i++)
	{
		if (myState1->hand[intTest1Player][i] == adventurer)
		{
			intAdventurerCount++;
		}
	}
	
	
	
	for (i=0; i < myState1->handCount[intTest1Player]; i++)
	{
		if (myState1->hand[intTest1Player][i] == copper || myState1->hand[intTest1Player][i] == silver || myState1->hand[intTest1Player][i] == gold)
		{
			intCoinCount++;
		}
	}
	
	
	if (compareInt(intInitialAdventurerCount - 1, intAdventurerCount) == 0)
        printf("Adventurer card: PASS with discard\n");
    else
        printf("Adventurer card: FAIL with discard\n");
	
	if (compareInt(intInitialCoinCount + 2, intCoinCount) == 0)
        printf("Adventurer card: PASS with adding 2 coins\n");
    else
        printf("Adventurer card: FAIL with adding 2 coins\n");
	
	
	
	// Test 2: Player 1 - 
	int intTest2Player = 1;
	intInitialAdventurerCount = 0;
	intInitialCoinCount = 0;
	
	myState2->hand[intTest2Player][0] = gold;
	myState2->hand[intTest2Player][1] = adventurer;
	myState2->hand[intTest2Player][2] = copper;
	myState2->hand[intTest2Player][3] = copper;
	
	myState2->deck[intTest2Player][0] = copper;
	myState2->deck[intTest2Player][1] = smithy;
	myState2->deck[intTest2Player][2] = curse;
	
	myState2->handCount[intTest2Player] = 4;
	myState2->deckCount[intTest2Player] = 3;
	
	for (i=0; i < myState2->handCount[intTest2Player]; i++)
	{
		if (myState2->hand[intTest2Player][i] == adventurer)
		{
			intInitialAdventurerCount++;
		}
	}
	
	for (i=0; i < myState2->handCount[intTest2Player]; i++)
	{
		if (myState2->hand[intTest2Player][i] == copper || myState2->hand[intTest2Player][i] == silver || myState2->hand[intTest2Player][i] == gold)
		{
			intInitialCoinCount++;
		}
	}
	
	// Run Test 2
	intAdventurerCount = 0;
	intCoinCount = 0;
	
	cardEffect(adventurer, 0, 0, 0, myState2, 1, intBonus);
	//callAdventurer(myState2, intTest2Player, intTempHand);
	
	for (i=0; i < myState2->handCount[intTest2Player]; i++)
	{
		if (myState2->hand[intTest2Player][i] == adventurer)
		{
			intAdventurerCount++;
		}
	}
	
	for (i=0; i < myState2->handCount[intTest2Player]; i++)
	{
		if (myState2->hand[intTest2Player][i] == copper || myState2->hand[intTest2Player][i] == silver || myState2->hand[intTest2Player][i] == gold)
		{
			intCoinCount++;
		}
	}
	
	
	
	if (compareInt(intInitialAdventurerCount - 1, intAdventurerCount) == 0)
        printf("Adventurer card w/ Shuffle: PASS with discard\n");
    else
        printf("Adventurer card w/ Shuffle: FAIL with discard\n");
	
	if (compareInt(intInitialCoinCount + 2, intCoinCount) == 0)
        printf("Adventurer card w/ Shuffle: PASS with adding 2 coins\n");
    else
        printf("Adventurer card w/ Shuffle: FAIL with adding 2 coins\n");
	
	
}



int main(int argc, char *argv[])
{
	printf("Start Card Test 1: Adventurer\n");
    testAdventurer();
    return 0;
}