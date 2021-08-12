extern int bsearch();
extern struct key;
#include<stdio.h>
#include<string.h>

int bsearch(char *word, struct key tab[], int max)
{
	int low, mid, high, value;
	
	low = 0;
	high = max - 1; 
	while(low <= high)
	{
		mid = (low+high)/2;
		if ((value = strcmp(word, tab[mid].word)) < 0)
			high = mid -1;
		else if (value > 0)
			low = mid + 1;
		else
			mid;
	}
}
		
