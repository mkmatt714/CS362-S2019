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
void testGetCost()
{

	// Test 1: Curse
	if (compareInt(getCost(curse), 0) == 0)
        printf("getCost(): PASS with curse\n");
    else
        printf("getCost(): FAIL with curse\n");
	
	// Test 2: Estate
    if (compareInt(getCost(estate), 2) == 0)
        printf("getCost(): PASS with estate\n");
    else
        printf("getCost(): FAIL with estate\n");
	
    // Test 3: Duchy
    if (compareInt(getCost(duchy), 5) == 0)
        printf("getCost(): PASS with duchy\n");
    else
        printf("getCost(): FAIL with duchy\n");
	
    // Test 4: Province
    if (compareInt(getCost(province), 8) == 0)
        printf("getCost(): PASS with province\n");
    else
        printf("getCost(): FAIL with province\n");
	
    // Test 5: Copper
    if (compareInt(getCost(copper), 0) == 0)
        printf("getCost(): PASS with copper\n");
    else
        printf("getCost(): FAIL with copper\n");
	
    // Test 6: Silver
    if (compareInt(getCost(silver), 3) == 0)
        printf("getCost(): PASS with silver\n");
    else
        printf("getCost(): FAIL with silver\n");
	
    // Test 7: Gold
    if (compareInt(getCost(gold), 6) == 0)
        printf("getCost(): PASS with gold\n");
    else
        printf("getCost(): FAIL with gold\n");
	
    // Test 8: Adventurer
    if (compareInt(getCost(adventurer), 6) == 0)
        printf("getCost(): PASS with adventurer\n");
    else
        printf("getCost(): FAIL with adventurer\n");
	
    // Test 9: Council_room
    if (compareInt(getCost(council_room), 5) == 0)
        printf("getCost(): PASS with council_room\n");
    else
        printf("getCost(): FAIL with council_room\n");
	
    // Test 10: Feast
    if (compareInt(getCost(feast), 4) == 0)
        printf("getCost(): PASS with feast\n");
    else
        printf("getCost(): FAIL with feast\n");
	
    // Test 11: Gardens
    if (compareInt(getCost(gardens), 4) == 0)
        printf("getCost(): PASS with gardens\n");
    else
        printf("getCost(): FAIL with gardens\n");
	
    // Test 12: Mine
    if (compareInt(getCost(mine), 5) == 0)
        printf("getCost(): PASS with mine\n");
    else
        printf("getCost(): FAIL with mine\n");
	
    // Test 13: Remodel
    if (compareInt(getCost(remodel), 4) == 0)
        printf("getCost(): PASS with remodel\n");
    else
        printf("getCost(): FAIL with remodel\n");
	
    // Test 14: Smithy
    if (compareInt(getCost(smithy), 4) == 0)
        printf("getCost(): PASS with smithy\n");
    else
        printf("getCost(): FAIL with smithy\n");
	
    // Test 15: Village
    if (compareInt(getCost(village), 3) == 0)
        printf("getCost(): PASS with village\n");
    else
        printf("getCost(): FAIL with village\n");
	
    // Test 16: Baron
    if (compareInt(getCost(baron), 4) == 0)
        printf("getCost(): PASS with baron\n");
    else
        printf("getCost(): FAIL with baron\n");
	
    // Test 17: Great_hall
    if (compareInt(getCost(great_hall), 3) == 0)
        printf("getCost(): PASS with great_hall\n");
    else
        printf("getCost(): FAIL with great_hall\n");
	
    // Test 18: Minion
    if (compareInt(getCost(minion), 5) == 0)
        printf("getCost(): PASS with minion\n");
    else
        printf("getCost(): FAIL with minion\n");
	
    // Test 19: Steward
    if (compareInt(getCost(steward), 3) == 0)
        printf("getCost(): PASS with steward\n");
    else
        printf("getCost(): FAIL with steward\n");
	
    // Test 20: Tribute
    if (compareInt(getCost(tribute), 5) == 0)
        printf("getCost(): PASS with tribute\n");
    else
        printf("getCost(): FAIL with tribute\n");
	
    // Test 21: Ambassador
    if (compareInt(getCost(ambassador), 3) == 0)
        printf("getCost(): PASS with ambassador\n");
    else
        printf("getCost(): FAIL with ambassador\n");
	
    // Test 21: Cutpurse
    if (compareInt(getCost(cutpurse), 4) == 0)
        printf("getCost(): PASS with cutpurse\n");
    else
        printf("getCost(): FAIL with cutpurse\n");
	
    // Test 22: Embargo 
    if (compareInt(getCost(embargo), 2) == 0)
        printf("getCost(): PASS with embargo\n");
    else
        printf("getCost(): FAIL with embargo\n");
	
    // Test 23: Outpost
    if (compareInt(getCost(outpost), 5) == 0)
        printf("getCost(): PASS with outpost\n");
    else
        printf("getCost(): FAIL with outpost\n");
	
    // Test 24: Salvager
    if (compareInt(getCost(salvager), 4) == 0)
        printf("getCost(): PASS with salvager\n");
    else
        printf("getCost(): FAIL with salvager\n");
	
    // Test 25: Sea_hag
    if (compareInt(getCost(sea_hag), 4) == 0)
        printf("getCost(): PASS with sea_hag\n");
    else
        printf("getCost(): FAIL with sea_hag\n");
	
    // Test 26: Treasure_map
	if (compareInt(getCost(treasure_map), 4) == 0)
        printf("getCost(): PASS with treasure_map\n");
    else
        printf("getCost(): FAIL with treasure_map\n");
	
	// Test 27: Treasure_map Wrong
	if (compareInt(getCost(treasure_map), 0) != 0)
		printf("getCost() : PASS with treasure_map wrong value\n");
	else
		printf("getCost() : FAIL with treasure_map wrong value\n");
	
	// Test 28: noCard
	int noCard = 100;
	
	if (compareInt(getCost(noCard), -1) == 0)
		printf("getCost() : PASS with noCard\n");
	else
		printf("getCost() : FAIL with noCard\n");
}	


int main(int argc, char *argv[])
{
	printf("Start Unit Test 2: getCost()\n");
    testGetCost();
    return 0;
}