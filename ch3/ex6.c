/* Write a version of itoa that accepts three arguments instead of
 * two. the third argument is a minimum field width;the converted 
 * number must be padded with blanks on left if necessary  to 
 * make it wide enough.
 * 21.10.2016		start 5:27 pm to 6:45 pm
 */

#include<stdio.h>
#include<string.h>
#define MAXSIZE 50

void itoa(int integer, char string[], int field_width);
void reverse(char string[]);

int main()
{
	char s[MAXSIZE], field_width;
	int integer;
	
	integer = 40;
	field_width = 15;

	itoa(integer, s, field_width);
	printf("INTEGER = %d s = %s", integer, s);
	return 0;
}

/* itoa: convert n into characters in n */
void itoa(int integer, char s[], int field_width)
{
	int rem;
	int i;
	
	i = 0;
	do
	{
		rem = integer % 10;
		rem < 0 ? rem = -rem : rem;
		s[i++] = rem + '0';
	}
	while((integer /= 10) > 0);
	
	while(i < field_width) s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverses the string */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
