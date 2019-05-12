#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    printf("Input Char\n");
	// Create a random character represented by an integer value
	int intRandomInt;
	
	int intMinValue = 32;
	
	int intMaxValue = 126;
	
	//do
	//{
	//	intRandomInt = rand();
	//} while (intRandomInt < intMinValue || intRandomInt > intMaxValue);
	
	intRandomInt = intMinValue + rand() % (intMaxValue - intMinValue);
	
	printf("Input Char2\n");
	
	return intRandomInt;
}

char *inputString()
{
    // TODO: rewrite this function
    // Create a random string of characters represented by an integer value
	// The characters are limited to 5 characters
	
	// Create an array of the 5 possible characters
	char strControl[5] = {'r', 'e', 's', 't', '\0'};
	char strOutput[10];
	
	int intRandomInt;
	
	int intMinValue = 0;
	
	int intMaxValue = 5;
	
	int i;
	
	printf("Input String\n");
	
	strControl[0] = 'r';
	strControl[1] = 'e';
	strControl[2] = 's';
	strControl[3] = 't';
	strControl[4] = '\0';
	for (i=0; i < 6; i++)
	{
		//do
		//{
		//	intRandomInt = rand();
		//} while (intRandomInt < intMinValue || intRandomInt > intMaxValue);
	
		intRandomInt = intMinValue + rand() % (intMaxValue - intMinValue);
		
		strOutput[i] = strControl[intRandomInt];
	}
	
	
	return strOutput;

}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
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
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
	printf("Start Test\n");
    srand(time(NULL));
    testme();
    return 0;
}
