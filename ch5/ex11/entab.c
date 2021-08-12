/* Entab : whenever string of blanks occurs tabstop and spaces should be given to fill the spaces.if first string of spaces occurs then tabstop has width given in argument,then for next occurence tabstop has width given in next argument */ 
#include<stdio.h>
#define MAXLENGTH 1000
#define MAXARGU 10
int mygetline(char [], int);
void checkline(char [], char [], int []);
void printline(char []);

void main(int argc, char *argv[])
{
	char s1[MAXLENGTH], s2[MAXLENGTH];
	int len;
	int argulist[MAXARGU] = {5,10,15,20,0};
	
//	for ((*++argv)[0] != NULL)
//	{
		
	if((len = mygetline(s1,MAXLENGTH)) > 0)
	{
		checkline(s1, s2,argulist);
		printline(s2);	
	}
	
}

/* printline : rpints the line */
void printline(char s2[])
{
	printf("result is\n%s", s2);
}
/* checkarray : replaces strings of blanks by tabstops */
void checkline(char s1[], char s2[], int argulist[])
{
	int i, j, total_spaces, spaces_till_tabstop, count, p_argu;
	i = j = total_spaces = count = p_argu = 0;

	while(s1[i] != '\0')
	{
		if (s1[i] == ' ')
		{
			for (; s1[i] == ' '; i++, ++total_spaces)
				;	
			spaces_till_tabstop = argulist[p_argu] - count;
			while(total_spaces > 0)
			{ 
				if (total_spaces == 1 && spaces_till_tabstop != total_spaces)
				{
					s2[j] = ' ';
					j++;
					total_spaces--;
				}
				else if (spaces_till_tabstop <= total_spaces)
				{
					s2[j] = '\t';
					j++;
					p_argu++;
					total_spaces -= spaces_till_tabstop;
					count = 0;
					while(total_spaces >= argulist[p_argu])
					{
						s2[j] = '\t';
						j++;
					       total_spaces -= argulist[p_argu];
						p_argu++;
					}
				}
				for (;total_spaces > 0; total_spaces--)
				{
					s2[j] = ' ';
					j++;
					count++;
				}
			}
	
		}
		else
		{
			s2[j] = s1[i];
			i++;		
			j++;
			count++;
			if (count == argulist[p_argu])
				count = 0;
		}
	}
			 
}	
