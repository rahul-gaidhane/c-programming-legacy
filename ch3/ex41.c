/* In a two's complement number representation, our version of iota 
 * does not handle the largest negative number, that is, the value 
 * of n equal to -(2^(wordsize-1)).Explain why not. Modify it to 
 * print that value correctly, regardless of the machine on
 * which it runs.
 * 20.10.2016 	start 4:55 pm to
 */

#include<stdio.h>
//#include<string.h>
#define MAXSIZE 50
//void reverse(char []);
//void itoa(int , char []);

int main()
{
	int n, k;
	int a;
	a = -45;	
	k = 2147483648  ;
	n = k % 10; 
	printf("n = %d\n k = %d\n a = %u", n, k, a%10 );
	return 0;
}

