/* To remove trailing blanks and spaces */

#include<stdio.h>
#define MAXLINE 1000
int inputline(char line[]);	/* to read lines */
int checkline(char line[],char cline[],int length_of_file);	/* to check lines for trailing blanks and tabs */

int main()
{
	char line[MAXLINE];		/* input lines */
	char cline[MAXLINE];		/* checked lines */
	int len;			/*original length of file */
	int clen;		  	/* length of file after checking */
	int i;				/*counter*/	
	for (i = 0; i < MAXLINE; i++)
	{ 	
		line[i] = '\0';
		cline[i] = '\0';
	}
	len = inputline(line);
	clen = checkline(line,cline,len);
	printf("\n%s",cline);
	
	return 0;
}

/* inputline: to read lines */
int inputline(char line[])
{
	int c, count;
	
	for (count = 0; (c = getchar()) != EOF; count++)
		line[count] = c;
	return count;
}

/* checkline : to check lines and remove trailing blanks and tabs */
int checkline(char line[],char cline[], int length_of_file)
{
	int count, count1;
	int whitespace;		/*counts no. of consecutive white spaces*/

	whitespace = count1 = 0;

	for (count = 0; count < length_of_file;count++)
	{
		if (line[count] != '\t' && line[count] != ' ')  
		{
			cline[count1] = line[count];	/*after checking lines are copied*/
			whitespace = 0;
			count1++;
		}
		else
		{
			whitespace++;
			if (whitespace == 1)
			{
				cline[count1] = line[count]; 
				count1++;
			}
		}
 	}
	return count1++;
}

