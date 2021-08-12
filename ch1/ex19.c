/* to reverse the string */

#include<stdio.h>
#define MAXLINE 1000	/* maximum size of a line */

void inputline(char []);
void reverse(char []);	

int main()
{
	char s[MAXLINE];	/*current line*/
	
	inputline(s);		/*read in line*/
	reverse(s);		/*reverse the line*/
	printf("%s",s);	
	
	return 0;
}

/* inputline: get the input line*/
void inputline(char line[])
{
	char c;
	int i;		/*counter*/
	
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	if (c == '\n')
	{	
		line[i] = '\n';	
 		i++;
	}
	line[i] = '\0';
	return ;
}

/* reverse: to reverse the input line */
void reverse(char s[])
{
	char rev[MAXLINE];	/* reverse of string */
	int len;		/* length of input string */
	int i,j;		/* counters */

	for (len = 0; s[len] != '\0'; len++)
		;
	
	for (i = 0, j = (len - 1); i < len; i++, j--)
		rev[i] = s[j];

	for (i = 0; i < len; i++)
		s[i] = rev[i];
	return ;
}
