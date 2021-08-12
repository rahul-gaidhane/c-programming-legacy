/* Write a routine ungets() to return entire string back 
   into the input */

#include<stdio.h>
#include<string.h>
#define BUFSIZE 100
#define MAXSIZE 100
int getch(void);
void ungetch(int);
void ungets(char []);

int buf[BUFSIZE];	/* buffer */
int bufp = 0;	/* pointer to next space */

int getch(void)
{
		return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int x)
{
	if (bufp == BUFSIZE)
		printf("overloaded");
	else
		buf[bufp++] = x;
}

void ungets(char s[])
{
	int len;
	
	len = strlen(s);
	
	while(len > 0)
	{
		ungetch(s[--len]);		
		s[len] = '\0';
	}
}

void main()
{
	int i;
	char s[MAXSIZE];
	for(i = 0; (s[i] = getch()) != EOF; i++)
		;
	s[i] = '\0';
	printf("string  is %s\n", s);
	ungets(s);
	printf("string is %s\n", s);
}
				

