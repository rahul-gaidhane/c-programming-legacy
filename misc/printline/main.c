/*
 * main.c
 *
 *  Created on: 22-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<ctype.h>
#define MAXLENGTH 100

 int main()
 {
	 char flag, c;
	 int count;
	 printf("Print non-graphic characters in Octal(o) or Hexadecimal(h) ? \n");
	 flag = getchar();

	 for(count = 0; (c = getchar()) != EOF; count++)
	 {
		 	if (c >= 0 && c <= 13)
		 	{	if(flag == 'o')
		 			printf("%#o",c);
		 		else
		 			printf("%#x",c);
		 	}
		 	else if(count > 99 && isspace(c))
		 	{
		 		printf("%c\n",c);
		 		count = 0;
		 	}
		 	else
		 		putchar(c);
	 }


 }

