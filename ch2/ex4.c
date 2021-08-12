/* write an alternate version of squeeze(s1, s2) that deletes each 
   character in s1 that matches any character in string s2         */
/* 7.10.2016 	5:00 pm to 5:30 pm */

#include<stdio.h>
#define MAXLINE 1000

void squeeze(char [], char []);
	
int main()
{
	char c;
	int i;
	char s1[MAXLINE];
	char s2[MAXLINE];

	printf("Enter the string : \n");

	for (i = 0;(c = getchar()) != '\0' && c != '\n';)
		s1[i++] = c;
	
	s1[i] = '\0';
	printf("Enter the characters : ");

	for (i = 0; (c = getchar()) != '\n';)
		s2[i++] = c;
	
	s2[i] = '\0';
	squeeze(s1, s2);

	for (i = 0; s1[i] != '\0';)
		printf("%c",s1[i++]);
	
	return 0;
}

void squeeze(char array1[], char array2[])
{
	int i, j;

	for(i = 0; array1[i] != '\0'; i++)
	{
		for(j = 0; array2[j] != '\0'; j++)
		{
			if (array1[i] == array2[j])
			{
				array1[i] = ' ';
				continue;
			}	
		}
	}
}
