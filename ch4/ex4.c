/* to add function of % in given framework of calculator */
/* 	 */

#include<stdio.h>
#include<stdlib.h> /* for atof() */

#define MAXOP 50  /* max size of operand */
#define NUMBER '0' /* signal that a number was found */
#define CLEAR 1
#define SWAP 2
#define TOP 3
int getop(char []);
void push(double);
double pop(void);
/* reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
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
				push((int)pop()%(int)op2);
			else 
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		default:
			printf("error: unknown command %s\n",s);
			break;
		}
	}
	return 0;
}
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; 	/* next free stack position */
double val [MAXVAL];	/* value stack */

/* clearstack : clears the operand stack */
void clearstack()
{
	while (sp > 0)
		val[--sp] = '\0';
}

/* top : returns top element of stack of operand */
double stacktop(void) 
{
	return val[--sp];
}

/* elementswap : swaps top two elements of stack of operand */
void elementswap(void)
{
	double op1, op2;
	op1 = pop();
	op2 = pop();
	push(op1);
	push(op2);
} 	

/* duplicate : duplicates the top two elements of stack */
void duplicate(void)
{
	double op1, op2;
	op1 = pop();
	op2 = pop();
	push(op1);
	push(op1);
}	 
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

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0; 
	if (c == '-')
	{
		if (isdigit(s[++i] = c = getch())) 
			;
		else 
		{
			if (c != EOF)
				ungetch(c);
			return s[0];
		}
	}	
		
	
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') 	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; 	/* next free position in buf */

int getch(void) /* get a character */
{
	printf("getch used\n");
	return (bufp > 0)? buf[--bufp]: getchar();
}

void ungetch(int c) /* push character back on input */
{
	printf("ungetch used *%c*\n",c);	
	if (bufp >= BUFSIZE)
		printf("ungetch: too many charcters \n");
	else
		buf[bufp++] = c;
}
