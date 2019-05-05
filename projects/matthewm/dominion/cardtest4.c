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
void testVillage()
{	

	// Testing should be to make sure that a card has been drawn, that the number of actions increases by two, and that the card is discarded
	
	struct gameState* myState1;
	
	
	myState1 = newGame();
	
	
	int i;
	
	int intVillageCount1 = 0;
	int intVillageCount2 = 0;
	
	// Test 1: Player 1 - 
	int intTest1Player = 1;
	
	myState1->hand[intTest1Player][0] = village;
	myState1->hand[intTest1Player][1] = copper;
	myState1->hand[intTest1Player][2] = copper;
	myState1->hand[intTest1Player][3] = copper;
	
	myState1->handCount[intTest1Player] = 4;

	for (i=0 ; i < 500 ; i++)
	{
		if (myState1->hand[intTest1Player][i] == village)
		{
			intVillageCount1++;
		}
	}
	
	int *intTempHand;
	
	int* intBonus;
	
	int intInitialHandCount;
	
	int intInitialActionCount;
	
	intInitialHandCount = myState1->handCount[intTest1Player];
	
	intInitialActionCount = myState1->numActions;
	
	// Run Test
	cardEffect(village, 0, 0, 0, myState1, 0, intBonus);
	//callVillage(myState1, intTest1Player, intTempHand, 0);
	
	// Hand count should be equal to before - draw one discard one
	if (compareInt(myState1->handCount[intTest1Player], intInitialHandCount) == 0)
	{
		for (i=0 ; i < 500 ; i++)
		{
			if (myState1->hand[intTest1Player][i] == village)
			{
				intVillageCount2++;
			}
		}
		if (compareInt(intVillageCount1 - 1, intVillageCount2) == 0)
		{
			printf("Village card: PASS with Player 1 Discard Card\n");	
		}
		else
			printf("Village card: FAIL with Player 1 Discard Card\n");
		
		if (compareInt(intInitialActionCount, myState1->numActions + 2) == 0)
			{
				printf("Village card: PASS with Player 1\n");
			}
			else
				printf("Village card: FAIL with Player 1 Action Count\n");
	}
    else
        printf("Village card: FAIL with Player 1\n");
	
	
	
    
	
}

int main(int argc, char *argv[])
{
	printf("Start Card Test 4: Village\n");
    testVillage();
    return 0;
}