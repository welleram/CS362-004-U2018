//	Amy Weller
//	CS362, Assignment3
//  unittest3.c  = 3 of 4 unit tests
// 	Description: This is a test of the  whoseTurn function in dominion.c

#include <stdio.h>
#include "macros.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv)
{
    printf("###########################UNIT TEST 3 #########################\n");
	printf("################################################################\n");
    int test_count = 0;
    struct gameState* state = malloc(sizeof(struct gameState));
    
    for (int i = 1; i <= 3; i++)
    {
        srand(time(NULL));
        int random = rand();
        state->whoseTurn = random;
        printf("\nwhoseTurn: Successfully Completed Test %i.\n",i);
        MY_ASSERT((whoseTurn(state) == random));
        if (!(whoseTurn(state) == random))
        {
            break;
        }
        test_count++;
    }
    
    MY_ASSERT(test_count == 3);
    if (test_count == 3)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else printf("ONE OR MORE TESTS FAILED!\n");
    
  	printf("################################################################\n");
	printf("################################################################\n");
    
    return 0;
}