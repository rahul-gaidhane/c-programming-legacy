/* suppose that there will never be more than one character of pushback
   modify getch and ungetch accordingly */

#include<stdio.h>
#include<string.h>

int getch(void);
void ungetch(int);

int buf = 0;

void main()
{
	ungetch('a');
	ungetch(EOF);
	putchar(getch());
	printf("\n");
	ungetch('y');
	putchar(getch());
	printf("\n");
}
int getch(void)
{
	if (buf > 0)
		return buf;
	else 
		return getchar();
	
}
void ungetch(int c)
{
	if (c != EOF)
		buf = c;
}				

