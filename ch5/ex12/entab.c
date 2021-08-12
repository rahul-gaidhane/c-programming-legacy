/* Entab : whenever string of blanks occurs tabstop and spaces should be given to fill the spaces.if first string of spaces occurs then tabstop has width given in argument,then for next occurence tabstop has width given in next argument */ 
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 1000
int mygetline(char [], int);
void checkline(char [], char [], int , int);
void printline(char []);

void main(int argc, char *argv[])
{
	char s1[MAXLENGTH], s2[MAXLENGTH];
	int len, colno, tab_width;

	while(*++argv != NULL)
	{
		if((*argv)[0] == '-')
			colno = -(atoi(*argv));
		if((*argv)[0] == '+')
			tab_width = atoi(*argv);
	}	
	if((len = mygetline(s1,MAXLENGTH)) > 0)
	{
		checkline(s1, s2, colno, tab_width);
		printline(s2);	
	}
	
}

/* printline : rpints the line */
void printline(char s2[])
{
	printf("result is\n%s", s2);
}
/* checkarray : replaces strings of blanks by tabstops */
void checkline(char s1[], char s2[], int colno, int tab_width)
{
	int i, j, total_spaces, spaces_till_tabstop, count, tab_stop;
	i = j = total_spaces = count = tab_stop = 0;

	while(s1[i] != '\0')
	{
		if (s1[i] == ' ')
		{
			for (; s1[i] == ' '; i++, ++total_spaces)
				;	
			spaces_till_tabstop = tab_stop - count;
			while(total_spaces > 0)
			{ 
				if (total_spaces == 1 && spaces_till_tabstop != total_spaces)
				{
					s2[j] = ' ';
					j++;
					if (j == colno)
						tab_stop = tab_width;
					total_spaces--;
				}
				else if (spaces_till_tabstop <= total_spaces)
				{
					s2[j] = '\t';
					j++;
					if (j == colno)
						tab_stop = tab_width;
					total_spaces -= spaces_till_tabstop;
					count = 0;
					while(total_spaces >= tab_stop)
					{
						s2[j] = '\t';
						j++;
						if(j == colno)
							tab_stop = tab_width;
					       total_spaces -= tab_stop;
					}
				}
				for (;total_spaces > 0; total_spaces--)
				{
					s2[j] = ' ';
					j++;	
					count++;
				}
				if (j >= colno)
					tab_stop = tab_width;
			}
	
		}
		else
		{
			s2[j] = s1[i];
			i++;		
			j++;
			if (j == colno)
				tab_stop = tab_width;
			count++;
			if (count == tab_stop)
				count = 0;
		}
	}
			 
}	
