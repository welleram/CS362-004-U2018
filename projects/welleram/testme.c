//Amy Weller
//CS 362
//Quiz 2

//TO COMPLIE THE FILE RUN
//gcc -o testme testme.c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//Please note, the follow code was leveraging information from stack overflow
//http://stackoverflow.com/questions/19724346/generate-random-characters-in-c

char inputChar(){
    //this would work with any encoding (including EBCDIC, ASCII, UTF-8, ISO-Latin-1)
    //....where each A...Z letter is encoded by a single char.
    //srand(time(NULL));
    char randomletter = "ax[]() {}"[random () % 10];
    return randomletter;
}


//Please note, the follow code was leveraging information from stack overflow
//http://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
char *inputString() {

    static char charset[] = "erst\0";
    char *randomString = NULL;

    if (5) {
        randomString = malloc(sizeof(char) * (5 +1));
        if (randomString) {
            int n;
            for (n = 0;n < 5;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[5] = '\0';
        }
    }

    return randomString;
}


void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1){
    tcCount++;
    c = inputChar();
    //LENGTH IS SET TO 6
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      free(s);
      printf("error ");
      exit(200);
    }
    free(s);
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
