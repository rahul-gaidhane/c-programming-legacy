/* 
 * write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rigthmost n bits of y, leaving the other bits 
 * unchanged.
 * 12.10.2016 	start 2:55 pm to 6:30 pm
 */

#include<stdio.h>

int setbits(int,int,int,int);

int main()
{
	int x, p, n, y, new_x;
	
	x = 5432;
	y = 9999;
	p = 6;
    	n = 5;
	new_x = setbits(x, p, n, y);
	printf("x = %d\nnew_x = %d\n", x, new_x);
	return 0;
}
 
/* setbits: return x such that n bits that begin at position p set to the 
 *	    rightmost n bits of y, leaving other bits unchanged
 */

int setbits(int x, int p, int n, int y)
{
	int a, b, c, l;
	
	a = b = c = 0;
	
	//xxxxx00000xxxxxx
	a = x & ~(~(~0 << n) << (p));
	printf("a = %d\n", a); 
	
	//00000yyyyy000000
	b = (~(~0 << n) & y) << p;
	printf("b = %d\n", b);
	
	//xxxxxyyyyyxxxxxx
	x = a | b;

	return x;
}
	 















		
