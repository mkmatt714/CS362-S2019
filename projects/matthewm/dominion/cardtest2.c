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
	
	//*
void testSmithy()
{
	
	// Testing should make sure that three cards are drawn, and that the card is discarded
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
	
	struct gameState* myState1;
	struct gameState* myState2;
	
	
	
	myState1 = newGame();
	myState2 = newGame();
	
	
	initializeGame(4, k, 3, myState1);
	initializeGame(4, k, 3, myState2);
	
	
	int i;
	
	int intSmithyCount1 = 0;
	int intSmithyCount2 = 0;
	
	// Test 1: Player 1 - 
	int intTest1Player = 1;
	
	myState1->hand[intTest1Player][0] = smithy;
	myState1->hand[intTest1Player][1] = copper;
	myState1->hand[intTest1Player][2] = copper;
	myState1->hand[intTest1Player][3] = copper;
	
	myState1->handCount[intTest1Player] = 4;
	
	for (i=0 ; i < 500 ; i++)
	{
		if (myState1->hand[intTest1Player][i] == smithy)
		{
			intSmithyCount1++;
		}
	}
	
	int *intTempHand;
	
	int intInitialHandCount;
	
	int* intBonus;
	
	intInitialHandCount = myState1->handCount[intTest1Player];
	
	// Run Test
	
	cardEffect(smithy, 0, 0, 0, myState1, 0, intBonus);
	//callSmithy(myState1, intTest1Player, intTempHand, 0);
	
	// Hand count should be 2 more than before - draw three discard one
	if (compareInt(myState1->handCount[intTest1Player], intInitialHandCount + 2) == 0)
	{
		for (i=0 ; i < 500 ; i++)
		{
			if (myState1->hand[intTest1Player][i] == smithy)
			{
				intSmithyCount2++;
			}
		}
		if (compareInt(intSmithyCount1 - 1, intSmithyCount2) == 0)
		{
			printf("Smithy card: PASS with Player 1\n");
		}
	}
    else
        printf("Smithy card: FAIL with Player 1\n");
	


	
	

	intSmithyCount1 = 0;
	intSmithyCount2 = 0;
	
	// Test 2: Player 2 - Smithy in last position
	int intTest2Player = 2;
	
	myState2->hand[intTest2Player][0] = copper;
	myState2->hand[intTest2Player][1] = copper;
	myState2->hand[intTest2Player][2] = copper;
	myState2->hand[intTest2Player][3] = smithy;
	
	myState2->handCount[intTest2Player] = 4;
	
	for (i=0 ; i < 500 ; i++)
	{
		if (myState2->hand[intTest2Player][i] == smithy)
		{
			intSmithyCount1++;
		}
	}
	

	
	intInitialHandCount = myState2->handCount[intTest2Player];
	
	// Run Test
	
	cardEffect(smithy, 0, 0, 0, myState2, 3, intBonus);
	//callSmithy(myState2, intTest2Player, intTempHand, 3);
	
	// Hand count should be 2 more than before - draw three discard one
	if (compareInt(myState2->handCount[intTest2Player], intInitialHandCount + 2) == 0)
	{
		for (i=0 ; i < 500 ; i++)
		{
			if (myState2->hand[intTest2Player][i] == smithy)
			{
				intSmithyCount2++;
			}
		}
		if (compareInt(intSmithyCount1 - 1, intSmithyCount2) == 0)
		{
			printf("Smithy card: PASS with Player 2\n");
		}
	}
    else
        printf("Smithy card: FAIL with Player 2\n");
	


	
}


int main(int argc, char *argv[])
{
	printf("Start Card Test 2: Smithy\n");
    testSmithy();
    return 0;
}