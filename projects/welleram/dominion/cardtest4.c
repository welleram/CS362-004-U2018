//	Amy Weller
//	CS362, Assignment3
//  cardtest4.c  = 4 of 4 card tests
// 	Description: This is a test of the village card in dominion.c


#include <stdio.h>
#include "macros.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv)
{
    printf("#######################VILLAGE CARD TEST #######################\n");
	printf("################################################################\n");
    
    struct gameState state;
    int passed = 0;
	int seed = 10;
	int numPlayers = 2;

    int k[] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, great_hall};
	
    /* initialize 2 player game with seed 10 */
    initializeGame(numPlayers, k, seed, &state);
    
	state.numActions = 0;
    state.handCount[0] = 1;
    state.hand[0][0] = village;
    state.deckCount[0] = 1;
    int test_count = 0;
    
    passed = cardEffect(village, 0, 0, 0, &state, 0,NULL);
    
    printf("\ncardEffect(village): test that village was successfully called and returned.\n" );
    MY_ASSERT(passed == 0);
    if (passed == 0)
    {
        test_count++;
    }
    
    printf("\ncardEffect(village): test that village added 2 actions.\n" );
    MY_ASSERT(state.numActions == 2);
    if (state.numActions == 2)
    {
        test_count++;
    }
    
    
    printf("\ncardEffect(village): test that village has been discarded and a card was added to the hand.\n" );
    MY_ASSERT(state.handCount[whoseTurn(&state)] == 1);
    if (state.handCount[whoseTurn(&state)] == 1)
    {
        test_count++;
    }
    
    printf("\ncardEffect(village): test that village drew a card from the deck.\n");
    MY_ASSERT(state.deckCount[0] == 0);
    if (state.deckCount[0] == 0)
    {
        test_count++;
    }
    
    if (test_count == 4)
    {
        printf("\nTEST SUCCESSFULLY COMPLETED\n");
    }
    
    printf("################################################################\n");
	printf("################################################################\n");

    return 0;
    
}