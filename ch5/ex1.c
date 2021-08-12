/* as written, getint treats a + or - not followed by a digit as a valid 
 * representation of zero. Fix it to push such a character back on the input
 * 7.1.2017 
 */

#include<ctype.h>
#include<stdio.h>
#define MAXSIZE 100
int getint(int *);
void main()
{
	int i;
	int array[MAXSIZE];
	
	for (i = 0; i < MAXSIZE && getint(&array[i]) != EOF; i++)
		printf("input number : %d\n",array[i]);
}


int getch(void);
void ungetch(int);

/* getint : get next integer from input into *p */
int getint(int *pn)
{
	int c, sign, temp;
	
	printf("enter number : ");
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != '+' && c != '-' && c != EOF) 
	{
		printf("\nungetch %c\n",c);
		ungetch(c);
		return EOF;
	}
	sign = (c == '-') ? -1 : 1 ;
	if (c == '-' || c == '+')
	{
		if(!isdigit(temp = getch()))
		{
			ungetch(temp);
			ungetch(c);
			return EOF;
		}
		else
		{	
			c = temp;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if ( c != EOF)
		ungetch(c);
	return c;
}
		
char buf[MAXSIZE];
int bufp = 0;	

void ungetch(int d)
{
	if(bufp >= MAXSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = d;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp]: getchar();
}

