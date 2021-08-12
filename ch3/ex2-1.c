/* Write a funtion escape(s,t) that converts characters like newline and tab into
 * visible escape sequences like \n and \t as it copies the string t to s. Use a 
 * switch. Write a function for the other direction as well, converting escape
 * sequences into the real characters.(REVERSE)
 * 18.10.2016	start 2:25 pm to 3:30 pm 
 */  

#include<stdio.h>
#define MAXSIZE 1000
#define TABWIDTH 5
void anti_escape(char [], char []);

int main()
{
	char s[MAXSIZE];	/* input */
	char t[MAXSIZE];	/* output */
	int i;
	char c;	

	for (i = 0; i < (MAXSIZE-1) && (c = getchar()) != EOF; i++)
		s[i] = c;  
	s[i] = '\0';
	
	for (i = 0; i < MAXSIZE; i++)
		t[i] = '\0';
	
   	anti_escape(s,t);
	printf("%s",t);
}

/* anti_escape: converts escape sequences into the real characters */
void anti_escape(char s[], char t[])
{
	int i, j, k, spaces_till_tabstop;

	i = j = k = 0;
	
	while (s[i] != '\0')
	{
		switch(s[i])
		{
			case '\n': t[j] = '\0';
			   	   printf("%s\n",t);
				   for (k = 0; k < MAXSIZE; k++)
					t[k] = '\0';	
			   	   j = 0;
			   	   i++;
			   	   break;

			case '\t': if (j < TABWIDTH) spaces_till_tabstop = TABWIDTH - j;
			
			   	   else spaces_till_tabstop = TABWIDTH - (j % TABWIDTH);
			
			   	   for (k = 0; k < spaces_till_tabstop; k++, j++)
				   	t[j] = ' ';
			   	   i++;				 
                           	   break; 				
                          			 
			default : t[j] = s[i];
			  	  j++;
			  	  i++;  
		}
	}
	return;
}	
