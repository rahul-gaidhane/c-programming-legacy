/*

 * lsearch.c
 *
 *  Created on: 06-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<string.h>
extern int bsearch();
int bsearch(char **list, char *word, int low, int high)
{
	int mid, value;
	while(low <= high)
	{
		mid = (low+high)/2;
		if((value = strcmp(word, list[mid])) < 0)
			high = mid - 1;
		else if (value > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
