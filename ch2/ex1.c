/* To determine ranges of char, short, int and long using header file */
/* Start 04.10.2016 */
/* start 05.10.2016  3:20 to */

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
/*	char c, d;
	unsigned char e, f;
//	signed char x, y;
	int g ,h;
	unsigned int i, j;
	short a, b;
	unsigned short k;
//	long l, m;
//	long long n;
	printf("By printing standard headers:\n");
	printf("char 		: %21d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char 	: %21d	to %d\n", 0, UCHAR_MAX);
	printf("signed char   	: %21d	to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("int	  	: %21d	to %d\n", INT_MIN, INT_MAX);		
	printf("unsigned int	: %21u	to %u\n", 0, UINT_MAX);
	printf("short		: %21d	to %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short 	: %21d	to %d\n", 0, USHRT_MAX);
	printf("long		: %21ld	to %ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long	: %21d to %lu\n", 0, ULONG_MAX);
	printf("\nBy computation:\n");
	
	printf("char		: ");
	for (c = 1; c > 0; c++)
		;
	for (d = -1; d < 0; d--)
		;
	printf("%21d to %d\n", c, d); 
	
	printf("unsigned char	: ");
	for (f = -1; f < 0; f--)
		;
	printf("                    0 to %d\n",f); 

	printf("signed char	: ");
	printf("%21d to %d\n", c, d);

	printf("int		: ");
	for (g = 1; g > 0; g++)
		;
	for (h = -1; h < 0; h--)
		;
	printf("%21d to %d\n", g, h);
	
	printf("unsigned int	: ");
	for (i = -1; i < 0; i--)
		;
	printf("                    0 to %u\n", i);
	
	
	printf("short		: ");
	for (a = -1; a < 0; a--)
		;
	for (b = 1; b > 0; b++)
		;
	printf("%21d to %d\n", b, a);	 
	
	printf("unsigned short	:");
	for (k = -1; k < 0; k--)
		;
	printf("                     0 to %u\n", k);
	
// DO NOT REMOVE COMMENT
	printf("long		: ");
	for (l = 1; l > 0; l++)
		;
	for (m = -1; m < 0; m++)
		;
	printf("%21ld to %ld\n",l, m);

	printf("unsigned long 	:");
	for (n = -1; n < 0; n--)
		;
	printf("                    0 to %lld\n",n);
*/
	printf("Floating point constants : ");
	printf("\n
	return 0;
}
