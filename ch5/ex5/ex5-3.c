/* strncmp */
#include<stdio.h>
int u_strncmp(char *, char *);
int main()
{	
	int value;
	char s[] = "AbCDEFGHIJKLMNO";
	char t[] = "AB";
	printf("s : %s\nt : %s\n", s, t);
	value = u_strncmp(s, t);
	if (value < 0)
		printf("s < t : %d\n", value);
	else
		printf("s > t : %d\n",value);
	return 0;
}

/* u_strncmp(s,t):compares string t to string s return 0 if string t=s otherwise
                 non-zero value */
int u_strncmp(char *s, char *t)
{
	while (*s == *t)
	{
		s++;
		t++;
	}	
	if (*s == '\0' && *t == '\0')
		return 0;
	else
		return *s-*t;
}	
	
