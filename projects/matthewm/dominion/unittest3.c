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
void testWhoseTurn()
{	

	struct gameState* myState1;
	struct gameState* myState2;
	struct gameState* myState3;
	
	
	myState1 = newGame();
	myState2 = newGame();
	myState3 = newGame();
	
	myState1->whoseTurn = 1;
	
	myState2->whoseTurn = 100;
	
	myState3->whoseTurn = -100;
	

	// Test 1: Player 1
	if (compareInt(whoseTurn(myState1), 1) == 0)
        printf("whoseTurn(): PASS with Player 1\n");
    else
        printf("whoseTurn(): FAIL with Player 1\n");
	
	// Test 2: Player 100 - Should come back invalid (-1)
    if (compareInt(whoseTurn(myState2), -1) == 0)
        printf("whoseTurn(): PASS with Player 100\n");
    else
        printf("whoseTurn(): FAIL with Player 100\n");
	
    // Test 3: Player -100 - Should come back invalid (-1)
    if (compareInt(whoseTurn(myState3), -1) == 0)
        printf("whoseTurn(): PASS with Player -100\n");
    else
        printf("whoseTurn(): FAIL with Player -100\n");
	
    
	
}

int main(int argc, char *argv[])
{
	printf("Start Unit Test 3: whoseTurn()\n");
    testWhoseTurn();
    return 0;
}