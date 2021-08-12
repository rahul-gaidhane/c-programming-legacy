/* Write a function expand(s1,s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2.Allow
 * for letters of either case and digits, and  be prepared to handle cases
 * a-b-c and a-z0-9 and -a-z.Arrange that a leading or trailing - is taken 
 * literally.
 * 19.10.2016	start 3:15 pm to 7:10 pm 	(problem in condition )
 * 20.10.2016	start 2:30 pm to 2:45 pm
 */

#include<stdio.h>
#define MAXSIZE 1000

void expand(char [], char []);

int main()
{
    	char s1[MAXSIZE];
    	char s2[MAXSIZE];
	char c;
	int i;

	for (i = 0; i < MAXSIZE-1 && (c = getchar()) != EOF; i++)
		s1[i] = c;
	s1[i] = '\0';
	
	for (i = 0; i < MAXSIZE; i++)
		s2[i] = '\0';
	
	expand(s1, s2);
	printf("%s", s2);
}

/* expand: expand shorthand notations like a-z,etc. */
void expand(char s1[], char s2[])
{
	int i, j, a, b, set;

	i = j = 0;

	while (s1[i] != '\0')
	{
		if (s1[i+1] == '-') 
		{
			set = 0;
			a = s1[i];
			b = s1[i+2];
			
			if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') set = 1;

			else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z') set = 1;
	
			else if (a >= '0' && a <= '9' && b >= '0' && b <= '9') set = 1; 
					
			if (set == 1)
			{
				while (a <= b)
				{
					s2[j] = a;
					a++;
					j++;
				}
				i += 3; 	
			}
			else 
			{	 	
				s2[j] = s1[i];
				i++;
				j++;
			}
		}	
		else
		{
			s2[j] = s1[i];
			i++;
			j++;
		}
	}
	s2[j] = '\0';
	return;
}	
			
	 
