//	Amy Weller
//	CS362, Assignment3
//  unittest4.c  = 4 of 4 unit tests
// 	Description: This is a test of the  supplyCount function in dominion.c


#include <stdio.h>
#include "macros.h"
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"

int main ()
{
    printf("###########################UNIT TEST 4 #########################\n");
	printf("################################################################\n");
    
    struct gameState state;
    
    state.supplyCount[province] = 7;
    state.supplyCount[gold] = 9;
    state.supplyCount[curse] = 10;
    state.supplyCount[smithy] = 11;
    
    int test_count = 0;
    
    printf("\nsupplyCount: test for calling supplyCount for province.\n" );
    MY_ASSERT(supplyCount(province, &state) == 7);
    if (supplyCount(province, &state) == 7)
    {
        test_count++;
    }
    
    printf("\nsupplyCount: test for calling supplyCount for gold.\n" );
    MY_ASSERT(supplyCount(gold, &state) == 9);
    if (supplyCount(gold, &state) == 9)
    {
        test_count++;
    }
    
    printf("\nsupplyCount: test for calling supplyCount for curse.\n" );
    MY_ASSERT(supplyCount(curse, &state) == 10);
    if (supplyCount(curse, &state) == 10)
    {
        test_count++;
    }
    
    printf("\nsupplyCount: test for calling supplyCount for smithy.\n" );
    MY_ASSERT(supplyCount(smithy, &state) == 11);
    if (supplyCount(smithy, &state) == 11)
    {
        test_count++;
    }
   
    
    if (test_count == 4)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else printf("ONE OR MORE TESTS FAILED!\n");
    
    printf("################################################################\n");
	printf("################################################################\n");
    
    return 0;
    
}