//	Amy Weller
//	CS362, Assignment3
//  unittest2.c  = 2 of 4 unit tests
// 	Description: This is a test of the  buyCard function in dominion.c


#include <stdio.h>
#include "macros.h"
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <time.h>
#include "dominion_helpers.h"


int main(){
    
    printf("###########################UNIT TEST 2 #########################\n");
	printf("################################################################\n");
    
    struct gameState state;
    int s;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    initializeGame(2, k, 2, &state);
    int test_count = 0;
    
    state.numBuys = 0;
    s = buyCard(5, &state);
    
    printf("\nbuyCard: test for calling buyCard with 0 buys.\n" );
    MY_ASSERT(s == -1);
    if(s == -1)
    {
        
        test_count++;
    }
    
    state.numBuys = 5;
    state.coins = 0;
    s = buyCard(5, &state);
    
    printf("\nbuyCard: test for calling buyCard with 0 coins.\n" );
    MY_ASSERT(s == -1)
    if(s == -1)
    {
        test_count++;
    }
    
    state.coins = 30;
    s = buyCard(5, &state);
    
    printf("\nbuyCard: test passed for calling buyCard with too many coins.\n" );
    MY_ASSERT(s == 0)
    if(s == 0)
    {
        test_count++;
    }
    
    if (test_count == 3)
    {
        printf("UNIT TEST 2:  SUCCESSFULLY COMPLETED\n");
    }
    else printf("UNIT TEST 2: ONE OR MORE TESTS FAILED!\n");
    
    return 0;
    
    printf("################################################################\n");
	printf("################################################################\n");
}