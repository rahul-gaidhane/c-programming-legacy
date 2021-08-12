#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])

struct key {
char *word;
int count;
}keytab[] = {"auto", 0,/*"autoo", 0, "auuto", 0,"aato", 0,*/ "char", 0, "define", 0, "float", 0, "token" , 0, "yank", 0};  

char getword(char *, int);
int bsearch(char *, struct key *, int);

void main()
{
	char word[MAXWORD];
	int n;
	
	while(getword(word, MAXWORD) != EOF)
	{
	   printf("word = %s\n",word);
	   if(isalpha(word[0]) ||(word[0] == '_' && isalnum(word[1])))
		{	if((n = bsearch(word, keytab, NKEYS)) >= 0)
			{	
				if (strcmp(word,keytab[n].word) == 0)
					keytab[n].count++;
			}
		}
	}
	for(n = 0; n < NKEYS; n++)
	{  	
	  	printf("%s = %d\n", keytab[n].word, keytab[n].count);
	}	
}

int bsearch(char *word, struct key *tab, int max)
{
	int low, mid, high, value;
	
	low = 0;
	high = max - 1; 
	while(low <= high)
	{
		mid = (low+high)/2;
		if ((value = strcmp(word, tab[mid].word)) < 0)
			high = mid -1;
		else if (value > 0)
			low = mid + 1;
		else
			return mid;
	}
}
//char getch(void);
//void ungetch(char);
char getword(char *word, int max)
{
	char c, *w;
	w = word;
	
	while(isspace(c = getchar()))
		;
	*w++ = c;
	switch(c)
	{
		case '"' : while((c = getchar()) != '"')
				;
			   return c;
		case '/' : c = getchar();
			   if ( c == '*')
			   {
				while((c = getchar()) != '*' && (c = getchar()) != '/')
					;
				return c;
			   }
			   else if( c == '/')
			   {
				while((c == getchar()) != '\n')
					;
				return c;
			   }
			   else
			  	return c;
		case '#' : while((c = getchar()) != '\n')
				;
			   return '#';
		case EOF : return EOF;
		
		default :	if (!isalpha(c)) 
				{
					if (c == '_' && isalnum(c = getchar()))
					{	
						--max;
						*w++ = c;
					}
					else
					{	
						*w = '\0';
						return c;
					}
				}
				for (; --max > 0; w++)
				{	
					if (!isalnum(*w = getchar()))
					{	
					break;
					}
				}
				*w = '\0';
				return word[0];
				
	}
}	

/*#define BUFSIZE 100
char arr[BUFSIZE];
int parr = 0; //next free space

char getch(void)
{
	return (parr > 0)?arr[parr--]:getchar();
}	

void ungetch(char c)
{
	if (parr >= BUFSIZE)
		printf("attempt to overload buffer");
	else
		arr[parr++] = c;
}
*/
