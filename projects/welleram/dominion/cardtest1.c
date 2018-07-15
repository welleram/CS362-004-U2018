//	Amy Weller
//	CS362, Assignment3
//  cardtest1.c  = 1 of 4 card tests
// 	Description: This is a test of the adventurer card in dominion.c

#include <stdio.h>
#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include "macros.h"
#include "dominion_helpers.h"

int main (int argc, char** argv)
{
    printf("##################PLAY ADVENTURER CARD TEST ####################\n");
	printf("################################################################\n");
    
    struct gameState state;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    initializeGame(2, k, 4, &state);
    
    int handTotal = 0;
    int test_count = 0;
    int discardTotalPrev = 0;
    int discardTotal = 0;
    int i = 0;
    int coinCardCountPrev = 0;
    int coinCardCount = 0;
    
    printf("\nplayAdventurer: test for 5 cards in hand.\n");
    handTotal = numHandCards(&state);
    playAdventurer(&state);
    
    MY_ASSERT(handTotal == 5);
    if (handTotal == 5)
    {
        test_count++;
    }
    
    initializeGame(2, k, 4, &state);
    printf("\nplayAdventurer: test that cards are added to the discard pile.\n");
    discardTotalPrev = state.discardCount[whoseTurn(&state)];
    playAdventurer(&state);
    discardTotal = state.discardCount[whoseTurn(&state)];
    MY_ASSERT(discardTotal >= (discardTotalPrev+2));
    if (discardTotal >= (discardTotalPrev + 2))
    {
        test_count++;
    }
    
    initializeGame(2, k, 4, &state);
    printf("\nplayAdventurer: test that 2 coin cards are added to the hand.\n");
    for (i = 0; i < 5 ; i++)
    {
        if ((state.hand[whoseTurn(&state)][i] == gold) || (state.hand[whoseTurn(&state)][i] == silver) || (state.hand[whoseTurn(&state)][i] == copper))
        {
            coinCardCountPrev++;
        }
        else break;
    }
    playAdventurer(&state);
    for (i = 0; i < 5 ; i++)
    {
        if ((state.hand[whoseTurn(&state)][i] == gold) || (state.hand[whoseTurn(&state)][i] == silver) || (state.hand[whoseTurn(&state)][i] == copper))
        {
            coinCardCount++;
        }
        else break;
    }
    
    MY_ASSERT((coinCardCount == (coinCardCountPrev + 2) || (coinCardCount == 5)))
    if((coinCardCount == (coinCardCountPrev + 2) || (coinCardCount == 5)))
    {
      test_count++;
    }
    
    if (test_count == 3)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    
	printf("################################################################\n");
	printf("################################################################\n");
    
    return 0;
    
}