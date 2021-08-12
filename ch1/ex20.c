/* DETAB */

#include<stdio.h>
#define MAXSIZE 1000
#define n 5

void input(char []);
void checkinput(char []);
void printline(char [],int);

int main()
{
	char array1[MAXSIZE];	
	int i;
	
	for (i = 0; i < 100; i++) array1[i] =/* array2[i] =*/ ' ';
	
	input(array1);
	checkinput(array1);
	
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
void checkinput(char inputarray[])
{ 
	int i, j;
	char line[MAXSIZE];
	
	i = j = 0;

	while (inputarray[i] != '\0')
	{
		if (inputarray[i] == '\n')
		{
			line[j] = inputarray[i];
			printline(line,j);
			j = 0;
		}
		else if (inputarray[i] == '\t')
		{
			if (j < n)
			{
				j = n;
				i++;
			}
			else
			{
				j = j + (n - (j % n));
				i++;
			}
			line[j] = inputarray[i];		
			j++;
		}
		else 
		{
			line[j] = inputarray[i];
			j++;
		}
		i++;
		
	}
	return;
}

void printline(char inputline[],int length_of_line)
{
	int i;
	
	for (i = 0; i < length_of_line; i++) printf("%c",inputline[i]);
	return;
}
