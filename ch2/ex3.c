/* Write the function htoi(s), which converts a string of hexadecimal digits
   (including an optional 0x or 0X) into its equivalent integer value.
   The allowable digits are 0 through 9, a through f, and A through F */
/* 10.10.2016	4:00 pm to 5:00 pm	*/

#include<stdio.h>
#define MAXSIZE 100

int htoi(char []);

int main()
{
	char c, s[MAXSIZE];
	int i,decimal;

	for (i = 0; i < MAXSIZE && (c = getchar()) != EOF && c != '\n'; i++) s[i] = c;

	s[i] = '\0';
	
	decimal = htoi(s);
	
	printf("%s is equivalent to %d",s, decimal);
}

/* htoi : convert string of hexadecimal integers into decimal integer */ 
int htoi(char hex[])
{
 	int i, n;

	n = 0;

	for (i = 0; hex[i] != '\0'; i++)
	{ 
		n *= 16; 
		
		if (hex[i] == '0' && (hex[i + 1] == 'x'|| hex[i + 1] == 'X'))
		{
			i = i + 1;	
			continue;
		}
		if (hex[i] >= '0' && hex[i] <= '9')
			n += (hex[i] - '0');
		
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			n += ((hex[i] - 'a') + 10);
		
		else if (hex[i] >= 'A' && hex[i] <='F')
			n += ((hex[i] - 'A') + 10);
	}

	return n;
}

		
			
  
	
	 
