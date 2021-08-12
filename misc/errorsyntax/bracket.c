/*
 * bracket.c
 *
 *  Created on: 31-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>

void brackets(char c)
{
	static int brace, brackets, parentheses;

	brace = brackets = parentheses = 0;
	switch(c)
	{
	case '{': brace++;
				break;
		case '}': brace--;
					break;
		case '[': brackets++;
					break;
		case ']': brackets--;
					break;
		case '(': parentheses++;
					break;
		case ')': parentheses--;
					break;
		}
}
