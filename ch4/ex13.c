/* write a recursive version of the function reverse(s). which reverses the
 * string s in place.
 */

#include<stdio.h>
#include<string.h>
//#define MAXSIZE 50
void reverse(char []);
int j, len;
int i = -1;
void main()
{
	char s[] = "abcdefghijklmnopqrstuvwxyz";	
	len = strlen(s);
	j = len;
 	reverse(s);

	printf("the reverse of string is %s", s);
}

/* reverse: reverses the string */
void reverse(char s[])
{
	char t;
	j--;
	i++;
	printf("i = %d, j = %d\n",i,j);	
	if (i <= (len/2))
	{		
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		printf("func. call i = %d\n", i);  
		reverse(s);
	}	
}	
		
	
	 
