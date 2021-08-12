/*
 * main.c
 *
 *  Created on: 27-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
void myprintf(char *, ...);


int main()
{
	myprintf("hello world !%i!%f!%s!\n", 10, 36.77, "hahaha");
	myprintf("hello world !%10.3d!%10.7f!%6.3s!\n", 10, 36.77, "hahaha");
	printf("hello world !%10.3d!%10.7f!%.3s!", 10, 36.77, "hahaha");
}
