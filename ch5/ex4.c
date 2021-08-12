/* STREND(S, T) */

#include<stdio.h>
#include<string.h>
int strend(char *, char *);
int main()
{
	char s[] = "MOONLIGHT is silver";
	char t[] = "selver";
	printf("string s : %s\n", s); 
	printf("string t : %s", t);
	if(strend(s,t))
		printf("\nstring t occurs at the end of string s");
	else
		printf("\nstring t does not occurs at the end of string s");
	return 0;
}
	
/* strend(s,t) which returns 1 if string t occurs at the end of string s 
   otherwise zero */
int strend(char *s, char *t)
{	
	int i, len;
	i = len = 0;
	
	for (;*s != '\0'; s++) 
		;
	
	for (;*t != '\0'; t++) 
		len++;
	s--; 
	t--;
	while(*s == *t)
	{
		s--;
		t--;
		i++;
	}
	if(i == len)
		return 1;
	else
		return 0;
}	
	

	
