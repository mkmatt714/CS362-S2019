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

void testUpdateCoins() {
	
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
	
    struct gameState* myState1;
	struct gameState* myState2;
	struct gameState* myState3;
	struct gameState* myState4;
	struct gameState* myState5;
	struct gameState* myState6;
	struct gameState* myState7;
	struct gameState* myState8;
	
	myState1 = newGame();
	myState2 = newGame();
	myState3 = newGame();
	myState4 = newGame();
	myState5 = newGame();
	myState6 = newGame();
	myState7 = newGame();
	myState8 = newGame();
	
	initializeGame(4, k, 3, myState1);
	initializeGame(4, k, 3, myState2);
	initializeGame(4, k, 3, myState3);
	initializeGame(4, k, 3, myState4);
	initializeGame(4, k, 3, myState5);
	initializeGame(4, k, 3, myState6);
	initializeGame(4, k, 3, myState7);
	initializeGame(4, k, 3, myState8);
	
	
	int i;
	
	// Test 1: Using Player 1 - 1 Copper - 1 Silver - 1 Gold
	int intTest1Player = 1;
	myState1->hand[intTest1Player][0] = copper;
	myState1->hand[intTest1Player][1] = silver;
	myState1->hand[intTest1Player][2] = gold;
	for (i = 3; i < 500; i++)
    {
		myState1->hand[intTest1Player][i] = curse;
	}
	myState1->handCount[intTest1Player] = 500;
	
	// Test 2: Using Player 1 - 1 Copper
	int intTest2Player = 1;
	myState2->hand[intTest2Player][0] = copper;
	for (i = 1; i < 500; i++)
    {
		myState2->hand[intTest2Player][i] = curse;
	}
	myState2->handCount[intTest2Player] = 500;
	
	// Test 3: Using Player 1 - 1 Silver
	int intTest3Player = 1;
	myState3->hand[intTest2Player][0] = silver;
	for (i = 1; i < 500; i++)
    {
		myState3->hand[intTest3Player][i] = curse;
	}
	myState3->handCount[intTest3Player] = 500;
	
	// Test 4: Using Player 4 - 1 Gold
	int intTest4Player = 4;
	myState4->hand[intTest4Player][0] = gold;
	for (i = 1; i < 500; i++)
    {
		myState4->hand[intTest4Player][i] = curse;
	}
	myState4->handCount[intTest4Player] = 500;
	
	// Test 5: Using Player 1 - All Coppers
	int intTest5Player = 1;
	for (i = 0; i < 500; i++)
    {
		myState5->hand[intTest5Player][i] = copper;
	}
	myState5->handCount[intTest5Player] = 500;
	
	// Test 6: Using Player 1 - No Coins
	int intTest6Player = 1;
	for (i = 0; i < 500; i++)
    {
		myState6->hand[intTest6Player][i] = curse;
	}
	myState6->handCount[intTest6Player] = 500;
	
	//**********
	//* Had to stop running this test because it caused a segmentation fault
	//* Function should make sure that player number is withing range
	//**********
	// Test 7: Using Player 100 - Out of bounds player number - 1 Copper
	//int intTest7Player = 100;
	//myState7->hand[intTest7Player][0] = copper;
	
	// Test 8: Using Player 1 - No Coins - Negative Bonus
	int intTest8Player = 1;
	int intTest8Bonus = -5;
	for (i = 0; i < 500; i++)
    {
		myState8->hand[intTest8Player][i] = curse;
	}
	myState8->handCount[intTest8Player] = 500;
	
	
	// Running Test 1: Using Player 1 - 1 Copper - 1 Silver - 1 Gold
    updateCoins(intTest1Player, myState1, 0);
	if (compareInt(myState1->coins, 6) == 0)
        printf("updateCoins(): PASS with one of each coin\n");
    else
        printf("updateCoins(): FAIL with one of each coin\n");
	
	
	// Running Test 2: Using Player 1 - 1 Copper
	updateCoins(intTest2Player, myState2, 0);
    if (compareInt(myState2->coins, 1) == 0)
        printf("updateCoins(): PASS with single copper\n");
    else
        printf("updateCoins(): FAIL with single copper\n");
    
	// Running Test 3: Using Player 1 - 1 Silver
	updateCoins(intTest3Player, myState3, 0);
    if (compareInt(myState3->coins, 2) == 0)
        printf("updateCoins(): PASS with single silver\n");
    else
        printf("updateCoins(): FAIL with single silver\n");
    
	// Running Test 4: Using Player 4 - 1 Gold
	updateCoins(intTest4Player, myState4, 0);
    if (compareInt(myState4->coins, 3) == 0)
        printf("updateCoins(): PASS with single gold\n");
    else
        printf("updateCoins(): FAIL with single gold\n");
	
	// Running Test 5: Using Player 1 - All Coppers
	updateCoins(intTest5Player, myState5, 0);
    if (compareInt(myState5->coins, 500) == 0)
        printf("updateCoins(): PASS with single gold\n");
    else
        printf("updateCoins(): FAIL with single gold\n");
	
	// Running Test 6: Using Player 1 - No Coins
	updateCoins(intTest6Player, myState6, 0);
    if (compareInt(myState6->coins, 0) == 0)
        printf("updateCoins(): PASS with all copper\n");
    else
        printf("updateCoins(): FAIL with all copper\n");
	
	// Running Test 7: Using Player 100 - Out of bounds player number - 1 Copper
	//updateCoins(intTest7Player, myState7, 0);
    //if (compare(myState7->coins, 1) == 0)
    //    printf("updateCoins(): PASS with out of bound player, one copper\n");
    //else
    //    printf("updateCoins(): FAIL with out of bound player, one copper\n");
	
	// Running Test 8: Using Player 1 - No Coins - Negative Bonus
	updateCoins(intTest8Player, myState8, intTest8Bonus);
    if (compareInt(myState8->coins, intTest8Bonus) == 0)
        printf("updateCoins(): PASS with negative Bonus\n");
    else
        printf("updateCoins(): FAIL with negative Bonus\n");
}



int main(int argc, char *argv[])
{
	printf("Start Unit Test 1: updateCoins()\n");
    testUpdateCoins();
    return 0;
}