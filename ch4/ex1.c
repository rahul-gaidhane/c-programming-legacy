/* write the function strrindex(s,t), which returns the position of the 
 * rightmost occurence of t in s, or -1 if there is none
 */
/* 20.12.16 2:05 pm to 2:15 pm */

#include<stdio.h>
#define MAXLINE 1000 /* maximum input line length */ 

int mygetline(char s[], int lim );
int strindex(char s[], char t[]);

char pattern[] = "mind";

int main()
{
    char line[MAXLINE];
    int position;	
    
    while (mygetline(line,MAXLINE) > 0)   
	if((position=strindex(line, pattern)) >= 0)/* as position cannot be negative condition
						      used to differentiate between occurence and
						      non occurence */	 
		printf("the rightmost occurence of pattern is at position %d", position);
}

/* getline: get a line into s, return length */       	
int mygetline(char s[], int lim)
{
	int i;
	char c;
	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n') 
	    s[i++] = c;
	if (c == '\n')
 	    s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strrindex:checks for the occurence of pattern, returns its position of rightmost occurence */
int strindex(char s[], char t[])
{
	int i, j, k, pos;
	pos = -1;
	for(i = 0; s[i] != '\0'; i++)
	{   for(j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
		;
	    if (k > 0 && t[k] == '\0')
		pos = j - k + 1;/* pos stores position of recent occurence of pattern */
	}
	return pos;
} 					   
