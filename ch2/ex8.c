/* write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions 
 * 13.10.16 start 3:45 pm to 5:45 pm
 */

#include<stdio.h>

int rightrot(int, int);

int main()
{
	int n, new_x, x;

	x = 77;
	n = 2;

	new_x = rightrot(x, n);
	printf("x = %d\nnew_x = %d", x, new_x);  
	
	return 0;
}

/* rightrot: returns the value of x rotated to right by n bit positions */
int rightrot(int x, int n)
{
	int a, b, c;
	
	a = x >> n;
	printf("a = %d\n", a);

	b = (~(~0 << n) & x) << (8 - n);
	printf("b = %d\n", b);

	c = a | b;
	
	return c;	
}	
