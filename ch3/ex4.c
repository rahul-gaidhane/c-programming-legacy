/* In a two's complement number representation, our version of iota 
 * does not handle the largest negative number, that is, the value 
 * of n equal to -(2^(wordsize-1)).Explain why not. Modify it to 
 * print that value correctly, regardless of the machine on
 * which it runs.
 * 20.10.2016 	start 4:55 pm to 7:45 pm
 * 21.10.2016   start 1:30 pm to 2:30 pm
 */

#include<stdio.h>
#include<string.h>
#define MAXSIZE 50
void reverse(char []);
void itoa(int , char []);

int main()
{
	char s[MAXSIZE];	//character representation of number
	int n, i;		//actual number
	
	n = -2147483648;
	for (i = 0; i < MAXSIZE; i++)
		s[i] = '\0';
	
	itoa(n, s);
	printf("Integer Number = %d String = %s", n, s);
}

/* itoa: converts integer to string */
void itoa(int n, char s[])
{
	int i, sign;
	int k; 		/* remainder */

	sign = n;	/* record sign */
	i = 0;
	do 	/* generate digits in reverse order */			    
	{ 	
		k = n % 10;	/* collect remainder */
		(k < 0)? k = -k :k ; 
     		s[i++] = k + '0'; /* get next digit */

	}
	while ((n /= 10) < 0);  /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);			
}

/* reverse the string */
void reverse(char s[])
{
	int c, i , j;

	for (i = 0, j = strlen(s) -1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}	 
