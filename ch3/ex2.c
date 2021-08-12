/* Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copied the string t to
 * s. Use a switch. Write a function for the other direction as well, conver
 * -ting escape sequences into the real characters.
 * 17.10.2016 	start 2:30 pm to 7:10 pm  
 * 18.10.2016   start 3:50 pm to 7:04 pm
 */

#include<stdio.h>
#define MAXSIZE 1000
#define TABWIDTH 5

void escape(char [], char []);

int main()
{
	char s[MAXSIZE];
	char t[MAXSIZE];
	int i;
	char c;
	
	for (i = 0; i < MAXSIZE-1 && (c = getchar()) != EOF; i++)
		s[i] = c;
	s[i] = '\0';

	for (i = 0; i < MAXSIZE; i++)
		t[i] = '\0';
	escape(s, t);
	printf("%s",t);
}

/* escape: converts characters like newline and tab into visible escape sequences */
void escape(char s[], char t[])
{
	int i, j, k, spaces_till_tabstop, no_of_blanks;

	i = j = no_of_blanks = spaces_till_tabstop = 0;

	while(s[i] != '\0')
	{
	      	switch(s[i])
		{
		/*	case '\n' : t[j] = '\0';
				    printf("%s",t);
				    j = 0;
				    i++;
				    break;	*/
			case ' ' : for (k = i; s[k] == ' '; k++)
					no_of_blanks++;
				   
				   if (i < TABWIDTH) spaces_till_tabstop = TABWIDTH - i;
			
				   else spaces_till_tabstop = TABWIDTH - (i % TABWIDTH);
				
				   if (no_of_blanks >= spaces_till_tabstop ) 
				   {
						t[j] = '\t';
						j++;
						no_of_blanks = no_of_blanks - spaces_till_tabstop;
						i = i + spaces_till_tabstop;
				   }
				   while (no_of_blanks >= TABWIDTH)
				   {
  						t[j] = '\t';
						j++;
						no_of_blanks = no_of_blanks - TABWIDTH;
						i = i + TABWIDTH;
				   }
				   while (no_of_blanks > 0)
				   {
					t[j] = ' ';
					j++;
					no_of_blanks--;
					i++;
				   }
				   break;					
			default : t[j] = s[i];
				  j++;
				  i++;	
		 
 		}
	}
	return;
}	
 	
