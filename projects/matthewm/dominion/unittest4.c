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
void testNumHandCards()
{	

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
	
	

	// Test 1: Player 1 - 4 Cards in Hand
	int intTest1Player = 1;
	myState1->whoseTurn = 1;
	myState1->handCount[intTest1Player] = 4;
	
	// Test 2: Player 2 - Zero Cards in Hand
	int intTest2Player = 2;
	myState2->whoseTurn = 2;
	myState2->handCount[intTest2Player] = 0;
	
	// Test 3: Player 3 - 501 Cards in Hand
	int intTest3Player = 3;
	myState3->whoseTurn = 3;
	myState3->handCount[intTest3Player] = 501;
	
	
	// Running Test 1
	if (compareInt(numHandCards(myState1), myState1->handCount[intTest1Player]) == 0)
        printf("numHandCount(): PASS with 4 cards\n");
    else
        printf("numHandCount(): FAIL with 4 cards\n");
	
	// Running Test 2: 
	if (compareInt(numHandCards(myState2), myState2->handCount[intTest2Player]) == 0)
        printf("numHandCount(): PASS with 0 cards\n");
    else
        printf("numHandCount(): FAIL with 0 cards\n");
	
	// Running Test 3: Shou;d be -1 because out of range
	if (compareInt(numHandCards(myState3), myState3->handCount[intTest3Player]) != 0)
        printf("numHandCount(): PASS with 501 cards\n");
    else
        printf("numHandCount(): FAIL with 501 cards\n");
	
	
	
    
	
}

int main(int argc, char *argv[])
{
	printf("Start Unit Test 4: numHandCards()\n");
    testNumHandCards();
    return 0;
}