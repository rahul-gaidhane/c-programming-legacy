/* DETAB */

#include<stdio.h>
#define MAXSIZE 1000
#define n 8

void input(char []);
void checkinput(char [], char []);
void print(char[], int );

int main()
{
	char array1[MAXSIZE];	/* CONTAINS INPUT */
	char array2[MAXSIZE];	/* CONTAINS LINE TO PRINT */
	int i;
	
	input(array1);
	checkinput(array1,array2);
	
	for (i = 0; array2[i] != '\0'; i++) printf("%c",array2[i]);
  	
	return 0;
}

/* input: gets input */
void input(char inputarray[])
{
	char c;
	int i;
	
	for (i = 0; (c = getchar()) != EOF; i++) inputarray[i] = c;
	
	inputarray[i] = '\0';
	return;
}

/* check: check input */
void checkinput(char inputarray[],char checkarray[])
{ 
	int i, j, k, l;
	
	i = j = k = 0;

	while (inputarray[i] != '\0')
	{
		if (inputarray[i] == '\t')
		{
			if (j < n) k = n;
		
			else k = n - (j % n);
	
			for (l = 1;l <= k; l++, j++) checkarray[j] = ' '; 
		}
		else if (inputarray[i] == '\n')
		{
			print(checkarray,j);
			j = 0;
		}
		else 
		{
			checkarray[j] = inputarray[i];
			j++;
		}
		i++;
	}
	inputarray[i] = '\0';
	return;
}

/* print: print line */
void print(char checkarray[],int linesize)
{
	int i;
	
	for (i = 0; i < linesize; i++) printf("%c",checkarray[i]);
	
	printf("\n");
	
	return;
}	
