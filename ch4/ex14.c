/* Define a macro swap(t,x,y) that interchanges two arguments of type t 
 */

#include<stdio.h>
#define swap(t,x,y) t tmp; tmp = x; x = y; y = tmp

void main()
{	
	int a ,b;
	a = 10;
	b = 66;
	printf("before swapping a = %d b = %d\n", a, b);
	swap(int,a,b);
	printf("after swapping a = %d b = %d\n", a,b); 
}	
