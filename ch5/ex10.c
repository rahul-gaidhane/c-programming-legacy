/* Write the program expr which evaluates a reverse polish expression from the 
 * command line where each operator or operand is a separate argument.
 * start 3 pm to 
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define NUMBER 1
double pop(void);
void push(int);

int main(int argc, char *argv[])
{
	int i = 0;
	char c, type;
	double op2;
	while(--argc > 0)
	{
		if(isdigit((c = (*++argv)[0]))) 
			type = NUMBER;
		else
			type = c;
		printf("%d", c);
		switch(type)
		{
			case NUMBER : push(atoi(*argv));
				      break;
			case '+' : push(pop() + pop());
				   break;
			case '-' : push(pop() - pop());
				   break;
			case '/' : op2 = pop();
				   if (op2 == 0)
				   {
				    	printf("error : cannot divide by zero");
                                        break;
				   }  
				   else
				   {
					push(pop()/op2);
					break;
				   }
			case '*' : printf("?*");
				   push(pop() * pop());
				   break;

			//default: printf("provide some useful argument");
		}		   
		 	
	}
	
}

#define MAXSIZE 100
double array[MAXSIZE];
int array_ptr = 0;
void push(int x)
{
	printf("pushed is %d\n",x); 
	array[array_ptr++] = x;
}
double pop(void)
{
	printf("pop : %f\n",array[--array_ptr]);
	return array[array_ptr];
}
