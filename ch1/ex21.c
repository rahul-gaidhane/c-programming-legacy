/* ENTAB */

#include<stdio.h>
#define n 8

void input(char []);
void replace_blank_for_tab(char [], char []);
void printline(char[]);

int main()
{
	char array1[1000];	/* CONTAINS INPUT */
	char array2[1000];	/* CONTAINS LINE TO PRINT */
	int i;
	
	for ( i = 0; i < 1000; i++) array1[i] = array2[i] = '\0'; 
	input(array1);
	replace_blank_for_tab(array1, array2);	
    		
	return 0;
}

/* input: gets input */
void input(char inputarray[])
{
	char c;
	int i;
	
	for (i = 0; i < 999 && (c = getchar()) != EOF ; i++) inputarray[i] = c;
	
	inputarray[i] = '\0';
	return;
}

/* replace_blanks_for_tab: replaces blanks for tabs and spaces  */
void replace_blank_for_tab(char inputarray[],char replacedarray[])
{	
	int i, j, k, NO_OF_BLANKS, SPACES_TILL_TABSTOP;

	i = j = 0;
	while (inputarray[i] != '\0')
	{
		
		NO_OF_BLANKS = SPACES_TILL_TABSTOP = 0;	 
		
		if(inputarray[i] != '\n' && inputarray[i] != ' ')	
		{ 
			replacedarray[j] = inputarray[i];
			i++;
			j++;
		}
		
		else if (inputarray[i] == '\n')
		{
			inputarray[i] = '\0';
			printline(replacedarray);
		}
		
		else
		{
			for (k = i; inputarray[k] == ' '; k++) NO_OF_BLANKS++;
			 		
			if(i < n) SPACES_TILL_TABSTOP = n - i;
			
			else SPACES_TILL_TABSTOP = n - (i % n);
			
			if (NO_OF_BLANKS >= SPACES_TILL_TABSTOP)
			{ 
				replacedarray[j] = '\t';
				j++;	
				i = i + SPACES_TILL_TABSTOP;
			}
			else
			{
				
				for (k = 0; k < NO_OF_BLANKS; k++, j++) replacedarray[j] = ' ';
				
				i = i + NO_OF_BLANKS;
			}
		}
	}
	return;
}				

/* printline: prints line */
void printline(char replacedarray[])
{
	int i;

	i = 0;
	while (replacedarray[i] != '\0')
	{
		printf("%c",replacedarray[i]);
		i++;
	}
		
	return;
}	
