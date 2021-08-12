/* To fold long lines into two or more shorter lines */

#include<stdio.h>
#define N 20 

int main()
{
    	char array1[1000];		
    	char c;
	int i, last_blank, last_print, array_length, j;
	
	last_blank = last_print = 0;
	
	for (i = 0; i < 999 && ((c = getchar()) != EOF); i++) array1[i] = c;
		
	array1[i] = '\0';
	printf("%s\n",array1);

	for(i = 0; array1[i] != '\0'; i++)
	{
		if(array1[i] == ' ') last_blank = i; /* last blank - records position of last blank before column width */
		
		if(i != 0 && ((i % N) == 0))
		{
			for(j = last_print; j < last_blank; j++)
			{
				printf("%c",array1[j]);
			}
			printf("\n");
			last_print = last_blank + 1;/* last print - records position just after the last printed char */ 
		}
	}	
	
	for(j = last_print; array1[j] != '\0'; j++) printf("%c",array1[j]); 
	
	printf("\n");
	
	return 0;
}	
		 	 			 	
