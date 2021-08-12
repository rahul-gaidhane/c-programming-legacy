/* 
 * Write the function any(s1,s2), which returns the first location in the 
 * string s1 where any character from the string s2 occurs, or -1 if s1 contains
 * no characters from s2.
 * 10.10.2016	2:15 pm to 2:50 pm 
 */

#include<stdio.h>
#define MAXSIZE 1000

int any(char [], char []);

int main()
{
	char s1[MAXSIZE];
	char s2[MAXSIZE];
	int i, k;
	char c;

	printf("Enter the string : ");
	
	for (i = 0; i < MAXSIZE && (c = getchar()) != '\0' && c != '\n'; i++) s1[i] = c;
	s1[i] = '\0';
	printf("Enter exception characters : ");
	
	for (i = 0; i < MAXSIZE && (c = getchar()) != '\0' && c != '\n'; i++) s2[i] = c;
	s2[i] = '\0';	
	k = any(s1, s2);
 
	if (k == -1) printf("No character in s1 from s2");
	
 	else printf("the character is at location %d",k);	 	 
}

/* any : check whether s1 contains any character from s2, if yes return the first location 
	of occurence or return -1 */
int any(char S1[], char S2[])
{
	int i, j;

	for (i = 0; S1[i] != '\0'; i++)
	{
		for (j = 0; S2[j] != '\0'; j++)
		{
			if (S1[i] == S2[j]) return i+1;
		}
	}
	return -1;
}
	
			
			
	
