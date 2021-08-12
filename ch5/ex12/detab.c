/* detab */
/* 10.02.2017 2:51 pm to */

#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 1000
int mygetline(char [], int);// array for line and maxlength is passed, length is 			    // returned
void checkarray(char s1[] , char s2[], int colno, int tab_width);//line in s1;s2
								// is blank
				                //s2 contains sufficent spaces  
void printline(char []);

void main(int argc, char *argv[])
{
	char s1[MAXLENGTH], s2[MAXLENGTH];
	int len, colno, tab_width;

	while(*++argv != NULL)
	{
		if ((*argv)[0] == '-')
			colno = -(atoi(*argv));
		if ((*argv)[0] == '+')
			tab_width = (atoi(*argv));
	}
	if((len = mygetline(s1, MAXLENGTH)) > 0)
	{
		checkarray(s1, s2, colno, tab_width);
		printline(s2);	
	}
	
}


/* printline : prints the line */
void printline(char line[])
{
		printf("%s", line);
}

/* checkarray : if tab stop oocurs in line, tab stop width is decide from argument */
void checkarray(char s1[], char s2[], int colno, int tab_width)
{	int i, j, count, tab_stop;
	i = j = count = 0;
	tab_stop = 10;
	while(s1[i] != '\0') 
	{	
		if (i == colno)
			tab_stop = tab_width;
		
		if(s1[i] == '\t')//check for tab stop  
		{		//if no. of argu ends default is used
			while (count < tab_stop)
			{	s2[j] = ' ';
				j++;
				count++;
			}
			count = 0;
			i++;
		}
		else //for non-tab_stop normal copy of elements is done
		{   	//from one array to another
			s2[j] = s1[i];
			i++;
			j++;
			count++;
			if (count == tab_stop)
				count = 0;
		}
	}
	s2[j] = s1[i];
} 	
