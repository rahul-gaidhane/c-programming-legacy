/* write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged.
 * 13.10.2016 start 2:30 pm to 3:15 pm
 */	

#include<stdio.h>

int invert(int,int,int);

int main()
{
 	int x, p, n, new_x;

	x = 5432;
	p = 6;
	n = 6;

	new_x = invert(x, p, n);
	printf("x = %d\nnew_x = %d", x, new_x);
}

/* invert: retuns x with the n bits that begn at position p inverted leaving 
	   others unchanged */

int invert(int x, int p, int n)
{
	int a, b, c;
	
	a = b = 0;
	
	//aaaa000000aaaaaa
	a = x & ~(~(~0 << n) << p);
	printf("a = %d\n", a);
        
	//0000bbbbbb000000
	b = ~(x | ~(~(~0 << n) << p));
	printf("b = %d\n", b);
	
 	c = a | b;
	printf("c = %d\n",c);
	
	return c;
}

