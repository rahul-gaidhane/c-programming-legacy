/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
 * in x. Explain why. Use this observation to write a faster version of 
 * bitcount.
 * start 1:17 pm to 1:30 pm 
 */

#include<stdio.h>

int bitcount(unsigned);

int main()
{
	int one_bits;
	unsigned x;
 	
	x = 5432;
	
	one_bits = bitcount(x);	
	printf("1-bits = %d",one_bits);
}

/* bitcount: counts 1-bits in given number */
int bitcount(unsigned x)
{
	int b;
	
	for (b = 0; x != 0; x &= (x-1))
	{ 
		b++;
		printf("x=%d\n",x);
	}
	return b;
}
