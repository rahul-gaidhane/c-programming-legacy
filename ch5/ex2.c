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

int getfloat(double *p)
{
	int sign;
	char c, c1;
	double flt, div;
	printf("\ninput number ");
	
	while(isspace(c = getchar()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		*p = ' ';
		return 0;
	}	
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
	{
		if (isdigit(c1 = getchar()))
			c = c1;
		else
		{
			*p = ' ';
			return 0;
		}
	}
	for(*p = 0; isdigit(c); c = getchar())
		*p = *p * 10 + (c - '0');
	
	if (c == '.')
		for (flt = 0.0, div = 10.0; isdigit(c = getchar()); div *= 10.0 )
		flt = flt + (c - '0') / div;
	*p = (*p + flt) * sign;
	if (c == EOF)
		return EOF;
	else 
		return 0;
}	

		
	
