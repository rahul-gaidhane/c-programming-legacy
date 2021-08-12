/*
 * myheader.h
 *
 *  Created on: 09-Mar-2017
 *      Author: rahul
 */

#ifndef MYHEADER_H_
#define MYHEADER_H_

struct link
{
	char *name;
	char *text;
	struct link *next;
};

#define HASHSIZE 10
typedef char *STRING;
typedef struct link *hashptr;
hashptr hashtab[HASHSIZE];

int hash(STRING);
hashptr addlink(STRING, STRING);
hashptr lookup(STRING);
STRING salloc(STRING);

char getch(void);
void ungetch(char);


#endif /* MYHEADER_H_ */
