/* strncpy, strncmp, strncat */

#include<stdio.h>
void u_strncpy(char *, char *, unsigned int);
int main()
{
	char s[] = "function does not works well";
	char t[] = "strncpy used";
	unsigned int n = 10;
	printf("s : %s\nt : %s\n", s, t);
	u_strncpy(s, t, n);
	printf("s : %s", s);
	return 0;
}

/* strncpy(s,t,n) : copies at most n characters of string t to string s. Add 
		    '\0' if t has fewer characters than t */
void u_strncpy(char *s, char *t, unsigned int n)
{
	int i = 1;
	while(*t != '\0' && i <= n)
	{
		*s = *t;
		s++;
		t++;
		i++;
		*s = '\0';
	}
	while(i < n)
	{
		*s = '\0';
		s++;
		i++;
	} 
} 
