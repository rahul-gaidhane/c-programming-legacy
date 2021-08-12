/* to add function of % in given framework of calculator */
/* 	 */

#include<stdio.h>
#include<stdlib.h> /* for atof() */
#include<math.h>
#include<string.h>

#define MAXOP 50  /* max size of operand */
#define NUMBER '0' /* signal that a number was found */
#define MATHSLIB '1'
#define MAXSIZE 100
int getop(char []);
void push(double);
double pop(void);
void mygetline(char []);
/* reverse polish calculator */
int main()
{
	int type, i, j;
	double op2, op1;
	char s[MAXOP];
	char k[MAXSIZE];
	i = 0;
	mygetline(s);
	while(s[i] != '\0')
	{	j = 0;
		if (s[i] != ' ')
		{
			k[j] = s[i];
			j++;
			i++;
		}
		else if (i != 0)
		{	k[j] = '\0';
			type = getop(k);  
			switch (type)
			{
				case NUMBER:
					push(atof(k));
					break;
				case MATHSLIB:
					if (strcmp(k, "sin") == 0)
						push(sin(pop()));
					else if (strcmp(k, "exp") == 0)
						push(exp(pop()));	
					else if (strcmp(k, "pow") == 0)
					{
						op2 = pop();
						op1 = pop();
						if (op1 != 0.0 && op2 > 0)
							push(pow(op1, op2));
						else if (op1 == 0.0)
							printf("error: base cannot be zero");
						else if (op2 <= 0)
							printf("error: index cannot be negative");
					}
					break;	
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop()/op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if(op2 != 0.0)
					push(fmod(pop(), op2));
				else 
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default:
				printf("error: unknown command %s\n",k);
				break;
			}
		i++;
		}
	}
	return 0;
}
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; 	/* next free stack position */
double val [MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
	{	printf("pushed %f\n",f);
		val[sp++] = f;
	}
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
	{
		printf("poped\n");
		return val[--sp];
	}
	else {
		printf("error: stack empty \n");
		return 0.0;
	}
}

#include<ctype.h>

/* getop: get next operator or numeric operand */
int getop(char k[])
{
	int i, c;
	i= 0;
	c = k[i];
	
	if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
		return c;

	if (c == '-')
	{
		if (isdigit(c = k[++i])) 
			;
		else 
		{
			return c;
		}
	}
	if (isalpha(c)) /* collect alphabet part */
	{	
		while(isalpha(c = k[++i]))
			;
		return MATHSLIB;
	}		
	if (isdigit(c)) /* collect integer part */
		while (isdigit(c = k[++i]))
			;
	if (c == '.') 	/* collect fraction part */
		while (isdigit(c = k[++i]))
			;
	return NUMBER;
}

void mygetline(char s[])
{
	int c, i;
	i = 0;
	
	while((c = getchar()) != EOF)
		s[i++] = c;
	s[i] = '\0';
	printf("the given string is %s/",s);
}	
