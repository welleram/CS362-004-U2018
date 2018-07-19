/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the Cutpurse card refactored function.
* Updated makefile to include:
*
* testCutpurse: cardtest3.c dominion.o rngs.o
* gcc -o testCutpurse -g cardtest3.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>


int main() {

	struct gameState testGame;
	int testNum = 0;
	int player = -5;
	int handPos = -5;
	int i = -5;
	int j = -5;
	int fxnRtn = -5;
	int choice1 = -5;
	int choice2 = -5;
	int choice3 = -5;
	int bonus = -5;

	player = 1;
	playerX = 0;
	playerY = 2;
	playerZ = 3;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.handCount[player] = 5;
	testGame.hand[player][0] = cutpurse;
	testGame.hand[player][1] = copper;
	testGame.hand[player][2] = tribute;
	testGame.hand[player][4] = silver;
	testGame.hand[player][5] = gold;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	testGame.handCount[playerX] = 5;
	testGame.hand[playerX][0] = minion;
	testGame.hand[playerX][1] = copper;
	testGame.hand[playerX][2] = treasure_map;
	testGame.hand[playerX][4] = embargo;
	testGame.hand[playerX][5] = sea_hag;
	testGame.handCount[playerY] = 5;
	testGame.hand[playerY][0] = village;
	testGame.hand[playerY][1] = feast;
	testGame.hand[playerY][2] = gold;
	testGame.hand[playerY][4] = silver;
	testGame.hand[playerY][5] = outpost;
	testGame.handCount[playerZ] = 5;
	testGame.hand[playerZ][0] = salvager;
	testGame.hand[playerZ][1] = mine;
	testGame.hand[playerZ][2] = gardens;
	testGame.hand[playerZ][4] = smithy;
	testGame.hand[playerZ][5] = ambassador;

	printf("\nBegin Card Test - Cutpurse\n");
	//cardEffect() call
	fxnRtn = cardEffect(cutpurse, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: Correct coin count after the function call
	if (testGame.coins == 8) {
		printf("PASS : current player has 8 coins to spend is correct\n");
	}
	else {
		printf("FAIL: current player has %d coins, correct number of coins is 8\n", testGame.coins);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Cutpurse
	if (testGame.playedCards[0] == cutpurse) {
		printf("PASS : Cutpurse is last card in playedCards\n");
	}
	else {
		printf("FAIL : Cutpurse is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Other PlayerX (0) has a copper
	//Check PlayerX has no copper in their hand
	j = 0;
	for (i = 0; i < 4; ++i) {
		if (testGame.hand[playerX][i] == copper) {
			++j;
		}
	}
	if (j != 0) {
		printf("FAIL : Incorrect number of coppers found in player%d's hand, found %d, correct count is 0\n", playerX, j);
	}
	else {
		printf("PASS : 0 coppers found in player%d's hand\n", playerX);
	}
	//Other Player (2) does NOT have a copper, has other coins
	//Check PlayerY has no copper in their hand
	j = 0;
	for (i = 0; i < 4; ++i) {
		if (testGame.hand[playerY][i] == copper) {
			++j;
		}
	}
	if (j != 0) {
		printf("FAIL : Incorrect number of coppers found in player%d's hand, found %d, correct count is 0\n", playerY, j);
	}
	else {
		printf("PASS : 0 coppers found in player%d's hand\n", playerY);
	}
	//Check for print statements
	printf("PASS/FAIL : PASS if 5 cards are displayed for player%d, otherwise FAIL\n", playerY);
	//Other Player (3) does NOT have a copper, does NOT have other coins
	//Check PlayerZ has no copper in their hand
	j = 0;
	for (i = 0; i < 4; ++i) {
		if (testGame.hand[playerZ][i] == copper) {
			++j;
		}
	}
	if (j != 0) {
		printf("FAIL : Incorrect number of coppers found in player%d's hand, found %d, correct count is 0\n", playerZ, j);
	}
	else {
		printf("PASS : 0 coppers found in player%d's hand\n", playerZ);
	}
	//Check for print statements
	printf("PASS/FAIL : PASS if 5 cards are displayed for player%d, otherwise FAIL\n", playerZ);
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	printf("End Card Test - Cutpurse\n\n");

	return 1;

}

//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
//int cardEffectCutpurse(struct gameState *state, int currentPlayer, int handPos, int i, int j, int k)