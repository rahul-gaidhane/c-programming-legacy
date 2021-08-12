/* to print histogram of frequency of characters in input */

#include<stdio.h>
#define ASIZE 30
#define NEW 1
#define OLD 0

int main()
{
 	char c;
	char sca[ASIZE];
	int freq[ASIZE];	
	int temp[ASIZE];
	int sc, i, j, fq, let, k, hfq;

	fq = sc = k = hfq = 0;
	let = NEW;
	
	for (i = 0; i < ASIZE; i++)
		freq[i] = 0; 	
	
	while ((c = getchar()) != EOF)
	{
		
		if (c == ' ')
			continue;
		
		for (i = 0; i < sc; i++)
		{
			if (c == sca[i])
			{ 
				freq[i] = freq[i] + 1 ;
				if (let == NEW); 
			        	let = OLD;
			}
		}
		
		if (let == NEW)
		{
			sca[sc] = c;
			freq[sc]++;
			sc++;
		}	
	}
	printf("\nsc=%d\n",sc);
	
	for (i = 0; i < ASIZE; i++)
	printf("%d",freq[i]);

	for (i = 0; i < sc; i++)
	{
		if (hfq < freq[i])
			hfq = freq[i];
	}
	printf("\n");
	for (i = 0; i < sc; i++)
	{
		temp[i] = hfq - freq[i];
	}
	printf("\n");
	for(i = 0; i < hfq; i++)
	{
		for (j = 0, k = 0; j < sc; j++,k++)
		{
			if( i >= temp[k])
				printf("||");
			printf("\t");
		}
		printf("\n");
	}
	for (i = 0; i < sc; i++)
	printf("%c\t",sca[i]);
	printf("\n");

	return 0;
}
