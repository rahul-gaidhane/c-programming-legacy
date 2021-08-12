/* detab */
/* 07.02.2017 4:25 pm to 7:30 pm*/
/* 08.02.2017 2:13 pm to */
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 1000
#define MAXARGU 10
int mygetline(char [], int);// array of line and maxlength is passed, length is 
			    // returned
void checkarray(char s1[] , char s2[], int []);//line in s1;s2 is blank
				       //s2 contains sufficent spaces  
void printline(char []);

void main(int argc, char *argv[])
{
	char s1[MAXLENGTH], s2[MAXLENGTH];
	int len, argulist[MAXARGU], i;

	for(i = 0; *++argv != NULL; i++)
	{
		argulist[i] = atoi(*argv);
		printf("argulist[%d] = %d",i,argulist[i]);
	}
	
	
	if((len = mygetline(s1, MAXLENGTH)) > 0)
	{
		checkarray(s1, s2, argulist);
		printline(s2);	
	}
	
}


/* printline : prints the line */
void printline(char line[])
{
		printf("%s", line);
}

/* checkarray : if tab stop oocurs in line, tab stop width is decide from argument */
void checkarray(char s1[], char s2[], int argulist[])
{	int i, j, count, p_argu;
	i = j = count = p_argu = 0;
	while(s1[i] != '\0') 
	{	if(s1[i] == '\t')//check for tab stop  
		{		//if no. of argu ends default is used
			if (argulist[p_argu] == 0)
			{
				while (count < 10)
				{	s2[j] = ' ';
					j++;
					count++;
				}
				count = 0;
				i++;
			}
			else	//else width of tab_stop as per argu.
			{
				while(count < argulist[p_argu])
				{
					s2[j] = ' ';
					j++;
					count++;
				}
				count = 0;
				i++;
				p_argu++;
			}
		}	
		else //for non-tab_stop normal copy of elements is done
		{   	//from one array to another
			s2[j] = s1[i];
			i++;
			j++;
			count++;
			if (argulist[p_argu] == 0)
			{
				if (count == 10)
					count = 0;
			}
			else
			{
				if(count == argulist[p_argu])
					count = 0;
			}
		}
	}
	s2[j] = s1[i];
} 	
