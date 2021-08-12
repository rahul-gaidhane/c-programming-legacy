/* to print lines above 80 characters */

#include<stdio.h>

int inputline(char *);	

int main()
{
	int len;		/* length of input*/
	char line[100];		/* current line */
	while ((len = inputline(line)) > 0)
		if (len > 80) printf("%s\n",line);
	return 0;
}

/* inputline: read a line into input,return length of input */
int inputline(char input[])
{
	int i,c;
	
	for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		input[i] = c;
	if (c == '\n')	{
		input[i] = c;
		i++;
	}
	input[i] = '\0';
	return i;
} 
		
