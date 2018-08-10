//	Amy Weller
//	CS362, Assignment3
//  unittest1.c  = 1 of 4 unit tests
// 	Description: This is a test of the  isGameOver function in dominion.c

#include <stdio.h>
#include "macros.h"
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>
#include "dominion_helpers.h"

int main(){
    
    printf("###########################UNIT TEST 1 #########################");
	printf("################################################################");
    struct gameState state;
    int s;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    int test_count = 0;
    
    initializeGame(2, k, 2, &state);
    
    state.supplyCount[province] = 0;
    
    s = isGameOver(&state);
    
    printf("\nisGameOver: test for province supply of 0. \n");
    MY_ASSERT(s==1)
    if(s==1)
    {
        test_count++;
    }
    
    
    state.supplyCount[1] = 0;
    state.supplyCount[5] = 0;
    state.supplyCount[10] = 0;
    s = isGameOver(&state);
    
    printf("\nisGameOver: test for province supply of 0 in 3 piles. \n");
    MY_ASSERT(s==1)
    if(s==1)
    {
        test_count++;
    }
   
    
    if (test_count == 2)
    {
        printf("UNIT TEST 1: TEST SUCCESSFULLY COMPLETED\n");
    }
    else printf("UNIT TEST 1: ONE OR MORE TESTS FAILED!\n");
    
	printf("################################################################\n");
	printf("################################################################\n");
    
    
    return 0;
}