/* To print arbitarily long lines */

#include<stdio.h>
#define MAXLINE 1000 	/* size of input line */

long inputline(char line[], int maxline);
void copy(char to[], char from[], int maxline);

int main()
{
	long len;		/*current input length */
	long max;		/*maximum length seen so far */
	char line[MAXLINE];	/*current input line */
	char longest[MAXLINE]; 	/*longest line saved here */

	max = 0;
	while ((len = inputline(line, MAXLINE)) > 0) {  					if (len > max && len < MAXLINE) 
		{ 
			max = len;
			copy(longest, line, MAXLINE);
		}
		else if (len > MAXLINE)
                {
		        max = len;
			copy(longest, line ,MAXLINE);
	  	}
	}
	printf("\n%s",longest);
	printf("\nlength:%lu",max);
	return 0;
}

/* inputline: read a line into s, return length */
long inputline(char s[], int lim)
{
	int c;
	long i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if(i < (lim-1))	
			s[i] = c;
	}
	if (c == '\n' && i < lim)
	{
		s[i] = c;
		++i;
		s[i] = '\0';
	}
	s[999] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[], int lim)
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0' && i < lim)
		++i;  
}                                           
