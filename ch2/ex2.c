/* Write a loop equivalent to the for loop above without using && and || */
/* 06.10.2016	4:02 pm to 5 :14  */

#include<stdio.h>

int main()
{
 	int i, lim;
	char s[50];
	char c;
	
	lim = 50;
	i = 0;
	
	while (i < lim - 1)
	{
		if ((c = getchar()) == '\n')
			break;
		if (c == EOF)
			break; 
		s[i] = c;  
		i++;
	}	
	return 0;
}
