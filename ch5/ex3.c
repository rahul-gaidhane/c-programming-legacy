/* strcat(S,T) copies string T to end of string S
 * 2017.18.01 2:32 pm to 3:10 pm
 */

#include<stdio.h>
void u_strcat(char *, char *);
int main()
{
	char s[] = "s ends here.";
	char t[] = "t ends here"; 
	printf("the string s is : %s\n", s);
	printf("the string t is : %s\n", t);
	u_strcat(s, t);
	printf("the string s is : %s\n", s); 
	return 0;
}

/* u_strcat : copies string 1 to the end of string 2 */
void u_strcat(char *string1, char *string2)
{
	for( ; *string1 != '\0'; string1++) 
		;
	for( ; (*string1++ = *string2++) != '\0'; )
		;
}		
	
		
