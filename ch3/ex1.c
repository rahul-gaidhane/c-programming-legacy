/* Our binary search makes two tests inside the loop, when one would suffice(at
 * the price of more tests outside). write a version with only one test inside 
 * the loop and measure the difference in run-time.
 * 17.10.2016 	start 2:25 pm to 4:15 pm
 */

#include<stdio.h>
#define MAXSIZE 100
int binsearch(int , int [], int);

int main()
{
 	int element, size, position;
 	int array[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 111};
        
	size = 10;
	element = 33;
	
	position = binsearch(element, array, size);
	
	if (position != -1)
	 	printf("Element %d is found at position %d", element, position);
        else printf("Element not present in array");
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid, value;
	
	value = 69;	/* arbitary value */
	low = 0;
	high = n - 1;
	
	while (low <= high) 
	{
		mid = (low + high);	 
		if (x < v[mid]) 
	 	{
			high = mid - 1;
			continue;
		}
		(x > v[mid]) ? (low = mid + 1) : (value = mid);
		return (value == 69) ? -1 : value;
	}
}
