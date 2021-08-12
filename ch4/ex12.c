/* adapt the ideas of printd to write a recursive version of itoa; that is,
 * convert an integer into a string by calling a recursive routine 
 * 3.1.17  6:17 pm to 
 */

#include<stdio.h>
#define MAXSIZE 50 

int ip = 0;
void itoa(int, char []);	

void main()
{
	char s[MAXSIZE];
	int x = 987.56;

	itoa(x, s);
	s[ip] = '\0';
	printf(" the string is %s", s);
}

/* itoa: convert an integer into a string by calling a recursive function */
void itoa(int x, char s[])
{
	if(x/10)
		itoa(x/10, s);
	s[ip++] = x % 10 + '0';
//	putchar(x % 10 + '0');
}
	

