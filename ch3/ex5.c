/* Write there function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. in particular, itob(n,s,16) 
 * formats n as a hexadecimal integer in s.
 * 21.10.2016 	start 2:45 pm to 5:00 pm
 */

#include<stdio.h>
#include<string.h>
#define MAXSIZE 50
void itob(int integer, char string[], int base);
void reverse(char string[]);

int main()
{
	char s[MAXSIZE];
	int integer, base, i;
	
	integer = 65992;
	base = 14;
	itob(integer, s, base); 
	printf("INTEGER %d = %s base %d\n", integer, s, base);
}

/* itob: converts integer to other base integer */
void itob(int integer, char s[], int base)
{
	int rem; 	/* remainder */
	int i;
	
	for (i = 0; integer > 0; i++)
	{
		rem = integer % base;
		if (rem < 10) s[i] = rem + '0';
		
		else s[i] = (rem - 10) + 'A';	
		
		integer = integer / base;
	}
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse the string */
void reverse(char s[])
{
	int c, i, j;
	
	for (i = 0, j = (strlen(s)-1); i < j; i++, j--) 	   
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
