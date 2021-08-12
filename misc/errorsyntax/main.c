/*
 * main.c
 *
 *  Created on: 31-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>

int main()
{
	char c;
	int brackets, parentheses, brace, sq, dq, flag;

	brackets=parentheses=brace=sq=dq=flag=0;

	while((c = getchar()) != EOF)
	{
		switch(c)
		{
		case '{': brace++;
				printf("{");
					break;
		case '}': brace--;
				printf("}");
					break;
		case '[': brackets++;
				printf("[");
					break;
		case ']': brackets--;
				printf("]");
					break;
		case '(': parentheses++;
				printf("(");
					break;
		case ')': parentheses--;
				printf(")");
					break;
	/*	case '\'':if(sq == 0)
					sq++;

				break;
		case '\"':*/
		default : printf("%c",c);
		}
	}
	printf("brackets = %d\nparentheses = %d\nbrace = %d\n", brackets, parentheses, brace);
	if(brackets != 0)
		printf("ERROR: brackets not used properly");
	if(brace != 0)
		printf("ERROR: brace not used properly");
	if(parentheses != 0)
		printf("ERROR: parentheses not used properly");
	return 0;
}

