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
void testGreatHall()
{	

	// Testing should make sure that a card is drawn, that the number of actions increases by one, and that the card is discarded
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	struct gameState* myState1;
	struct gameState* myState2;
	struct gameState* myState3;
	
	
	myState1 = newGame();
	myState2 = newGame();
	myState3 = newGame();
	
	initializeGame(4, k, 3, myState1);
	initializeGame(4, k, 3, myState2);
	initializeGame(4, k, 3, myState3);
	
	
	int i;
	
	int intGreatHallCount1 = 0;
	int intGreatHallCount2 = 0;
	
	// Test 1: Player 1 - 
	int intTest1Player = 1;
	
	myState1->hand[intTest1Player][0] = great_hall;
	myState1->hand[intTest1Player][1] = copper;
	myState1->hand[intTest1Player][2] = copper;
	myState1->hand[intTest1Player][3] = copper;
	
	myState1->handCount[intTest1Player] = 4;
	
	for (i=0 ; i < 500 ; i++)
	{
		if (myState1->hand[intTest1Player][i] == great_hall)
		{
			intGreatHallCount1++;
		}
	}
	
	int *intTempHand;
	
	int* intBonus;
	
	int intInitialHandCount;
	
	int intInitialActionCount;
	
	intInitialHandCount = myState1->handCount[intTest1Player];
	
	intInitialActionCount = myState1->numActions;
	
	// Run Test
	cardEffect(great_hall, 0, 0, 0, myState1, 0, intBonus);
	//callGreatHall(myState1, intTest1Player, intTempHand, 0);
	
	// Hand count should be equal to before - draw one discard one
	if (compareInt(myState1->handCount[intTest1Player], intInitialHandCount) == 0)
	{
		for (i=0 ; i < 500 ; i++)
		{
			if (myState1->hand[intTest1Player][i] == great_hall)
			{
				intGreatHallCount2++;
			}
		}
		if (compareInt(intGreatHallCount1 - 1, intGreatHallCount2) == 0)
		{
			if (compareInt(intInitialActionCount, myState1->numActions) == 0)
			{
				printf("Great_Hall card: PASS with Player 1\n");
			}
			else
				printf("Great_Hall card: FAIL with Player 1 Action Count\n");
		}
		else
			printf("Great_Hall card: FAIL with Player 1 Discard Card\n");
	}
    else
        printf("Great_Hall card: FAIL with Player 1\n");
    
	
	// Test 2: Player 2 - Card in last position
	int intTest2Player = 2;
	
	myState2->hand[intTest2Player][0] = copper;
	myState2->hand[intTest2Player][1] = copper;
	myState2->hand[intTest2Player][2] = copper;
	myState2->hand[intTest2Player][3] = great_hall;
	
	myState2->handCount[intTest2Player] = 4;
	
	for (i=0 ; i < 500 ; i++)
	{
		if (myState2->hand[intTest2Player][i] == great_hall)
		{
			intGreatHallCount1++;
		}
	}
	
	
	intInitialHandCount = myState2->handCount[intTest2Player];
	
	intInitialActionCount = myState2->numActions;
	
	// Run Test
	cardEffect(great_hall, 0, 0, 0, myState2, 3, intBonus);
	//callGreatHall(myState2, intTest2Player, intTempHand, 3);
	
	// Hand count should be equal to before - draw one discard one
	if (compareInt(myState2->handCount[intTest2Player], intInitialHandCount) == 0)
	{
		for (i=0 ; i < 500 ; i++)
		{
			if (myState2->hand[intTest2Player][i] == great_hall)
			{
				intGreatHallCount2++;
			}
		}
		if (compareInt(intGreatHallCount1 - 1, intGreatHallCount2) == 0)
		{
			if (compareInt(intInitialActionCount, myState2->numActions) == 0)
			{
				printf("Great_Hall card: PASS with Player 2\n");
			}
			else
				printf("Great_Hall card: FAIL with Player 2 Action Count\n");
		}
		else
			printf("Great_Hall card: FAIL with Player 2 Discard Card\n");
		
	}
    else
        printf("Great_Hall card: FAIL with Player 2\n");
	
}

int main(int argc, char *argv[])
{
	printf("Start Card Test 3: Great_Hall\n");
    testGreatHall();
    return 0;
}