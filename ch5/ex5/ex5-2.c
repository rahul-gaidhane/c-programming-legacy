/* strncat */

#include<stdio.h>
void u_strncat(char *, char *, unsigned int);
int main()
{
	char s[] = "function strcat works well.";
	char t[] = "ABCDEF";
	unsigned int n = 3;
	printf("s : %s\nt : %s\n", s, t);
	u_strncat(s, t, n);
	printf("s : %s\n", s);
	return 0;
}

/* u_strcat : concatenate at most n characters of string t to string s */
void u_strncat(char *s, char *t, unsigned int n)
{
	int i = 1;
	while(*s != '\0')
		s++;
	while(i<=n)
	{
		*s=*t;
		s++;
		t++;
		i++;
	}
	*s = '\0';
}
	
