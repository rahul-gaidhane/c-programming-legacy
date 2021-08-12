/*
 * hashtable.c
 *
 *  Created on: 08-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASHSIZE 10

struct link
{
	char *name;
	char *text;
	struct link *next;
};
typedef char *STRING;
typedef struct link *hashptr;
hashptr hashtab[HASHSIZE];

extern int hash(STRING);
extern hashptr addlink(STRING, STRING);
extern hashptr lookup(STRING);
extern STRING salloc(STRING);

int hash(STRING name)
{
	int hashvalue;

	for(hashvalue = 0; *name != '\0'; name++)
		hashvalue = hashvalue * 31 + *name;
	return hashvalue%HASHSIZE;
}

hashptr lookup(STRING name)
{
	hashptr p;

	p = hashtab[hash(name)];
	for(;p != NULL; p = p-> next)
	{
		if(strcmp(p->name, name) == 0)
			return p;
	}
	return NULL;
}

STRING salloc(STRING string)
{
	STRING p;

	p = (STRING)malloc(sizeof(strlen(string) + 1));
	strcpy(p,string);

	return p;
}

hashptr addlink(STRING name, STRING text)
{
	//printf("\nin addlink\n");
	int hashvalue = 0;
	hashptr p;
	if ((p = lookup(name)) == NULL)
	{
	//	printf("more inside deep");
		p = (hashptr)malloc(sizeof(struct link));
		p->name = salloc(name);
		//printf("p->name = %s\n",p->name);
		p->text = salloc(text);
		//printf("p->text = %s\n",p->text);
		p->next = hashtab[(hashvalue = hash(name))];
		//printf("p->next = %p\n",p->next);
		hashtab[hashvalue] = p;
		//printf("hastab = %p", hashtab[hashvalue]);
	}
	else
	{
		free((void *)p->text);
		p->text = salloc(text);
	}
	return p;
}
