CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

#getCost()
testGetCost: unittest1.c dominion.o rngs.o
	gcc -o testGetCost unittest1.c -g dominion.o rngs.o $(CFLAGS)

#fullDeckCount()
testFullDeckCount: unittest2.c dominion.o rngs.o
	gcc -o testFullDeckCount unittest2.c -g dominion.o rngs.o $(CFLAGS)

#kingdomCards
testKingdomCards: unittest3.c dominion.o rngs.o
	gcc -o testKingdomCards unittest3.c -g dominion.o rngs.o $(CFLAGS)

#handCard
testHandCard: unittest4.c dominion.o rngs.o
	gcc -o testHandCard unittest4.c -g dominion.o rngs.o $(CFLAGS)

#Smithy
testSmithy: cardtest1.c dominion.o rngs.o
	gcc -o testSmithy -g cardtest1.c dominion.o rngs.o $(CFLAGS)

#Adventurer
testAdventurer: cardtest2.c dominion.o rngs.o
	gcc -o testAdventurer -g cardtest2.c dominion.o rngs.o $(CFLAGS)

#Cutpurse
testCutpurse: cardtest3.c dominion.o rngs.o
	gcc -o testCutpurse -g cardtest3.c dominion.o rngs.o $(CFLAGS)

#CouncilRoom
testCouncilRoom: cardtest4.c dominion.o rngs.o
	gcc -o testCouncilRoom -g cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults: unittestresults.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c
	echo "Result for running Dominion Unit and Card tests:" > unittestresults.out
	
	echo "unittest1.c:" >> unittestresults.out
	gcc -o testGetCost dominion.c rngs.c unittest1.c $(CFLAGS)
	testGetCost >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o testFullDeckCount dominion.c rngs.c unittest2.c $(CFLAGS)
	testFullDeckCount >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o testKingdomCards dominion.c rngs.c unittest3.c $(CFLAGS)
	testKingdomCards >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o testHandCard dominion.c rngs.c unittest4.c $(CFLAGS)
	testHandCard >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o testSmithy dominion.c rngs.c cardtest1.c $(CFLAGS)
	testSmithy >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o testCutpurse dominion.c rngs.c cardtest3.c $(CFLAGS)
	testCutpurse >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o testCouncilRoom dominion.c rngs.c cardtest4.c $(CFLAGS)
	testCouncilRoom >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o testAdventurer dominion.c rngs.c cardtest2.c $(CFLAGS)
	testAdventurer >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe testGetCost testGetCost.exe testFullDeckCount testFullDeckCount.exe testKingdomCards testKingdomCards.exe testHandCard testHandCard.exe testSmithy testSmithy.exe testAdventurer testAdventurer.exe testCutpurse testCutpurse.exe testCouncilRoom testCouncilRoom.exe unittestresults.out
