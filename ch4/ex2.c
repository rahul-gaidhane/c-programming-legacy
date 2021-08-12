/* extend the function atof to handle scientific notation */
/* 21.12.2016 2:07 pm to 4:00 pm4:00 pm4:00 pm4:00 pm*/

#include<stdio.h>
#include<ctype.h>
#define MAXSIZE 50
void main()
{
	int getnumber(char [], int);
	char number[MAXSIZE];
	double value,atof(char []);

	while(getnumber(number, MAXSIZE))
		printf(" the value is %.4e\n",atof(number));
}

/* getnumber: gets the string of number */
int getnumber(char num[], int lim)
{
	int i, c;
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		num[i++]=c;
	if(i > 0 && c == '\n')a
		num[i++]=c;
	num[i]='\0';
	return i;
}   		

/* atof: convert string s to real value */
double atof(char s[])
{
	double val, power;
	int i, sign, exponent, counter, sflag, exponent_value;
	exponent_value = 1;
	
	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if(s[i] == 'e' || s[i] == 'E') {
		i++;
		sflag = (s[i] == '-') ? 1 : 0;
		if (s[i] == '-' || s[i] == '+')
			i++;
		for(exponent=0; isdigit(s[i]); i++)
			exponent= 10 * exponent + (s[i] - '0');
		for(counter = 0; counter < exponent; counter++)
			exponent_value = 10 * exponent_value;  
		if (sflag)
			return (val/power)/exponent_value;
		else 
			return (val/power)*exponent_value;	 
	}
	else
		return sign * val / power;
}
		 
