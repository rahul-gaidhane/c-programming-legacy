/* Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 * start 2:50 pm to 3:10 pm 
 */

#include<stdio.h>

int lower(int);

int main()
{
	printf("%c\n",lower(getchar()));
}

/* lower : converts uppercase letters to lower case */
int lower(int c)
{
	return (c >= 'A' && c <= 'Z')?c-'A'+'a':c;
} 
