/* getfloat */

#include<stdio.h>
#include<ctype.h>
#define MAXSIZE 100
int getfloat(double *);

int main()
{
	int i, num;
	double array[MAXSIZE];
	
	for(i = 0; i < MAXSIZE && (num = getfloat(&array[i])) != EOF; i++)
		printf("\nthe number is %.4f", array[i]) ;
	return 0;
}

/*extern char getch(void);
extern void ungetch(char);*/

int getfloat(double *p)
{
	int sign;
	char c, c1;
	double flt, div;
	
	printf("\ninput number ");
	
	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		*p = ' ';
		return 0;
	}	
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
	{
		if (isdigit(c1 = getch()))
			c = c1;
		else
		{
			ungetch(c);
			return 0;
		}
	}
	for(*p = 0; isdigit(c); c = getch())
		*p = *p * 10 + (c - '0');
	
	if (c == '.')
		for (flt = 0.0, div = 10.0; isdigit(c = getch()); div *= 10.0 )
		flt = flt + (c - '0') / div;
	*p = (*p + flt) * sign;
	if (c == EOF)
		return EOF;
	else 
		return 0;
}	

		
	
