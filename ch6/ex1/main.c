/* */
#include<stdio.h>
#include<ctype.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
struct key {
char *word;
int count;
}keytab[] = {"auto", 0, "char", 0, "define", 0, "float", 0, "token" , 0, "yank", 0};  
int getword(char *, int);
int bsearch(char *, struct key, int);
void main()
{
	char *string;
	int n, c, i;

	while((c=getword(string, MAXWORD)) != EOF)
		if(isalpha(c))
			if((n = bsearch(string, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for(i = 0; i < NKEYS; i++)
		printf("%s = %d\n", keytab[i].word, keytab[i].count);
}	


